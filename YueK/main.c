#include <stdio.h>
#include <stdbool.h>

#include "GuaList.h"
#include "GuaStack.h"
#include "GuaQueue.h"
#include "GuaTest.h"


void
testGuaListLength() {
    type a1[] = {1, 2, 3};
    int n1 = 3;
    GuaList *l1 = GuaListCreate(a1, n1);
    ensure(GuaListLength(l1) == n1, "test list length 1");

    type a2[] = {};
    int n2 = 0;
    GuaList *l2 = GuaListCreate(a2, n2);
    ensure(GuaListLength(l2) == n2, "test list length 2");

    type a3[] = {1, 2};
    int n3 = 2;
    GuaList *l3 = GuaListCreate(a3, n3);
    ensure(GuaListLength(l3) != (n3 + 1), "test list length 3");
}

void
testGuaListContains() {
    type a1[] = {1, 2, 3};
    int n1 = 3;
    GuaList *l1 = GuaListCreate(a1, n1);
    ensure(GuaListContains(l1, n1) == true, "test list contains 1");

    type a2[] = {1, 5, 7};
    int n2 = 3;
    GuaList *l2 = GuaListCreate(a2, n2);
    ensure(GuaListContains(l2, n2) == false, "test list contains 2");

    type a3[] = {2, 4, 1, 3};
    int n3 = 4;
    GuaList *l3 = GuaListCreate(a3, n3);
    ensure(GuaListContains(l3, n3) == true, "test list contains 3");
}

void
testGuaListAppend() {
    type a1[] = {1, 2, 3};
    int n1 = 3;
    GuaList *l1 = GuaListCreate(a1, n1);
    GuaListAppend(l1, 4);

    //
    type a2[] = {1, 2, 3, 4};
    int n2 = 4;
    GuaList *l2 = GuaListCreate(a2, n2);
    ensure(GuaListEqual(l1, l2), "test list append 1");

    type a3[] = {1, 5, 1};
    int n3 = 3;
    GuaList *l3 = GuaListCreate(a3, n3);
    //
    type a4[] = {1, 5, 1, 8};
    int n4 = 4;
    GuaList *l4 = GuaListCreate(a4, n4);
    GuaListAppend(l3, 10);
    ensure(!GuaListEqual(l3, l4), "test list append 2");

    type a5[] = {3, 6, 10};
    int n5 = 3;
    GuaList *l5 = GuaListCreate(a5, n5);
    //
    type a6[] = {3, 6, 10, 100};
    int n6 = 4;
    GuaList *l6 = GuaListCreate(a6, n6);
    GuaListAppend(l5, 100);
    ensure(GuaListEqual(l5, l6), "test list append 3");
}

void
testGuaListPrepend() {
    type a1[] = {1, 2, 3};
    int n1 = 3;
    GuaList *l1 = GuaListCreate(a1, n1);
    GuaListPrepend(l1, 4);
    //
    type a2[] = {4, 1, 2, 3};
    int n2 = 4;
    GuaList *l2 = GuaListCreate(a2, n2);
    ensure(GuaListEqual(l1, l2), "test list prepend 1");

    type a3[] = {1, 5, 1};
    int n3 = 3;
    GuaList *l3 = GuaListCreate(a3, n3);
    //
    type a4[] = {1, 5, 1, 8};
    int n4 = 4;
    GuaList *l4 = GuaListCreate(a4, n4);
    GuaListPrepend(l3, 10);
    ensure(!GuaListEqual(l3, l4), "test list prepend 2");

    type a5[] = {3, 6, 10};
    int n5 = 3;
    GuaList *l5 = GuaListCreate(a5, n5);
    //
    type a6[] = {100, 3, 6, 10};
    int n6 = 4;
    GuaList *l6 = GuaListCreate(a6, n6);
    ensure(GuaListEqual(GuaListPrepend(l5, 100), l6), "test list prepend 3");
}

void
testGuaIndexOfElement() {
    type a1[] = {1, 2, 3};
    int n1 = 3;
    GuaList *l1 = GuaListCreate(a1, n1);
    ensure(GuaListIndexOfElement(l1, 3) == 2, "test list index 1");

    type a2[] = {4, 1, 3};
    int n2 = 3;
    GuaList *l2 = GuaListCreate(a2, n2);
    ensure(GuaListIndexOfElement(l2, 14) == -1, "test list index 2");

    type a3[] = {1, 12, 53};
    int n3 = 3;
    GuaList *l3 = GuaListCreate(a3, n3);
    ensure(GuaListIndexOfElement(l3, 53) == 2, "test list index 3");
}

void
testGuaListInsertElementAtIndex() {
    type a1[] = {1, 2, 3};
    int n1 = 3;
    GuaList *l1 = GuaListCreate(a1, n1);

    type a2[] = {1, 2, 5, 3};
    int n2 = 4;
    GuaList *l2 = GuaListCreate(a2, n2);

    type e1 = 5;
    GuaListInsertElementAtIndex(l1, e1, 2);
    ensure(GuaListEqual(l1, l2), "test list insert 1");

    type a3[] = {1, 2, 3};
    int n3 = 3;
    GuaList *l3 = GuaListCreate(a3, n3);

    type a4[] = {3, 5, 3};
    int n4 = 4;
    GuaList *l4 = GuaListCreate(a4, n4);

    type e2 = 15;
    GuaListInsertElementAtIndex(l2, e2, 2);
    ensure(!GuaListEqual(l3, l4), "test list insert 2");

    type a6[] = {1, 2, 3};
    int n6 = 3;
    GuaList *l6 = GuaListCreate(a6, n6);

    type a5[] = {3, 5, 3};
    int n5 = 4;
    GuaList *l5 = GuaListCreate(a5, n5);

    type e3 = 15;
    GuaListInsertElementAtIndex(l6, e3, 2);
    ensure(!GuaListEqual(l5, l6), "test list insert 3");
}


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

// void
// testGuaStackPush() {
//     GuaStack *s1 = GuaStackCreate();
//     GuaStackPush(s1, 1);
//
//     // GuaList *l1 = s1->list;
//     // GuaListLog(l1);
//     // ensure(GuaStackLength(s1) == 1, "test stack push 1");
//
// }

void testGuaStackIsEmpty() {
    GuaStack *s1 = GuaStackCreate();
    // GuaStackIsEmpty(s1);
    ensure(GuaStackIsEmpty(s1),"test stack is empty1");
}

int
main(int argc, const char * argv[]) {
    // testGuaListLength();
    // testGuaListContains();
    // testGuaListAppend();
    // testGuaListPrepend();
    // testGuaIndexOfElement();
    // testGuaListInsertElementAtIndex();

    //stack的测试
    testGuaStackLength();
    // testGuaStackPush();

    testGuaStackIsEmpty();

    //queue的测试


    // 返回 0 表示程序执行完毕并成功退出
    return 0;
}
