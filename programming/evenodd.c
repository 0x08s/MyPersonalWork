#include<stdio.h>
int check_even(int n);


int main(){
int n = 5;

check_even(n);

}
int check_even(int n){
if(n%2==0){
    printf("print the even number ");
}    
else{
    printf("print the odd number ");
}
return 0;
}
