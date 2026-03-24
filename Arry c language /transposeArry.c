#include<stdio.h>

int main() {
    int n;
    printf("Enter size of square matrix (n x n): ");
    scanf("%d", &n);

    int arr[n][n];

    // input matrix
    printf("Enter matrix elements:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);

    // in-place transpose
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){   // notice j = i+1
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    // print transposed matrix
    printf("\nTranspose of the matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}