#include <stdio.h>

#define MAX_N 8

void matrix_input(int a[MAX_N][MAX_N], int n) {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void matrix_output(int a[MAX_N][MAX_N], int n) {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
}

void mtos(int a[MAX_N][MAX_N], int n) {
    for (int i = 0;i < n;i++) {
        int temp = a[i][i];
        a[i][i] = a[i][n - 1 - i];
        a[i][n - 1 - i] = temp;
    }
}

int main() {
    int n; 
    scanf("%d", &n);
    int a[MAX_N][MAX_N];
    matrix_input(a, n);
    mtos(a, n);
    matrix_output(a, n);
    return 0;
}