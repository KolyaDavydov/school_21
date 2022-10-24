#include <stdio.h>
#define NMAX 10

/*
 Quest 3. Добавить реализации необходимых функций таким образом,
 чтобы программа собиралась и корректно работала
 (принимала через stdin массив целых чисел, выводила бы его,
 вычисляла и выводила на новой строке набор статистических метрик -
 экстремумы (max и min), математическое ожидание и дисперсию,
 считая, что мы имеем дело с дискретным равномерным распределением).
 В случае некорректного ввода необходимо выводить n/a.
 Числа с плавающей запятой выводить с точностью 6 знаков после запятой.
 */

void input(int *a, int *n, int *err);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);     // математическое ожидание
double variance(int *a, int n);     // дисперсия
void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main() {
    int n, data[NMAX], err = 0;
    input(data, &n, &err);
    if (err == 0) {
        output(data, n);
        max(data, n);
        min(data, n);
        mean(data, n);
        variance(data, n);
        output_result(max(data, n),
                      min(data, n),
                      mean(data, n),
                      variance(data, n));
    } else {
        printf ("n/a");
    }
    

    return 0;
}

void input(int *a, int *n, int *err) {
    if (scanf("%d", n) != 1 || *n > 10 || *n <= 0) {
        *err = 1;
    } else {
        for (int i = 0; i < *n; i++) {
            if (scanf("%d", &a[i]) != 1) {
                *err = 1;
            }
        }
    }
    
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int max(int *a, int n) {
    int max = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p > max) {
            max = *p;
        }
    }

    return max;
}

int min(int *a, int n) {
    int min = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }

    return min;
}

double mean(int *a, int n) {
    double m = 0.0f;
    double num = (double) n;    // переводим инт в дабл

    for (int i = 0; i < n; i++) {
        m = m + a[i] * (1 / num);
    }
    return m;
}

double variance(int *a, int n) {
    double var = 0.0f;
    double num = (double) n;    // переводим инт в дабл
    for (int i = 0; i < n; i++) {
        var = var + (1 / num * (a[i] - mean(a, n)) * (a[i] - mean(a, n)));
    }

    return var;
}

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v) {
    printf("%d %d %.6f %.6f \n", max_v, min_v, mean_v, variance_v);
}
