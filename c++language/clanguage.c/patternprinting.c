#include<stdio.h>
void namasty();
void bonjor();
//function prototype
int main(){

  //function call
printf("enter f for franch & i for india"); 
char ch;
scanf("%c",&ch);
if (ch == 'i'){
    namasty();
}
else {
    bonjor();
}
return 0;    
}

//function definition

void namasty(){

printf("namasty \n");
}
void bonjor(){
printf("bonjor \n");
}