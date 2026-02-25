#include <stdio.h>

void sumnumber(int a, int b, int c, int d);
void minusnumber(int a, int b, int c, int d);
void divnumber(int a, int b, int c, int d);
void modulenumber(int a, int b, int c, int d);

int main() {
    char choice;
    
    // Sabse pehle yeh poochhta hai — run hote hi
    printf("Kya saare functions chalane hain? (y / n): ");
    scanf(" %c", &choice);   // space → enter/newline ignore karega
    
    if (choice == 'y' || choice == 'Y') {
        int a, b, c, d;
        
        printf("\n--- Numbers daalo ---\n");
        printf("1st number: ");
        scanf("%d", &a);
        
        printf("2nd number: ");
        scanf("%d", &b);
        
        printf("3rd number: ");
        scanf("%d", &c);
        
        printf("4th number: ");
        scanf("%d", &d);
        
        printf("\n--- Results ---\n");
        
        sumnumber(a, b, c, d);
        minusnumber(a, b, c, d);
        divnumber(a, b, c, d);
        modulenumber(a, b, c, d);
    }
    else if (choice == 'n' || choice == 'N') {
        printf("Theek hai, program khatam.\n");
    }
    else {
        printf("Galat input daala! Sirf y ya n likhna tha.\n");
    }
    
    return 0;
}

// ------------------- Functions -------------------

void sumnumber(int a, int b, int c, int d) {
    printf("Sum     = %d\n", a + b + c + d);
}

void minusnumber(int a, int b, int c, int d) {
    printf("Minus   = %d\n", a - b - c - d);
}

void divnumber(int a, int b, int c, int d) {
    if (b == 0 || c == 0 || d == 0) {
        printf("Division = Error (zero se divide nahi kar sakte)\n");
    } else {
        printf("Division = %d\n", a / b / c / d);
    }
}

void modulenumber(int a, int b, int c, int d) {
    if (b == 0 || c == 0 || d == 0) {
        printf("Modulus  = Error (zero se modulus nahi hota)\n");
    } else {
        printf("Modulus  = %d\n", a % b % c % d);
    }
}