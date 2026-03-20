#include<stdio.h>
int main(){

// 1 2 3
// 4 5 6

int a[2][3] = {{1,2,3},{4,5,6}};

int b[3][2] = {{1,2},{3,4},{5,6}};

// 1 2
// 3 4
// 5 6
int result [2][2];
int rc = 2;
for(int i = 0;i < 2;i++){

for(int j =0;j < 2 ;j++){
result[i][j] = 0;
for(int k = 0;k < rc;k++){

result[i][j] += a[i][k] * b[k][j];

}
}
}

// print the result 

for(int i = 0;i < 2;i++){

for(int j =0;j < 2 ;j++){

printf("%d",result[i][j]);

}
printf("\n");
}


return 0;    
}