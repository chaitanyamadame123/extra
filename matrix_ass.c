#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define SIZE 1000

int main() {
    int mat1[SIZE][SIZE];
    int mat2[SIZE][SIZE];
    int result[SIZE][SIZE];

    srand(time(NULL));

    int i, j, k;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            mat1[i][j] = rand() % 10;
            mat2[i][j] = rand() % 10;
        }
    }

    // Enable nested parallelism
    omp_set_nested(1);

    double start_time = omp_get_wtime();

    #pragma omp parallel for private(i, j, k) shared(mat1, mat2, result)
    for (i = 0; i < SIZE; i++) {
        #pragma omp parallel for private(j, k)
        for (j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (k = 0; k < SIZE; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    double end_time = omp_get_wtime();
    double execution_time = end_time - start_time;

    printf("Matrix multiplication executed in %f seconds.\n", execution_time);

    return 0;
}
