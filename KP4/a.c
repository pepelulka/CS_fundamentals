#include <stdio.h>
#include <math.h>

double mach_eps() {
    double eps = 1;
    while (eps / 2 + 1 > 1.0) {
        eps /= 2;
    }
    return eps;
}

double func_17(double x) {
    return 0.25 * x * x * x + x - 1.2502;
}

double func_17_deriv(double x) {
    return 0.75 * x * x + 1;
}

double func_18(double x) {
    return x + pow(x, 0.5) + pow(x, 1.0 / 3.0) - 2.5;
}

double func_18_deriv(double x) {
    return 1 + 0.5 * pow(x, -0.5) + (1.0 / 3.0) * pow(x, -(2.0 / 3.0));
}

double func_17_iter(double x) {
    return x - (1.0 / 3.0) * func_17(x);
}

double func_18_iter(double x) {
    return x - 0.5 * func_18(x);
}

double newton(double (*f)(double), double (*df)(double), double a, double b, double eps) {
    double prev = a;
    double cur = a + (b - a) / 2;
    while (fabs(cur - prev) > eps) {
        prev = cur;
        cur -= (*f)(cur) / (*df)(cur);
    }
    return cur;
}

double dichotomy(double (*f)(double), double a, double b, double eps) {
    double mid = a;
    while (fabs(b - a) > eps) {
        mid = a + (b - a) / 2;
        if ((*f)(mid) * (*f)(a) < 0) b = mid;
        else a = mid;
    }
    return mid;
}

double iteration(double (*f)(double), double a, double b, double eps) {
    double prev = a;
    double cur = a + (b - a) / 2;
    while (fabs(cur - prev) > eps) {
        prev = cur;
        cur = (*f)(prev);
    }
    return cur;
}

int main() {
    double eps = mach_eps();
    double a = 0, b = 2;

    printf("var 17:\n dichotomy: %.9f\n newton: %.9f\n iterations: %.9f\n", dichotomy(&func_17, a, b, eps), newton(&func_17, &func_17_deriv, a, b, eps), iteration(&func_17_iter, a, b, eps));
    printf("var 18:\n dichotomy: %.9f\n newton: %.9f\n iterations: %.9f\n", dichotomy(&func_18, a, b, eps), newton(&func_18, &func_18_deriv, a, b, eps), iteration(&func_18_iter, a, b, eps));
}
