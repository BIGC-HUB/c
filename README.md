https://github.com/happlebao/visual_studio_demo
c99 (-std=c99)
-x c

```c
// stdafx.h 编译头
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <tchar.h>
```

```c
// main
#include "stdafx.h"

#if _WIN32
#include <Windows.h>
#endif


int main() {
#if _WIN32
	SetConsoleOutputCP(65001);
#endif
	printf("得是嘛不是\n");
    return 0;
}
```
