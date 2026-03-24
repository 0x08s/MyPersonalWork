#include<stdio.h>

int main() {
    int n, m;
    
    printf("Rows enter karo: ");
    scanf("%d", &n);
    printf("Columns  enter karo: ");
    scanf("%d", &m);

    int arr[n][m];

    // input elements
    printf("Matrix ke elements enter karo:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    // initialize max
    int max = arr[0][0];
    int max_row = 0, max_col = 0;

    // find max
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] > max){
                max = arr[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }

    printf("Maximum element = %d\n", max);
    printf("Index of maximum element = [%d][%d]\n", max_row, max_col);

    return 0;
}