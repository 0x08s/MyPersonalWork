#include<stdio.h>

int main() {
    int n, m;
    printf("Enter number of rows : ");
    scanf("%d", &n);
    printf("Enter number of colum: ");
    scanf("%d", &m);

    int arr[n][m];

    // input matrix
    printf("enter the matrics of element:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &arr[i][j]);

    // print transpose
    printf("\nTranspose of matrix:\n");
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}