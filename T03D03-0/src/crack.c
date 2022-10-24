#include <stdio.h>
#include <math.h>
 
int main() {
    float x, y;

    if(scanf("%f%f", &x, &y) != 2) {
        printf("n/a\n");
        return 0;
    }

    if((x * x) + (y * y) < 25) {
        printf("GOTCHA");
    } else {
        printf("MISS");
    }
    return 0;
}
