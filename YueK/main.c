#include <stdio.h>
#include <stdbool.h>

#include "GuaList.h"
#include "GuaTest.h"
#include "GuaQueue.h"
#include "GuaStack.h"

void
testGuaStackLength() {
    int n1 = 0;
    GuaStack *s1 = GuaStackCreate();
    ensure(GuaStackLength(s1) == n1, "test stack length 1");

    // type a2[] = {};
    // int n2 = 0;
    // GuaList *l2 = GuaListCreate(a2, n2);
    // ensure(GuaStackLength(l2) == n2, "test list length 2");
    //
    // type a3[] = {1, 2};
    // int n3 = 2;
    // GuaList *l3 = GuaListCreate(a3, n3);
    // ensure(GuaStackLength(l3) != (n3 + 1), "test list length 3");
}

void
testGuaStackPush() {
    GuaStack *s1 = GuaStackCreate();
    GuaStackPush(s1, 1);

    // GuaList *l1 = s1->list;
    // GuaListLog(l1);
    // ensure(GuaStackLength(s1) == 1, "test stack push 1");

}

void testGuaStackIsEmpty() {
    GuaStack *s1 = GuaStackCreate();
    // GuaStackIsEmpty(s1);
    ensure(GuaStackIsEmpty(s1),"test stack is empty1");
}

int
main(int argc, const char * argv[]) {
    //stack的测试
    testGuaStackLength();
    testGuaStackIsEmpty();
    // testGuaStackPush();

    //queue的测试


    // 返回 0 表示程序执行完毕并成功退出
    return 0;
}
