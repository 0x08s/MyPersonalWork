#include<stdio.h>
int main(){

int arr[5] = {1,2,3,4,5};
int i = 0;
int x;
for(i = 0; i <= 4;i++){

x = arr[i] * 2;

printf("%d\n",x);

}

printf("total answer %d\n",x);

return 0;    
}