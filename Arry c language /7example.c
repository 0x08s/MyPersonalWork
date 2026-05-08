#include<stdio.h>
int main(){

float score[5] = {88.5,76.0,92.5,65.0,80.0};

float result;

int i = 0;
 for(i = 0;i<=4;i++){

  result += score[i]/5;  

 }

 //find the average

printf("%f\n",result);






return 0;    
}