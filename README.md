https://github.com/happlebao/visual_studio_demo

|配置|参数|
|:-:|:-:|
|C语言标准|C99 (-std=c99)|
|编译为|编译为 C 代码 (-x c)|
|编译预编译头作为|编译为 C 代码 (-x c-header)|
|将警告视为错误|是 (-Werror)|
|警告等级|启用所有警告 (-Wall)|

```c
// 常用编译头
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <tchar.h>

#if _WIN32
#include <Windows.h>
#endif
```

```c
// main
#include "stdafx.h"

int main() {
#if _WIN32
	SetConsoleOutputCP(65001);
#endif
	printf("得是嘛不是\n");
    return 0;
}
```
