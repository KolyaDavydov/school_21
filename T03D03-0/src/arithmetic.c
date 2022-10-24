#include <stdio.h>

int main() {
    int x, y, res;
    if (scanf("%d %d", &x, &y) != 2) {
        printf("n/a");
        return 0;
    }
    res = x + y;
    printf("%d ", res);
    res = x + y;
    printf("%d ", res);
    res = x * y;
    printf("%d ", res);
    if (y == 0) {
        printf("n/a");
    } else {
        res = x / y;
        printf("%d ", res);
    }
    return 0;
}
