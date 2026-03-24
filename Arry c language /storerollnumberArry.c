// " store the roll number and student marks "
#include<stdio.h>
int main(){

int arr[4][2] = {{1,23},{0,24},{1,56},{0,90}};
for(int i = 0; i<=3;i++){

for(int j = 0;j <= 1;j++){

printf("%d ",arr[i][j]);

}
printf("\n");
}

return 0;    
}

