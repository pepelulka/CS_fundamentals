#include <stdio.h>

#define MAX_N 8

int len(int a) {
    if (a == 0) return 1;
    int res = 0;
    while (a > 0) {
        res++;
        a /= 10;
    }
    return res;
}

void print_with_tab(int a, int n) {
    printf("%d", a);
    for (int i = 0;i < (n - len(a));i++) {
        printf(" ");
    }
}

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
            print_with_tab(a[i][j], 3);
        }
        printf("\n");
    }
}

int main() {
    solve();
    return 0;
}