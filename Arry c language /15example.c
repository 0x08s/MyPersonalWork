#include<stdio.h>

//823

int main(){

int arr[6] = {-1,2,-3,-4,-5,-6};
int count = 0;
int i = 0;

for(i = 0;i <= 5; i++){

if(arr[i]<0){

printf("%d\n",arr[i]);

count++;

}
}

printf("%d\n",count);
return 0;    
}