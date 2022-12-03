#include <stdio.h>

struct State {
    int i, j, l;
};

struct Band {
    int lower, upper;
};

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

void entered_msg(struct State st, int k) {
    printf("(i, j) has entered the area, i = %d, j = %d, l = %d, k = %d \n", st.i, st.j, st.l, k);
}

void iter(struct State* st, int ck) {
    int ci = st->i, cj = st->j, cl = st->l;
    st->i = abs(ci - cl) + min(mod(cj, 10), mod(cl * ck, 10)) - 20;
    st->j = mod(max(ck - ci, min(cj, max(ci - cl, cj - cl))), 30);
    st->l = mod(cl * cl, 20) - mod(max(ci, cj), ck + 1);
}

void out(struct State st) {
    printf("(%d, %d, %d) \n", st.i, st.j, st.l);
}

void trace(struct State st, struct Band bnd) {
    int flag = 0;
    if (check(st, bnd)) {
        flag = 1;
        entered_msg(st, 0);
    }
    for (int k = 1;(k <= 50) && (flag == 0);k++) {
        iter(&st, k);
        out(st);
        if (check(st, bnd)) {
            flag = 1;
            entered_msg(st, k);
            break;
        }
    }
    if (flag == 0) {
        printf("(i, j) hasn't entered the area, i = %d, j = %d, l = %d \n", st.i, st.j, st.l);
    }
}
                    
int main() {
    struct State st = {-30, -4, 12};
    struct Band bnd = {-20, -10};
    trace(st, bnd);
    return 0;
}