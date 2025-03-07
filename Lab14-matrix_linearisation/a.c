#include <stdio.h>

#define MAX_N 7

void matrix_input(int a[MAX_N][MAX_N], int n) {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void matrix_linearize(int a[MAX_N][MAX_N], int n) {
    for (int k = 0;k < (2 * n + 1);k++) {
        if (k % 2 == 0) {
            // starting point
            int i = n - 1;
            int j = n - 1 - (k / 2);
            while (i >= 0 && j >= 0) {
                printf("%d ", a[i][j]);
                i--; j--; // going by diagonal
            }
        } else {
            // starting point
            int i = 0;
            int j = 1 + (k / 2);
            while (i < n && j < n) {
                printf("%d ", a[i][j]);
                i++; j++; // going by diagonal
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int a[MAX_N][MAX_N];
    matrix_input(a, n);
    matrix_linearize(a, n);
    return 0;
}