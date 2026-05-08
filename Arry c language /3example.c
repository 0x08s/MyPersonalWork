#include<stdio.h>
int main(){

    

int arr[3] = {1,2,3};

int i = 0;

for(i = 0;i<=2;i++){

printf("%d\n",arr[i]);

}

arr[2] = 4;
printf("%d\n",arr[2]);



return 0;    
}