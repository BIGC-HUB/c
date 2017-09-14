// 编译头
#include "stdafx.h"
// 定制方法
#define len(arr) sizeof(arr) / sizeof(arr[0])
#define log(...) printf(">>>" __VA_ARGS__)

int main(void) {
	int a[] = {1, 2, 99};
	for (size_t i = 0; i < len(a); i++) {
		log("第 %i 个等于 %i \n", i, a[i]);
	}
	getchar();
    return 0;
}
