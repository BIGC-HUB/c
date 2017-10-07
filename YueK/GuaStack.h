#ifndef __GuaStack_H__
#define __GuaStack_H__

#include <stdbool.h>

//声明 结构名, 类型
struct GuaStackNode;
typedef struct GuaStackNode GuaStack;
typedef int type;

// 结构的具体定义
struct GuaStackNode {
    GuaList *list;
};
//创建并返回一个空栈
GuaStack *
GuaStackCreate();

type
GuaStackLength(GuaStack *stack);

void
GuaStackPush(GuaStack *stack,type e);

// //返回栈顶的元素
type
GuaStackPop(GuaStack *stack);

// 检查栈是否为空
bool
GuaStackIsEmpty(GuaStack *stack);

// //时间复杂度 O(n), 删除栈的所有元素(清空栈)
// bool
// GuaStackClear(GuaStack *stack);
//
// // 删除栈中所有元素并销毁栈
// void
// GuaStackRemove(GuaStack *stack);

#endif
