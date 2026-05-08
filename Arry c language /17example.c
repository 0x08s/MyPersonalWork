#include<stdio.h>
//827
int main (){

int arr[5] = {1,2,3,4,5};
int count = 0;
int i = 0;

for(i = 0; i <= 4;i++){

if(arr[i]%2 == 0){

printf("even number %d\n",arr[i]);
count ++;
}

}
printf("total number %d\n",count);
return 0;    
}