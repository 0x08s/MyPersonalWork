#include<stdio.h>
int main(){

int arr[5] = {1,2,3,4,5};

int max = arr[0];
int smax = arr[0];

int i = 0;

for(i = 0;i<=4;i++){

if(arr[i]>max){

smax = max ;
max = arr[i];

printf("%d\n",max);

}

else if(arr[i]>smax && arr[i] != max){
smax = arr[i];

}

}

printf("second max element %d",smax);

return 0;    
}