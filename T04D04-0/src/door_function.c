#include <stdio.h>
#include <math.h>

double va(double x) {
    return 1 / (1 + x * x);
}

double lb(double x) {
    double y = sqrt(sqrt(1 + 4 * x * x) - x * x - 1);
    return y;
}

double gp(double x) {
    return 1 / (x * x);
}

int main() {
    double num;
    for (int i = 0; i < 42; i++) {
        num = 0 - M_PI;
        num = num + i * (fabs(num) / 20.5);
        printf("%.7lf | ", num);
        if (finite(va(num)) == 0) {
            printf("- |");
        } else {
            printf("%.7lf | ", va(num));
        }
        if (finite(lb(num)) == 0) {
            printf("- |");
        } else {
            printf("%.7lf | ", lb(num));
        }
        if (finite(gp(num)) == 0) {
            printf("- \n");
        } else {
            printf("%.7lf\n", gp(num));
        }
    }
    return 0;
}
