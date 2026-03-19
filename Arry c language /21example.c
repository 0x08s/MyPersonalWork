#include<stdio.h>
//832 
int fun(int arr[],int size){

int sum = 0;

for(int i = 0; i <= 4;i++){

sum += arr[i];

}

return sum;

}
int main(){
int arr[5] = {1,2,3,4,5};
int size = 5;

int add = fun(arr,size);

printf("%d",add);
return 0;    
}