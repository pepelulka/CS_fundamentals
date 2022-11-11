#include <stdio.h>

int p10(int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) return p10(n / 2) * p10(n / 2);
    return 10 * p10(n -1);
}

int len(int n) {
    if (n == 0) return 1;
    int res = 0;
    while (n > 0) {
        n = n / 10;
        res++;
    }
    return res;
}

void solve(int n) {
    int fd = n % 10;
    int d = len(n);
    int ld = n / p10(d - 1);
    n = n - fd + ld;
    n = n - ld * p10(d - 1) + fd * p10(d - 1);
    printf("%d\n", n);
}

int main() {
    char cur = ' ';
    while (cur != EOF) {
        int n;
        scanf("%d", &n);
        cur = getchar();
		if (cur == EOF) break;
        solve(n);
    }
    return 0;
}   
