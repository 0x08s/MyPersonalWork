#include<stdio.h>
int main(){
int n;
printf("enter your number :");
scanf("%d",&n);
for(int i = 1;i<=10;i++){
if(n%2==0)    
    printf("print the even %d",n);
}   
if(n%2!=0){
    printf("print the odd %d",n);
}
return 0;
}