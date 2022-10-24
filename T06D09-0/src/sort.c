#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void sort(int *a, int n);
void output(int *a, int n);

int main() {
    int n = 10;
    int data[NMAX];
    int *pn = &n;
    input(data, pn);
    sort(data, n);
    output(data, n);
    return 0;
}

int input(int *a, int *n) {
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            printf("n/a\n");
            return 0;
        }
    }
    return 0;
}

void sort(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int k = i;
        while (k > 0 && a[k - 1] > a[k]) {
            int tmp = a[k - 1];
            a[k - 1] = a[k];
            a[k] = tmp;
            k--;
        }
    }
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
    printf("\n");
}
