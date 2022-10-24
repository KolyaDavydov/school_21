#include <stdio.h>

int fibonacci(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    float n;
    scanf("%f", &n);
    if (n - (int) n != 0.0f) {
        printf("n/a\n");
        return 0;
    }
    if (n <= 0) {
        printf("n/a\n");
        return 0;
    }
    int fib = 1;
    for (int i = 1; i <= n; i++)
        fib = fibonacci(i);
    printf("%d\n", fib);
    return 0;
}
