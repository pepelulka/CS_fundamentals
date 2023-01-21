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
    return 0.5 * log(x);
}

double taylor_func(double x, double eps, int max_iter, int *iter_count) {
    double res = 0;
    double d_x = (x - 1) / (x + 1);
    double d_x_m = d_x;
    double cur = d_x_m;
    int n = 0;
    do {
        res += cur;
        d_x_m *= d_x * d_x;
        n++;
        cur = (1 / (2 * (double)n + 1) * d_x_m);
    } while ((cur > eps || cur < -eps) && n <= max_iter);
    *iter_count = n;
    return res;
}

void print_table(double a, double b, int n, int k) {
    double step = (b - a) / n;
    double meps = mach_eps();
    double eps = meps * k;

    printf("Machine eps for double: EPS = %.16lf.\n", meps);

    printf("-------------------------------------------------------------------------------------------------\n");
    printf("|       x       |      Taylor series            |       math.h function         |Iteration count|\n");
    printf("|---------------|-------------------------------|-------------------------------|---------------|\n");
    double x = a;
    for (int i = 0; i < n + 1; i++) {
        int iter = 0;
        double t_value = taylor_func(x, eps, 100, &iter);
        printf("|\t%.3f\t|\t%.18f\t|\t%.18f\t|\t%d\t|\n", x, t_value, func(x), iter);
        x += step;
    }
    printf("--------------------------------------------------------------------------------------------------\n");
}

int main() {
    int n, k;
    printf("Enter n, k: ");
    scanf("%d %d", &n, &k);

    print_table(0.2, 0.7, n, k);

    return 0;
}
