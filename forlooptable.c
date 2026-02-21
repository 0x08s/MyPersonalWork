#include<stdio.h>
int main(){
int n;
printf("enter your number :");
scanf("%d",&n);
int i = 1;
do{
printf("%d",n*i);
printf("\n");
i++;
}
while(i<=10);

return 0;    
}