#include <stdio.h>

int maxv(int x, int y) {
    if (x < y) {
        return y;
    } else if (x > y) {
        return x;
    }
    return 0;
}

int main() {
    int x, y;
    if (scanf("%d %d", &x, &y) != 2) {
        printf("n/a\n");
        return 0;
    }
    int max = maxv(x, y);
    printf("%d\n", max);
    return 0;
}
