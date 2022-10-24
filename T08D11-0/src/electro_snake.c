#include <stdio.h>
#include <stdlib.h>
/*
    1 6 7
    2 5 8
    3 4 9
*/
//void sort_vertical(int **matrix, int n, int m, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
//void sort_horizontal(int **matrix, int n, int m, int **result_matrix);


void input(int **matrix, int *n, int *m);
//void output(int **matrix, int n, int m);


/*void*/int main()
{
    int **matrix/*, **result*/;
    int n, m;
    int flag = 0;
    matrix = NULL;
    input(matrix, &n, &m);
    
 //   sort_vertical(matrix, n, m, result);
//    output(result);
    
//    sort_horizontal(matrix, n, m, result);
 //   output(result);
return 0;
}

void input(int **matrix, int *n, int *m/*, int *flag*/) {
 //   char space;
    char enter;
    printf("enter stroki\n");
    if (scanf("%d%d%c", n, m, &enter) == 3 &&
        *n > 0 && *m > 0 && enter == '\n') {
        
        matrix =(int **) malloc(*m * *n * sizeof(int) + *m * sizeof(int*));
        printf("начинаем заполнять цикл n = %d, m = %d\n", *n, *m);
        for (int i = 0; i < *n - 1; i++) {
            printf("внешний цикл");
            for (int j = 0; j < *m - 1; j++) {
                if (scanf("%d", &matrix[i][j]) != 1) {
 //                   *flag = 1;
                }
            }
        }
    } else {
//        *flag = 1;
    }
}


