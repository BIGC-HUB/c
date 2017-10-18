// 编译头
// ﻿#include "stdafx.h"

#include "GuaList.h"
#include "GuaTest.h"
#include "GuaStack.h"
#include "GuaHashTable.h"


void
testGuaHashTableCreate(void) {
    GuaHashTableCreate();
}

void
testGuaHashTableSetGet(void) {
    GuaHashTable *h = GuaHashTableCreate();
    GuaHashTableSet(h, "name", 1);
    bool exist;
    int v = GuaHashTableGet(h, "name", &exist);
    printf("test set get %d\n", v);

    GuaHashTableSet(h, "name", 110);
    v = GuaHashTableGet(h, "name", &exist);
    printf("test set get %d\n", v);
}

void
test() {
    testGuaHashTableCreate();
    testGuaHashTableSetGet();
}

int
main() {
#if _WIN32
	SetConsoleOutputCP(65001);
#endif
    test();
	printf("得是嘛不是\n");

    return 0;
}
