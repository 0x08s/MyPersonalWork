#include<stdio.h>
int main(){

int arr[5] = {1,2,3,4,5};
int target;

printf("enter your target number");
scanf("%d",&target);
for(int i = 0;i <= 4;i++){

if(arr[i] == target){

printf("index %d\n",i);

break;

}
else {

printf("%d\n",-1);

}
}

return 0;    
}