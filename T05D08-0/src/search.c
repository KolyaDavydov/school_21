#include <stdio.h>
#include <math.h>
#define NMAX 30

/*
 Quest 4. Реализовать программу src/search.c в соответствии с комментарием.
 Программа должна принимать через stdin массив целых чисел и находить в нем
 первое вхождение числа, удовлетворяющего следующим требованиям: быть четным,
 быть большим или равным математическому ожиданию, подчиняться правилу трех сигм
 и не равняться 0. Найденное число должно быть выведено в stdout. Если такого
 числа нет, то программа должна выдавать 0. Максимальное количество введенных
 чисел равно 30. В случае некорректного ввода необходимо выводить n/a. */

void input(int *a, int *n, int *err);
double mean(int *a, int n);
double variance(int *a, int n);


int main() {
    int n;
    int data[NMAX];
    int err = 0;
    input(data, &n, &err);
    if (err == 0) {
        for (int i = 0; i < n; i++) {
            if (data[i] % 2 == 0 &&
                data[i] >= mean(data, n) &&
                data[i] <= mean(data, n) + 3 * sqrt(variance(data, n)) &&
                data[i] != 0) {
                printf("%d\n", data[i]);
            }
        }
    } else {
        printf("n/a");
    }
    return 0;
}

void input(int *a, int *n, int *err) {
    if (scanf("%d", n) != 1 || *n > 30 || *n <= 0) {
        *err = 1;
    } else {
        for (int i = 0; i < *n; i++) {
            if (scanf("%d", &a[i]) != 1) {
                *err = 1;
            }
        }
    }
    
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



