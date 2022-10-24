#include <stdio.h>
#include <stdlib.h>

int* input(int *arr, int *n);
void sort(int *arr, int n);
void output(int *arr, int n);

int main() {
    int *arr = NULL;
    int n;
    arr = input(arr, &n);
    if (NULL != arr) {
        sort(arr, n);
        output(arr, n);
    } else {
        printf("n/a");
    }
    return 0;
}

int* input(int *arr, int *n) {
    int flag = 0;
    char c;
    if (scanf("%d%c", n, &c) != 2 || c != '\n' || *n < 1 || *n > 10)
        flag = 1;
    arr = (int*) malloc(*n * sizeof(int));
    for (int i = 0; i < *n; i++) {
        if (scanf("%d%c", &arr[i], &c) != 2)
            flag = 1;
    }
    if (flag == 1) {
        return NULL;
    }
    free(arr);
    return arr;
}

void sort(int *arr, int n) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - 1 - j; i++) {
            printf("sort %d\n", j);
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
    printf("sort complite\n");
}

void output(int *arr, int n) {
    for (int *p = arr; p - arr < n; p++) {
        printf("%d ", *p);
    }
    printf("\n");
}
