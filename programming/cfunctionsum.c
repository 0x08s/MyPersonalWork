#include<stdio.h>
int check_sign(int n);

int main(){

int n;
printf("enter your number :");
scanf("%d",&n);
check_sign(n);

}
int check_sign(int n){
if(n==1){
printf("%d print the positive number",n);
}
else{
printf("%d print the negative number",n);
}
return 0;
}

