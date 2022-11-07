#include <stdio.h>
#include <locale.h>

int sign(int a) {
    if (a < 0) return -1;
    if (a > 0) return 1;
    return 0;
}

int abs(int a) {
    if (a < 0) return -a;
    return a;
}

int mod(int a, int b) {
    return a - (a / b) * b;
}

int max(int a, int b) {
    if (a < b) return b;
    return a;
}

int min(int a, int b) {
    return (a + b) - max(a, b);
}

int check(int i, int j) {
    return ((i + j) >= -20) && ((i + j) <= -10);
}

void entered_msg(int i, int j, int l, int k) {
    printf("(i, j) has entered the area, i = %d, j = %d, l = %d, k = %d \n", i, j, l, k);
}

void iter(int* i, int* j, int* l, int ck) {
    int ci = *i, cj = *j, cl = *l;
    *i = sign(ci + 1) * abs(abs(ck - cj) - abs(ci - cl));
    *j = mod(cj, 20) + max(mod(ci, 20), min(cj - ck, cl - ck)) - 10;
    *l = mod(ck * (ci + 1) * (cj + 2) * (cl + 3), 20);
}

int main() {
    setlocale(LC_ALL, "Russian");
    int i = 13, j = 10, l = 14;
    int flag = 0;
    if (check(i, j)) {
        flag = 1;
        entered_msg(i, j, l, 0);
    }
    for (int k = 1;(k <= 50) && (flag == 0);k++) {
        iter(&i, &j, &l, k);
        if (check(i, j)) {
            flag = 1;
            entered_msg(i, j, l, k);
            break;
        }
    }
    if (flag == 0) {
        printf("(i, j) hasn't entered the area, i = %d, j = %d, l = %d \n", i, j, l);
    }
    return 0;
}