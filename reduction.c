#include <stdio.h>
#include <omp.h>

#define ITERATION_NUM 100
#define ARRAY_NUM 100000000

// 整数、浮動小数点数で変更
double array[ARRAY_NUM];

int main(void)
{
	int i;
	int it;
	// 整数、浮動小数点数で変更
	double sum = 0;
	double start_sec, end_sec, all_time;

	for(i = 0; i < ARRAY_NUM; i++) 
		array[i] = i + 1;

	start_sec = omp_get_wtime();
	for(it = 0; it < ITERATION_NUM; it++) {
#pragma omp parallel for reduction(+:sum)
		for(i = 0; i < ARRAY_NUM; i++) 
			sum += array[i];
	}
	end_sec = omp_get_wtime();
	all_time = end_sec - start_sec;

	printf("elapsed_time = %lf\n", all_time / ITERATION_NUM);

	return 0;
}
