#include<stdio.h>
void sumnumber(int a, int b ,int c , int d);


void  minusnumber(int a, int b ,int c , int d);



void  divnumber(int a, int b ,int c , int d);



void modulenumber(int a, int b ,int c , int d);

int main(){

char choice ;
printf("complete run function use y otherwise N");
scanf(" %c",&choice);



if(choice == 'y' || choice == 'Y'){
int a ,b,c,d;
    printf("enter your 1st number: ");
        scanf("%d", &a);
        printf("enter your 2nd number: ");
        scanf("%d", &b);
        printf("enter your 3rd number: ");
        scanf("%d", &c);
        printf("enter your 4th number: ");
         scanf("%d", &d);

   modulenumber(a, b ,c ,d);
   sumnumber(a, b , c , d);
   divnumber(a,  b , c ,d);
   minusnumber( a,b ,c ,d);

}
else if (choice ==  'n'||choice == 'N'){
    printf("nothing");
}
else{
    printf("Ivalid");
}


return 0;    
}

void sumnumber(int a, int b ,int c , int d){
printf("sum = %d \n", a + b +c +d);
}
void  minusnumber(int a, int b ,int c , int d){
printf("minus = %d\n",a - b - c -d);

}
void  divnumber(int a, int b ,int c , int d){
printf("div = %d\n",a / b /c /d);

}
void modulenumber(int a, int b ,int c , int d){
printf("module = %d\n",a % b% c % d);
}
