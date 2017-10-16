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
