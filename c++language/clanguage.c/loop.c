#include<stdio.h>
int main(){    
int n ;
printf("enter your nubmer :");
scanf("%d",&n);
int i = 1;
int sum = 0;
do{
      sum = sum + i;
      printf("%d",sum);
      printf("\n");
      i++;
}

while(i<=10);

return 0;    
}