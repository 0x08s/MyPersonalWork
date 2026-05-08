#include<stdio.h>
int check_sum(int m, int n,int p);
int check_module(int n ,int m,int p);
int check_minus(int n ,int m,int p);
int check_div(int n ,int m,int p);

int main(){

int n;
printf("enter your number :");
scanf("%d",&n);
printf("\n");
int m;
printf("enter your number :");
scanf("%d",&m);
printf("\n");
int p;
printf("enter your number :");
scanf("%d",&p);
printf("\n");
int sum = n+m+p;
printf("%d print the sum",sum);
printf("\n");
int multiply = n*m*p;
printf("%d print the multyply",multiply);
printf("\n");
int module = n%m%p;
printf("%d print the module",module);
printf("\n");
int minus = n-m-p;
printf("%d print the minus",minus);
printf("\n");
int div = n/m/p;
printf("%d print the div",div);
printf("\n");

//calling function

check_sum(m,n,p);
check_module(n ,m,p);
check_minus(n ,m,p);
check_div(n ,m,p);

}
//function definition

//if else function use 

int check_sum(int m, int n,int p){
if(n+m+p>0){
printf("%d print the sum",n + m + p);
}
else{
    printf("less than zero");
}
}
int check_module(int n ,int m,int p){
    if(n%m%p>0){
printf("%d print the sum",n%m%p);
}
else{
    printf("less than zero");
}
}
int check_minus(int n ,int m,int p){
   if(n-m-p>0){
printf("%d print the sum",n-m-p);
}
else{
    printf("less than zero");
}

}
int check_div(int n ,int m,int p){
    if(n/m/p>0){
printf("%d print the sum",n/m/p);
}
else{
    printf("less than zero");
}
return 0;
}






