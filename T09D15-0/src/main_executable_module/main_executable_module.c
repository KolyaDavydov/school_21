#include "../data_libs/data_io.h"   // input and output
#include "../data_libs/data_stat.h"     // sort
#include "../data_module/data_process.h"    // normalization
#include "../yet_another_decision_module/decision.h"    //  make decision
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double *data;
    int n;
    
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("n/a");
    } else {
        data = (double *) malloc(n * sizeof(double));
        
        printf("LOAD DATA...\n");
        input(data, n);

        printf("RAW DATA:\n\t");
        output(data, n);

        printf("\nNORMALIZED DATA:\n\t");
        normalization(data, n);
        output(data, n);
        
        printf("\nSORTED NORMALIZED DATA:\n\t");
        sort(data, n);
        output(data, n);
        
        printf("\nFINAL DECISION:\n\t");
        make_decision(data, n);
        
        free(data);
    }
    return 0;
    
    
}
