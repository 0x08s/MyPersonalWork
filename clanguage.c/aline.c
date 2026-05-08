#include <stdio.h>

int main() {

int arr[5] = {4,4,4,5};

int i = 0;

int max = arr[0];
int smax = arr[0];

for(i = 0;i <= 4;i++){

if (max < arr[i]){
smax = max;
max = arr[i];
}

else if(smax < arr[i] && arr[i] != max){

smax = arr[i];

}

printf("%d\n",smax);

return 0;
}  
}