#include<stdio.h>
int main(){

int arr[8];
int i = 0;
int smallest ;
 for(i = 0;i<=7;i++){

printf("enter your number %d\n",i);
scanf("%d",&arr[i]);

 }

smallest = arr[0];
for(i = 0;i<=7;i++){

if(arr[i]<smallest)    

smallest = arr[i];

}

printf("%d",smallest);
return 0;    
}