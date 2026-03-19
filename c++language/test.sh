#!/usr/bin/env bash
#
# laptop_audit.sh
# Colorful audit for buying a cybersecurity laptop.
# Produces both a pretty terminal report and a detailed timestamped log.
#
# Usage:
#   chmod +x laptop_audit.sh
#   ./laptop_audit.sh            # quick report
#   ./laptop_audit.sh --sample 20  # sample power/battery for 20 seconds
#
# Notes:
# - Script only reads system info (no writes). Some commands require sudo (dmidecode, rdmsr/turbostat).
# - If a tool is not installed, the script will skip that section gracefully.
#

# --- Settings ---
SAMPLE_SECONDS=0
if [[ "${1-}" == "--sample" && -n "${2-}" ]]; then
  SAMPLE_SECONDS="$2"
fi

TIMESTAMP=$(date -u +"%Y%m%dT%H%M%SZ")
LOGDIR="${HOME}/laptop_audit_logs"
mkdir -p "$LOGDIR"
LOGFILE="${LOGDIR}/laptop_audit_${TIMESTAMP}.log"

# --- Colors ---
NC="\e[0m"
BOLD="\e[1m"
DIM="\e[2m"
RED="\e[31m"
GREEN="\e[32m"
YELLOW="\e[33m"
BLUE="\e[34m"
MAGENTA="\e[35m"
CYAN="\e[36m"
WHITE="\e[97m"
BGGRAY="\e[48;5;236m"

# Print header both to terminal and log
hdr() {
  printf "%b\n" "${BGGRAY}${BOLD}${CYAN}  >> LAPTOP AUDIT REPORT  <<  ${NC}"
  {
    printf "LAPTOP AUDIT REPORT - %s (UTC)\n" "$(date -u +"%Y-%m-%d %H:%M:%SZ")"
    printf "============================================\n\n"
  } >> "$LOGFILE"
}

echolog() {
  # echo to screen with optional color, and to log plain
  local color="$1"; shift
  local text="$*"
  printf "%b\n" "${color}${text}${NC}"
  printf "%b\n" "${text}" >> "$LOGFILE"
}

section() {
  local title="$1"
  echolog "${BOLD}${MAGENTA}" "---- ${title} ----"
  printf "\n---- %s ----\n" "$title" >> "$LOGFILE"
}

safe_cmd() {
  # Run a command, print header if available. Accepts command as string.
  local cmd="$*"
  printf ">>> $cmd\n" >> "$LOGFILE"
  eval "$cmd" >> "$LOGFILE" 2>&1 || echo " (skipped / not available)" >> "$LOGFILE"
}

# Start
hdr

echolog "${BOLD}${GREEN}" "Quick summary (terminal):"
echolog "${YELLOW}" "Timestamp (UTC): $(date -u +'%Y-%m-%d %H:%M:%SZ')"
echolog "${CYAN}" "Log saved to: ${LOGFILE}"
echo "" >> "$LOGFILE"

#
# CPU & Topology
#
section "CPU & Topology"

echolog "${BLUE}" "Basic CPU summary (lscpu):"
if command -v lscpu >/dev/null 2>&1; then
  lscpu | sed 's/^/  /' | tee -a "$LOGFILE"
else
  echolog "${RED}" "  lscpu not found. Install util-linux."
fi

echolog "${BLUE}" "Per-core details (/proc/cpuinfo):"
grep -m1 "model name" /proc/cpuinfo | sed 's/^/  /' | tee -a "$LOGFILE"
echolog "${DIM}" "  ...first logical CPU shown above; full /proc/cpuinfo appended to log."
printf "\n" >> "$LOGFILE"
cat /proc/cpuinfo >> "$LOGFILE"

echolog "${BLUE}" "Cache summary (lscpu --cache if available, fallback to sysfs):"
if lscpu --cache >/dev/null 2>&1; then
  lscpu --cache | sed 's/^/  /' | tee -a "$LOGFILE"
else
  # sysfs fallback - sum caches
  echo "  (lscpu --cache not available; reading /sys/devices/system/cpu/*/cache)" | tee -a "$LOGFILE"
  for idx in /sys/devices/system/cpu/cpu0/cache/index*; do
    name=$(cat "$idx/level" 2>/dev/null || echo "?")
    size=$(cat "$idx/size" 2>/dev/null || echo "?")
    type=$(cat "$idx/type" 2>/dev/null || echo "?")
    echo "  L${name} ${type} ${size}" | tee -a "$LOGFILE"
  done
fi

echolog "${BLUE}" "CPU microcode & vendor:"
if grep -q microcode /proc/cpuinfo 2>/dev/null; then
  grep -m1 microcode /proc/cpuinfo | sed 's/^/  /' | tee -a "$LOGFILE"
fi
grep -m1 "vendor_id" /proc/cpuinfo | sed 's/^/  /' | tee -a "$LOGFILE"

# Optional: CPUID (raw) if installed
if command -v cpuid >/dev/null 2>&1; then
  echolog "${BLUE}" "CPUID feature leafs (concise):"
  cpuid -1 | sed 's/^/  /' | tee -a "$LOGFILE"
else
  echolog "${DIM}" "cpuid not installed (optional). Install 'cpuid' for raw CPUID output."
fi

# MSR/Model-Specific Registers info (read-only) - requires sudo
if command -v turbostat >/dev/null 2>&1 && [[ $(id -u) -eq 0 ]]; then
  echolog "${BLUE}" "turbostat (requires sudo) snapshot:"
  turbostat -i 1 -n 1 | sed 's/^/  /' | tee -a "$LOGFILE"
else
  echolog "${DIM}" "turbostat not run (needs root and the tool)."
fi

#
# Memory, NUMA, Cache totals (helpful)
#
section "Memory & NUMA"
echolog "${BLUE}" "Physical memory (/proc/meminfo summary):"
awk '/MemTotal|MemFree|MemAvailable/ {printf "  %s\n", $0 }' /proc/meminfo | tee -a "$LOGFILE"

if command -v numactl >/dev/null 2>&1; then
  echolog "${BLUE}" "NUMA topology:"
  numactl --hardware | sed 's/^/  /' | tee -a "$LOGFILE"
else
  echolog "${DIM}" "numactl not available (optional)."
fi

#
# Battery & Power
#
section "Battery & Power (important for mobility)"

# find battery path
BAT_DIR=""
for b in /sys/class/power_supply/BAT*; do
  [[ -d "$b" ]] && BAT_DIR="$b" && break
done

if [[ -n "$BAT_DIR" ]]; then
  echolog "${BLUE}" "Kernel battery path: ${BAT_DIR}"
  # read several fields safely
  read_field() {
    local f="$1"
    if [[ -r "${BAT_DIR}/${f}" ]]; then
      cat "${BAT_DIR}/${f}"
    else
      echo ""
    fi
  }

  manufacturer=$(read_field manufacturer)
  model_name=$(read_field model_name)
  serial=$(read_field serial_number)
  cycle_count=$(read_field cycle_count)
  energy_full=$(read_field energy_full)
  energy_full_design=$(read_field energy_full_design)
  charge_full=$(read_field charge_full)
  charge_full_design=$(read_field charge_full_design)
  capacity=$(read_field capacity)
  voltage_now=$(read_field voltage_now)
  status=$(read_field status)
  power_now=$(read_field power_now)
  energy_now=$(read_field energy_now)
  charge_now=$(read_field charge_now)

  echolog "${GREEN}" "Battery manufacturer: ${manufacturer:-N/A}"
  echolog "${GREEN}" "Battery model:        ${model_name:-N/A}"
  echolog "${GREEN}" "Battery serial:       ${serial:-N/A}"
  echolog "${GREEN}" "Cycle count:          ${cycle_count:-N/A}"

  # conversion helpers
  to_mwh_energy() {
    # argument in µWh -> mWh integer
    awk -v v="$1" 'BEGIN{if(v=="") print ""; else printf("%.0f", v/1000)}'
  }
  to_mwh_charge() {
    # charge in µAh and voltage in µV -> mWh
    awk -v c="$1" -v v="$2" 'BEGIN{if(c==""||v=="") print ""; else printf("%.0f", (c * v) / 1e9)}'
  }

  # pick canonical full/design using energy_* first, else charge_*
  full_mwh=""
  design_mwh=""
  if [[ -n "$energy_full" ]]; then
    full_mwh=$(to_mwh_energy "$energy_full")
  elif [[ -n "$charge_full" && -n "$voltage_now" ]]; then
    full_mwh=$(to_mwh_charge "$charge_full" "$voltage_now")
  fi

  if [[ -n "$energy_full_design" ]]; then
    design_mwh=$(to_mwh_energy "$energy_full_design")
  elif [[ -n "$charge_full_design" && -n "$voltage_now" ]]; then
    design_mwh=$(to_mwh_charge "$charge_full_design" "$voltage_now")
  fi

  now_mwh=""
  if [[ -n "$energy_now" ]]; then
    now_mwh=$(to_mwh_energy "$energy_now")
  elif [[ -n "$charge_now" && -n "$voltage_now" ]]; then
    now_mwh=$(to_mwh_charge "$charge_now" "$voltage_now")
  fi

  echolog "${CYAN}" "Reported full charge (mWh): ${full_mwh:-N/A}"
  echolog "${CYAN}" "Design capacity (mWh):     ${design_mwh:-N/A}"
  echolog "${CYAN}" "Current charge (mWh):      ${now_mwh:-N/A}"
  echolog "${CYAN}" "Reported percent (capacity): ${capacity:-N/A}%"
  if [[ -n "$power_now" ]]; then
    awk -v p="$power_now" 'BEGIN{printf("  Current power_now (kernel): %.3f W\n", p/1000000)}' | tee -a "$LOGFILE"
  fi

  # upower summary if available
  if command -v upower >/dev/null 2>&1; then
    echolog "${BLUE}" "upower summary:"
    BAT_DEV=$(upower -e | grep -i battery | head -n1 || true)
    if [[ -n "$BAT_DEV" ]]; then
      upower -i "$BAT_DEV" | sed 's/^/  /' | tee -a "$LOGFILE"
    fi
  fi

  # compute health percent if available
  if [[ -n "$full_mwh" && -n "$design_mwh" ]]; then
    health=$(awk -v f="$full_mwh" -v d="$design_mwh" 'BEGIN{printf("%.1f", (f/d)*100)}')
    echolog "${YELLOW}" "Calculated battery health: ${health}% (full/design)"
    if (( $(echo "$health < 50" | bc -l) )); then
      echolog "${RED}" "WARNING: battery health < 50% — expect significantly reduced unplugged runtime."
    fi
  fi
else
  echolog "${RED}" "No battery found under /sys/class/power_supply/BAT*"
fi

#
# Storage & NVMe info (for secure boot / replacement checks)
#
section "Storage & NVMe"

echolog "${BLUE}" "Block devices (lsblk):"
lsblk -o NAME,SIZE,MODEL,ROTA,RO,TYPE,MOUNTPOINT | sed 's/^/  /' | tee -a "$LOGFILE"

if command -v nvme >/dev/null 2>&1; then
  echolog "${BLUE}" "NVMe devices:"
  nvme list | sed 's/^/  /' | tee -a "$LOGFILE"
  echolog "${BLUE}" "NVMe SMART summaries (if available):"
  for dev in $(nvme list | awk '/^\/dev/ {print $1}'); do
    echolog "${DIM}" "  SMART for $dev"
    nvme smart-log "$dev" | sed 's/^/    /' | tee -a "$LOGFILE"
  done
else
  echolog "${DIM}" "nvme-cli not installed or no NVMe devices."
fi

#
# Firmware / BIOS / Secure Boot / Virtualization
#
section "Firmware, Secure Boot & Virtualization"

if command -v dmidecode >/dev/null 2>&1; then
  echolog "${BLUE}" "BIOS / System info (dmidecode requires sudo):"
  echo "  (If you want the raw dmidecode output, run: sudo dmidecode -t bios -t system)" | tee -a "$LOGFILE"
  safe_cmd "sudo dmidecode -t bios -t system | sed 's/^/  /'"
else
  echolog "${DIM}" "dmidecode not installed (optional)."
fi

echolog "${BLUE}" "Secure Boot status:"
if [[ -d /sys/firmware/efi/efivars ]]; then
  if mokutil --sb-state >/dev/null 2>&1; then
    mokutil --sb-state 2>&1 | sed 's/^/  /' | tee -a "$LOGFILE"
  else
    echo "  efivars present; mokutil not available to read SB state." | tee -a "$LOGFILE"
  fi
else
  echolog "${YELLOW}" "  System not booted in UEFI or efivars not available."
fi

echolog "${BLUE}" "Virtualization support (cpu flags):"
grep -m1 '^flags' /proc/cpuinfo | sed 's/flags\t: //' | tr ' ' '\n' | egrep 'vmx|svm' --color=never | sed 's/^/  /' | tee -a "$LOGFILE"

#
# Useful quick tests for buyers (performance & security checks)
#
section "Quick buyer checks & advice"

echolog "${WHITE}" "What to look for when buying a cybersecurity laptop (quick checklist):"
echolog "${DIM}" "  * CPU: at least 4 cores / 8 threads recommended (8+ threads better for VMs)."
echolog "${DIM}" "  * RAM: 16GB minimum, 32GB preferred for multiple VMs."
echolog "${DIM}" "  * Storage: NVMe SSD recommended; check SMART."
echolog "${DIM}" "  * Battery: health > 80% ideal for mobility; <50% means replace."
echolog "${DIM}" "  * BIOS: ensure up-to-date, Secure Boot and virtualization enabled."
echolog "${DIM}" "  * Ports: Ethernet + multiple USB + HDMI/DP for labs."

# Print quick hardware fingerprint
section "Hardware fingerprint"
echolog "${BLUE}" "CPU model:"
grep -m1 "model name" /proc/cpuinfo | sed 's/^/  /' | tee -a "$LOGFILE"
echolog "${BLUE}" "Total logical CPUs:"
lscpu | awk -F: '/^CPU\(s\):/ {print "  " $2}' | sed 's/^  //g' | sed 's/^/  /' | tee -a "$LOGFILE"
echolog "${BLUE}" "Total memory:"
awk '/MemTotal/ {printf "  %.2f GiB\n", $2/1024/1024 }' /proc/meminfo | tee -a "$LOGFILE"

#
# Optional dynamic sampling of battery drain / power (short)
#
if [[ "$SAMPLE_SECONDS" -gt 0 && -n "$BAT_DIR" ]]; then
  section "Dynamic sample (estimation)"
  echolog "${BLUE}" "Sampling battery percentage and power_now every 4s for ${SAMPLE_SECONDS}s..."
  interval=4
  iterations=$(( SAMPLE_SECONDS / interval ))
  (( iterations < 1 )) && iterations=1 && interval="$SAMPLE_SECONDS"
  start_pct=""
  end_pct=""
  tot_power=0
  power_samples=0
  for ((i=0;i<iterations;i++)); do
    if [[ -r "${BAT_DIR}/capacity" ]]; then
      pct=$(cat "${BAT_DIR}/capacity")
    else
      pct=""
    fi
    if [[ -r "${BAT_DIR}/power_now" ]]; then
      p=$(cat "${BAT_DIR}/power_now")
      w=$(awk -v v="$p" 'BEGIN{printf("%.3f", v/1000000)}')
      tot_power=$(awk -v a="$tot_power" -v b="$w" 'BEGIN{printf("%.6f", a+b)}')
      power_samples=$((power_samples+1))
    fi
    [[ -z "$start_pct" && -n "$pct" ]] && start_pct="$pct"
    end_pct="$pct"
    printf "  sample %2d: %s%% %sW\n" $((i+1)) "${pct:-N/A}" "${w:-N/A}"
    printf "  sample %2d: %s%% %sW\n" $((i+1)) "${pct:-N/A}" "${w:-N/A}" >> "$LOGFILE"
    sleep "$interval"
  done
  if [[ -n "$start_pct" && -n "$end_pct" ]]; then
    drop=$(awk -v s="$start_pct" -v e="$end_pct" 'BEGIN{printf("%.2f", s-e)}')
    echolog "${YELLOW}" "Observed percent change: ${drop}% (start ${start_pct}%, end ${end_pct}%)"
    if (( power_samples > 0 )); then
      avgw=$(awk -v t="$tot_power" -v n="$power_samples" 'BEGIN{printf("%.3f", t/n)}')
      echolog "${YELLOW}" "Average sampled power: ${avgw} W"
      # estimate runtime from full_mwh if available
      if [[ -n "$full_mwh" && -n "$capacity" ]]; then
        cur_mwh=$(awk -v f="$full_mwh" -v c="$capacity" 'BEGIN{printf("%.0f", (f * c) / 100)}')
        avg_mw=$(awk -v w="$avgw" 'BEGIN{printf("%.0f", w*1000)}')
        if [[ "$avg_mw" -gt 0 ]]; then
          hours=$(awk -v e="$cur_mwh" -v p="$avg_mw" 'BEGIN{printf("%.2f", e/p)}')
          echolog "${GREEN}" "Estimate remaining runtime (from kernel values): ~${hours} hours"
        fi
      fi
    fi
  fi
fi

#
# Final notes & save
#
section "Final notes & saved report"
echolog "${CYAN}" "Full raw outputs and extended info saved to: ${LOGFILE}"
echolog "${WHITE}" "If you plan to buy, share the log file with a friend or seller to verify specs."
echolog "${WHITE}" "If you want extra checks (TPM, PCI bus enumeration, sensor logs), run with sudo and ensure tools installed: dmidecode, cpuid, nvme, turbostat, smartctl."

echo "" >> "$LOGFILE"
echo "END OF REPORT" >> "$LOGFILE"
echolog "${BOLD}${GREEN}" "Audit complete — check ${LOGFILE} for the full dump."



# --- Performance & Health Summary (Improved) ---
section "Performance & Health Summary"

# CPU model
cpu_model=$(grep -m1 "model name" /proc/cpuinfo | cut -d: -f2- | sed 's/^ *//')

# Core and thread counts (clean numbers)
cpu_cores=$(lscpu | awk -F: '/^Core\(s\) per socket/ {gsub(/[^0-9]/,"",$2); print $2}')
cpu_threads=$(lscpu | awk -F: '/^CPU\(s\)/ {gsub(/[^0-9]/,"",$2); print $2}')

# CPU min/max frequency (in GHz)
cpu_min=$(lscpu | awk -F: '/CPU min MHz/ {printf("%.2f", $2/1000)}')
cpu_max=$(lscpu | awk -F: '/CPU max MHz/ {printf("%.2f", $2/1000)}')

# Cache sizes
cache_l1d=$(lscpu | awk -F: '/L1d cache/ {gsub(/[^0-9KMi]/,"",$2); print $2}')
cache_l1i=$(lscpu | awk -F: '/L1i cache/ {gsub(/[^0-9KMi]/,"",$2); print $2}')
cache_l2=$(lscpu | awk -F: '/L2 cache/ {gsub(/[^0-9KMi]/,"",$2); print $2}')
cache_l3=$(lscpu | awk -F: '/L3 cache/ {gsub(/[^0-9KMi]/,"",$2); print $2}')
# Convert to MiB where possible and sum
to_mib() { awk 'BEGIN{split(ARGV[1],a," ");size=a[1];unit=a[2];if(unit=="KiB"){printf "%.2f",size/1024}else if(unit=="MiB"){printf "%.2f",size}else{printf "%s",ARGV[1]}}' "$1"; }
l1d_m=$(to_mib "$cache_l1d")
l1i_m=$(to_mib "$cache_l1i")
l2_m=$(to_mib "$cache_l2")
l3_m=$(to_mib "$cache_l3")
cache_total=$(awk -v a="$l1d_m" -v b="$l1i_m" -v c="$l2_m" -v d="$l3_m" 'BEGIN{printf("%.2f",a+b+c+d)}')

# RAM
mem_total=$(awk '/MemTotal/ {printf("%.1f GiB", $2/1024/1024)}' /proc/meminfo)

# Battery health + capacities
if [[ -n "$full_mwh" && -n "$design_mwh" ]]; then
  batt_health=$(awk -v f="$full_mwh" -v d="$design_mwh" 'BEGIN{printf("%.1f", (f/d)*100)}')
else
  batt_health="N/A"
fi
batt_cycles=${cycle_count:-N/A}

# ----- Print to screen and log -----
echolog "${GREEN}" "CPU Model        : ${cpu_model}"
echolog "${GREEN}" "Cores / Threads  : ${cpu_cores:-?} cores / ${cpu_threads:-?} threads"
echolog "${GREEN}" "CPU Speed Range  : ${cpu_min:-?}–${cpu_max:-?} GHz (base–turbo)"
echolog "${GREEN}" "Cache per level  : L1d ${cache_l1d}, L1i ${cache_l1i}, L2 ${cache_l2}, L3 ${cache_l3}"
echolog "${GREEN}" "Total Cache      : ${cache_total} MiB (all levels combined)"
echolog "${GREEN}" "Installed RAM    : ${mem_total}"
echolog "${CYAN}"  "Battery Design   : ${design_mwh:-N/A} mWh"
echolog "${CYAN}"  "Battery Full Now : ${full_mwh:-N/A} mWh"
echolog "${CYAN}"  "Battery Health   : ${batt_health}% of design"
echolog "${CYAN}"  "Battery Cycles   : ${batt_cycles}"
