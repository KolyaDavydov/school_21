#include <stdio.h>
#include "decision.h"
#include "../data_libs/data_io.h"
#include <stdlib.h>

int main()
{
    double *data;
    int n;
    
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("n/a");
    } else {
        
        data = (double *) malloc(n * sizeof(double));

        input(data, n);
        
        if (make_decision(data, n))
            printf("YES");
        else
            printf("NO");
        
        free(data);
    }
     return 0;
}
