#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int sum_numbers(int *a, int n);
int find_numbers(int* a, int n, int* numbers);
int how_much_el(int *a, int n);

int main() {
    int n, data[NMAX], new_data[NMAX], flag = 0;
    if (input(data, &n) != 0) {
        flag = 1;
        printf("n/a");
    } else {
        find_numbers(data, n, new_data);
        printf("%d\n", sum_numbers(data, n));
        output(new_data, how_much_el(data, n));
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

//  определяет и возвращает сумму четных элементов исходного массива
int sum_numbers(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            sum = sum + a[i];
        }
    }
    return sum;
}

//
int find_numbers(int* a, int n, int* numbers) {
    int sum = sum_numbers(a, n);
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            if (sum % a[i] == 0) {
                *numbers = a[i];
                numbers++;
            }
        }
    }
    return 0;
}

//  определяет и возвращает количество элементов которые нацелло деляться
int how_much_el(int *a, int n) {
    int sum = sum_numbers(a, n);
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            if (sum % a[i] == 0) {
                num++;
            }
        }
    }
    return num;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
