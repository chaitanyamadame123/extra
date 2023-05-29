#include <stdio.h>
#include <omp.h>

int main() {
    int n = 3;
    int fact = 1;


    omp_set_num_threads(4);

    double start_time = omp_get_wtime();
int i;
        #pragma omp parallel for reduction(*:fact)
    for ( i = 2; i <= n; i++) {
        fact *= i;
    }

    double end_time = omp_get_wtime();
    double execution_time = end_time - start_time;

    printf("Factorial of %d is %d\n", n, fact);
    printf("Execution time: %f seconds\n", execution_time);

    return 0;
}

