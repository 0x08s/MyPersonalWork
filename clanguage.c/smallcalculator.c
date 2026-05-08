#include<stdio.h>

int check_add(int a,int b);
int check_sub(int a,int b);
int check_div(int a,int b);
int check_mul(int a,int b);

int main(){

int a = 1;
int b = 2;
int add = a+b;
printf("%d print the add",add);
printf("\n");
int sub = a-b;
printf("%d print the suntract",sub);
printf("\n");
int div = a/b;
printf("%d print the div",div);
printf("\n");
int mul = a%b;
printf("%d print the mul",mul);

//calling the functions
check_add(a,b);
check_sub(a,b);
check_div(a,b);
check_mul(a,b);

return 0;

}

int check_add(int a,int b){
    
    printf("%d sum the number",a + b);
}
int check_sub(int a,int b){
   
    printf("%d sum the number",a - b);
}
int check_div(int a,int b){
    
    printf("%d sum the number",a / b);
}
int check_mul(int a,int b){
   
    printf("%d sum the number",a % b);

    return 0;
}











