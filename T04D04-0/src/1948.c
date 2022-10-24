#include <stdio.h>
#include <math.h>

int main() {
    int num;
    if (scanf("%d", &num) != 1) {
        printf("n/a\n");
        return 0;
    }
    int i = fabs(num + 0.0);
    int j = 0;
    int k;
    while (i > 0) {
        if (num % i == 0) {
            k = i;
            while (k > 0) {
                if (i % k == 0) {
                    j++;
                }
                k--;
            }
            if (j == 2) {
                printf("%d\n", i);
                break;
            }
            j = 0;
        }
        i--;
    }
    return 0;
}
