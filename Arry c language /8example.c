#include<stdio.h>
int main(){

int arr[8];
int i = 0;
int largest ;

for(i = 0; i <= 7;i++){

printf("enter your number %d",i);
scanf("%d",&arr[i]);

}

largest = arr[0];
for(i = 0; i<=7;i++){

if(arr[i]>largest){

largest = arr[i];
}

}

printf("print the largest %d",largest);

return 0;    
}