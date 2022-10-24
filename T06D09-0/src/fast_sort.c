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
    int left = 0;
    int right = n - 1;
    int middle = a[(left + right) / 2];
        do {
            while (a[left] < middle)
                left++;
            while (a[right] > middle)
                right--;
            if (left <= right) {
                int temp = a[left];
                a[left] = a[right];
                a[right] = temp;
                left++;
                right--;
            }
        } while (left <= right);
    if (right > 0) {
        sort(a, right + 1);
    }
    if (left < n) {
        sort(a + left, n - left);
    }
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
    printf("\n");
}

