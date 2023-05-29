#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

static long num_step = 4000;
double steps;

int main() {
    int i;
    double pi, x, sum = 0.0;
    steps = 1.0 /(double) num_step;

        omp_set_num_threads(1000);
double start_time=  omp_get_wtime();
    #pragma omp parallel for private(x) reduction(+:sum)
    for (i = 0; i < num_step; i++) {
        x = (i + 0.5) * steps;
        sum = sum + 4.0 / (1.0 + x * x);
    }

double end_time=  omp_get_wtime();
double ex_time=end_time-start_time;
    pi = steps * sum;

    printf("pi=: %.10f\n", pi);
printf("%lf\n",ex_time);
    return 0;
}

