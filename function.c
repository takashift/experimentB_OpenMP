#include <stdio.h>
#include <math.h>
#include <omp.h>

#define ITERATION_NUM 100
#define ARRAY_NUM 100000000

// main()に書くとスタックから溢れてセグフォになるので、スタック外に割り当てられるようにグローバルに書く。
// 勝手に他の場所で変えられないように static を付ける。
static int array[ARRAY_NUM];

int main() {
	double result=0, start_time, end_time, time;
	int i, it;

	// 配列の初期化
	for(i=0; i<ARRAY_NUM; i++) {
		array[i] = i+1;
	}

	start_time = omp_get_wtime();
	// 重みの関数を実行
	for(it=0; it<ITERATION_NUM; it++) {
		// 並列処理
#pragma omp parallel for reduction(+:result)
		for(i=0; i<ARRAY_NUM; i++) {
			result += 1/array[i];
		}
	}
	end_time = omp_get_wtime();

	time = end_time - start_time;
	printf("elapsed_time = %lf\n", time / ITERATION_NUM);

	return 0;
}
