#include<stdio.h>
int fun(int arr[5],int size){

for(int i = 4;i >= 0;i--){

printf("%d\n",arr[i]);    

}

}

int main(){

int arr[5] = {1,2,3,4,5};
int size = 5;

fun(arr,size);



return 0;    
}