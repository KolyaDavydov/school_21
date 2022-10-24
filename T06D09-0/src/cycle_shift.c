#include <stdio.h>
#include <math.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int creat_shift_arr(int* a, int n, int* numbers, int sh);
int input_shift(int *sh);

int main() {
    int n, sh, data[NMAX], new_data[NMAX], flag = 0;
    if (input(data, &n) != 0 || input_shift(&sh)) {
        flag = 1;
        printf("n/a");
    } else {
        creat_shift_arr(data, n, new_data, sh);
        output(new_data, n);
    }
    return flag;
}

int input(int *a, int *n) {
    char c;
    int flag = 0;
    if (scanf("%d%c", n, &c) != 2 || c != '\n' || *n > NMAX || *n < 1) {
        flag = 1;
    } else {
        for (int i = 0; i < *n; i++) {
            scanf("%d", &a[i]);
        }
        if (c != '\n') {
            flag = 1;
        }
    }
    return flag;
}

// ввод числа для сдвига элементов
int input_shift(int *sh) {
    char c;
    int flag = 0;
    if (scanf("%d%c", sh, &c) != 2 || c != '\n') {
        flag = 1;
    }
    return flag;
}

// копирует со смещением
int creat_shift_arr(int* a, int n, int* numbers, int sh) {
    for (int i = 0; i < n; i++) {
        if (sh > 0) {
            for (int i = 0; i < n; i++) {
                if (sh > i) {
                    numbers[i] = a[n - sh + i];
                } else {
                    numbers[i] = a[i - sh];
                }
            }
        }
        if (sh < 0) {
            for (int i = 0; i < n; i++) {
                if (fabs((double) sh) <= i) {
                    numbers[i + sh] = a[i];
                } else {
                    numbers[n + sh + i] = a[i];
                }
            }
        }
    }
    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
