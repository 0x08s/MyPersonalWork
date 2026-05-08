#include<stdio.h>
//function prototype
void printmessage(int a);

int main(){
int a;
printf("enter your number");
scanf("%d",&a);
//calling the function
printmessage(a);
return 0;
}

//function definition

void printmessage(int a){
if(a%2==0){
    printf("print the even number ");
}    
else{
    printf("print the odd number");
}
}
