#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "GuaList.h"
//
//创建两个单链表A、B,要求A、B 的元素按升序排列,输出单链表A、B,
//然后将A、B中相同的元素放在单链表C中，C也按升序排列，输出单链表C。


// interface
// 声明 结构名, 类型
struct GuaNode;
typedef struct GuaNode GuaList;
typedef int type;

// 结构的具体定义
struct GuaNode {
    type element;
    int length;
    GuaList *last;
    GuaList *next;
};


// 创建并返回一个 List
// element 是一个 int 数组
// numberOfElements 是数组的长度
// 在 C 语言中, 数组的长度信息要额外提供
GuaList *
GuaListCreate(int *element, int numberOfElements) {
    // assert 是用于确保一定条件的断言
    assert(numberOfElements >= 0);

    // malloc 申请一块内存, 并初始化一下
    GuaList *list = malloc(sizeof(GuaList));
    list->next = NULL;

    // 循环插入初始化元素
    for(int i = numberOfElements - 1; i >= 0; i--) {
        GuaList *n = malloc(sizeof(GuaList));
        n->element = element[i];
        n->next = list->next;
        list->next = n;
        if (i == numberOfElements - 1) {
            list->last = n;
        }
    }
    list->length = numberOfElements;
    return list;
}

// 把一个 List 的数据打印出来
void
GuaListLog(GuaList *list) {
    GuaList *l = list->next;
    while(l != NULL) {
        printf("%d  ", l->element);
        l = l->next;
    }
    printf("\n");
}


bool
GuaListEqual(GuaList *l_1, GuaList *l_2) {
    bool lengthEqual = (GuaListLength(l_1) == GuaListLength(l_2));
    bool nodeEqual = false;
    GuaList *l1 = l_1->next;
    GuaList *l2 = l_2->next;
    if(lengthEqual) {
        while(l2->next != NULL) {
            if (l1->element != l2->element) {
                return nodeEqual;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        // 此时的 l1 l2 都是最后的元素
        if(l1->element == l2->element) {
            nodeEqual = true;
        }
    }
    return nodeEqual;
}


int
GuaListLength(GuaList *list) {
    return list->length;
}

bool
GuaListContains(GuaList *list, type element) {
    GuaList *l = list->next;
    while(l != NULL) {
        if(element == l->element) {
            return true;
            break;
        }
        l = l->next;
    }
    return false;
}

void
GuaListAppend(GuaList *list, type element) {
    GuaList *l = list->last;
    list->length++;
    // 此时的 l 是最后一个元素
    GuaList *temp = GuaListCreate(&element, 1);
    l->next = temp;
    temp->element = element;
    temp->next = NULL;
}


GuaList *
GuaListPrepend(GuaList *list, type element) {
    list->length++;
    GuaList *n = GuaListCreate(&element,1);
	n->element = element;
	n->next = list->next;
	list->next = n;
}

int
GuaListIndexOfElement(GuaList *list, type element) {
    int index = -1;
    GuaList *l = list->next;
    while(l != NULL) {
        // printf("l->element:%d element:%d\n", l->element, element);
        if (l->element == element) {
            index++;
            return index;
        } else {
            index++;
            l = l->next;
        }
    }
    return -1;
}


void
GuaListInsertElementAtIndex(GuaList *list, type element, int index) {
    GuaList *l = list->next;
    int i = 0;
    while (l != NULL) {
        ++i;
        if (i == index) {
            break;
        }
        l = l->next;
    }
    GuaList *n = GuaListCreate(&element,1);
    list->length++;
    n->element = element;
    n->next = l->next;
    l->next = n;
}

type
GuaListPop(GuaList *list) {
    GuaList *l = list->next;
    type e = l->element;
    list->length--;
    list->next = l->next;
    free(l);
    return e;
}

bool
GuaListIsEmpty(GuaList *list) {
    return list->length == 0;
}
