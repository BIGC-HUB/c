#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "GuaStack.h"
#include "GuaList.h"

//声明 结构名, 类型
struct GuaStackNode;
typedef struct GuaStackNode GuaStack;
typedef int type;

// 结构的具体定义
struct GuaStackNode {
    GuaList *list;
};

GuaStack *
GuaStackCreate() {
    GuaStack *stack = malloc(sizeof(GuaStack));
    type e[] = {};
    type number = 0;
    stack->list = GuaListCreate(e,number);
    return stack;
}

type
GuaStackLength(GuaStack *stack) {
    GuaList *l = stack->list;
    return GuaListLength(l);
}

void
GuaStackPush(GuaStack *stack, type e) {
    GuaList *l = stack->list;
    GuaListAppend(l, e);
}

type
GuaStackPop(GuaStack *stack) {
    GuaList *l = stack->list;
    GuaListPop(l);
}
//检查栈是否为空
bool
GuaStackIsEmpty(GuaStack *stack){
    GuaList *l = stack->list;
    return GuaListIsEmpty(l);
}

//时间复杂度 O(n), 删除栈的所有元素(清空栈)
// bool
// GuaStackClear() {
//
// }

// 删除栈中所有元素并销毁栈
// void
// GuaStackRemove(GuaStack *) {
//
// }
