#include<stdio.h>
int main(){

int arr[6] = {100,20,30,40};
int max = arr[0];
int i = 0;

for(i = 0;i <= 5;i++){

if(arr[i] > max){

max = arr[i];

}

}

printf("%d",max);

return 0;    
}