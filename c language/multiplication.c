#include<stdio.h>

int main(){
    //1 2
    //3 4
    //5 6

int a[3][2] = {{1,2},{3,4},{5,6}};

// 1 2 3 4
// 5 6 7 8

int b[2][4] = {{1,2,3,4},{5,6,7,8}};
int cr = 2;
int result[3][4];
//multiplying
for(int i = 0;i < 3;i++){

for(int j = 0;j < 4;j++){

// i row of a[][] and j colum of b[][]
// ( a[i][0],a[i][1],a[i][2]..... ) * (b[0][j],b[1][j],b[2][j]..)

result[i][j] = 0;

for(int k = 0;k < cr;k++){

result[i][j] += a[i][k] * b[k][j];

}
}
}
 
// print resultant 

for(int i = 0;i < 3;i++){

for(int j = 0;j < 4;j++){

printf("%d  ",result[i][j]);

}
printf("\n");
}
 


return 0;  

}