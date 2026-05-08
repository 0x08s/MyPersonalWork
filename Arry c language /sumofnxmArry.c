#include<stdio.h>

int main() {
    int n, m;

    // size input
    printf("Rows (n) enter karo: ");
    scanf("%d", &n);
    printf("Columns (m) enter karo: ");
    scanf("%d", &m);

    int a[n][m], b[n][m];

    // matrix a input
    printf("Matrix A ke elements enter karo:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &a[i][j]);
        }
    }

    // matrix b input
    printf("Matrix B ke elements enter karo:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &b[i][j]);
        }
    }

    // add b into a
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            a[i][j] += b[i][j];   // a[i][j] = a[i][j] + b[i][j]
        }
    }

    // print the sum matrix
    printf("\nSum of matrices:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}