#include<stdio.h>
int fun(int arr[5],int size){

int max = arr[0];
for(int i = 0;i <= 4;i++){

if(arr[i]>max){

max = arr[i];

}

}
printf("%d\n",max);
return max;
}

int main(){

int arr[5] = {1,2,3,4,5};
int size = 5;

int total = fun(arr,size);

return 0;    
}