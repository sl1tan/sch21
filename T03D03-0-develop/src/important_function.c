#include <math.h>
#include <stdio.h>

double calc(double x);

double QuickPower(double x, long long int n);

double myPow(double x, long long int n);

double calc(double x) {
    return 7e-3 * myPow(x, 4) + ((22.8 * myPow(x, 1 / 3) - 1e3) * x + 3) / (x * x / 2) -
           x * myPow(10 + x, 2 / x) - 1.01;
}

double QuickPower(double x, long long int n) {
    if (n == 0) {
        return 1;
    }

    if (n == 1) {
        return x;
    }

    if (n >= 2) {
        long long int res = n % 2;
        double half = QuickPower(x, n / 2);
        return res ? half * half * x : half * half;
    } else
        return 0;
}

double myPow(double x, long long int n) { return n >= 0 ? QuickPower(x, n) : (1 / QuickPower(x, -n)); }

int main() {
    double x, res;
    char c;
    if (scanf("%lf", &x) == 1 && (isnormal(calc(x)) != 0)) {
        scanf("%c", &c);
        if (c == '\n' || c == '\0' || c == ' ') {
            res = calc(x);
            printf("%.1lf", res);
        } else
            printf("n/a");
    } else
        printf("n/a");
    return 0;
}
