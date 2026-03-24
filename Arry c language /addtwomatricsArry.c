// add two matrics in Arry 
#include<stdio.h>
int main(){

int a[2][2] = {1,2,3,4};
int b[2][2] = {5,6,7,8};
int result [2][2];
for(int i = 0;i <= 1;i++){

for(int j = 0;j <=1;j++){

result[i][j] = a[i][j]+b[i][j];  

}
}

for(int i = 0;i <= 1;i++){

for(int j = 0;j <=1;j++){


printf("%d\n",result[i][j]);

}
printf("\n");
}

return 0;    
}