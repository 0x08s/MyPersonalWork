#include<stdio.h>
//eg 821
int main(){

int arr[10] = {1,2,3,4,5,6,7,8,9,10};    
int sum = 0;
int i = 0;

for(i = 0;i <= 9;i++){

if(i%2 == 0){
sum += arr[i];
printf("%d\n",sum);

}
}

printf("%d",sum);

return 0;    
}