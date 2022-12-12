#include <stdio.h>

#define MAX_N 8

void solve() {
    int n;
    scanf("%d", &n);
    int a[MAX_N][MAX_N];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (int i = 0;i < n;i++) {
        int temp = a[i][i];
        a[i][i] = a[i][n - 1 - i];
        a[i][n - 1 - i] = temp;
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    solve();
    return 0;
}