#include<stdio.h>
int main(){

int marks[4];
printf("enter your chem:");
scanf("%d",&marks[0]);

printf("enter your phy:");
scanf("%d",&marks[1]);

printf("enter your math:");
scanf("%d",&marks[2]);

printf("enter your bio:");
scanf("%d",&marks[3]);

int result = {marks[0] + marks[1]+marks[2]+marks[3]};
printf("result %d",result);
printf("\n");
printf("%d,%d,%d,%d",marks[0] , marks[1] ,marks[2],marks[3]);

return 0;    
}