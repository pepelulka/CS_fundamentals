#include <stdio.h>

#define MAX_N 49

void matrix_input(int a[MAX_N][MAX_N], int n) {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void matrix_linearize(int a[MAX_N][MAX_N], int n) {
    int was[MAX_N][MAX_N];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            was[i][j] = 0;
        }
    }

    for (int k = 1;k <= 2 * n + 1;k++) {
        if (k % 2 == 0) {
            int i = (k - 1) / 2, j = n - 1; // starting point
            while (j >= 0 && i < n) {
                if (!was[i][j]) {
                    was[i][j] = 1;
                    printf("%d ", a[i][j]);
                }
                i++; j--;
            }
        } else {
            int i = 0, j = k / 2; // starting point
            while (j < n && i < n) {
                if (!was[i][j]) {
                    was[i][j] = 1;
                    printf("%d ", a[i][j]);
                }
                i++; j++;
            }
        }
    }

    for (int k = 0;k < n / 2;k++) {
        int i = n / 2 - k, j = n / 2 - k - 1; // starting point
        for (int _ = 0;_ < 2 * k + 1;_++) {
            printf("%d ", a[i][j]);
            i++;
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
