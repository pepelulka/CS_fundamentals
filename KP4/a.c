#include <stdio.h>
#include <math.h>

double mach_eps() {
    double eps = 1;
    while (eps / 2 + 1 > 1.0) {
        eps /= 2;
    }
    return eps;
}

double func(double x) {
    return 0.25 * x * x * x + x - 1.2502;
}

double func_deriv(double x) {
    return 0.75 * x * x + 1;
}

double newton(double (*f)(double), double (*df)(double), double a, double b, double eps) {
    double prev = a;
    double cur = b;
    while (fabs(cur - prev) > eps) {
        prev = cur;
        cur -= (*f)(cur) / (*df)(cur);
    }
    return cur;
}

int main() {
    double eps = mach_eps();
    double a = 0, b = 2;

    printf("Root is %.12f", newton(&func, &func_deriv, a, b, eps));
}