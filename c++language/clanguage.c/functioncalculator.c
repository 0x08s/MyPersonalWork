#include<stdio.h>

int check_calculator(int n,int m, int p);

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
int module1 = n%m;
printf("%d print the modulus1",module1);
printf("\n");
int minus = n-m;
printf("%d print the minus",minus);
printf("\n");
int module2= m%p;
printf("%d print the module2",module2);
printf("\n");
int minus2 = m-p;
printf("%d print the minus2",minus2);
printf("\n");

//calling function 

check_calculator(n,m,p); 

}

//function definition
int check_calculator(int n,int m,int p){
if(n+m+p > 0){
printf("%d print the sum ",n+m+p);    
}
else {
    printf("less than to the zero");
}
printf("\n");
if(n*m*p > 0){
printf("%d print the multiply ",n*m*p);    
}
else {
    printf("less than to the zero");
}
printf("\n");
if(m%p > 0){
printf("%d print the sum ",m%p);    
}
else {
    printf("less than to the zero");
}
printf("\n");
if(n%m> 0){
printf("%d print the sum ",n%m);    
}
else {
    printf("less than to the zero");
}
printf("\n");
if(n-m> 0){
printf("%d print the sum ",n-m);    
}
else {
    printf("less than to the zero");
}
printf("\n");
if(m-p> 0){
printf("%d print the sum ",m-p);    
}
else {
    printf("less than to the zero");
}

return 0;
}