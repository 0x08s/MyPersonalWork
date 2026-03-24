#include<stdio.h>

int main() {
    int n, m;
    printf("Rows (n) enter karo: ");
    scanf("%d", &n);
    printf("Columns (m) enter karo: ");
    scanf("%d", &m);

    int arr[n][m];

    // matrix input
    printf("Matrix ke elements enter karo:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &arr[i][j]);

    int max_sum = 0, row_index = 0;

    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < m; j++){
            sum += arr[i][j];
        }
        if(sum > max_sum){
            max_sum = sum;
            row_index = i;
        }
    }

    printf("Maximum row sum = %d\n", max_sum);
    printf("Row index with maximum sum = %d\n", row_index);

    return 0;
}