#include <stdio.h>
#define NMAX 10

/*
 Quest 2. Внести исправления в программу src/squaring.c таким образом,
 чтобы программа собиралась и корректно работала
 (принимала через stdin массив целых чисел,
 возводила их в квадрат и выводила в stdout).
 В случае некорректного ввода необходимо выводить n/a.
*/


void input(int *a, int *n, int *err);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    int err = 0;
    input(data, &n, &err);
    if (err == 0) {
        squaring(data, n);
        output(data, n);
    } else {
        printf("n/a");
    }
    return 0;
}

void input(int *a, int *n, int *err) {
    if (scanf("%d", n) != 1) {
        *err = 1;
    }
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            *err = 1;
        }
    }
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = a[i] * a[i];
    }
}


