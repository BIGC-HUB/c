#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "GuaList.h"

//
//创建两个单链表A、B,要求A、B 的元素按升序排列,输出单链表A、B,
//然后将A、B中相同的元素放在单链表C中，C也按升序排列，输出单链表C。


// interface
// 声明 结构名, 类型
// struct GuaNode;
// typedef struct GuaNode GuaList;
// typedef int type;

// 结构的具体定义
struct GuaNodeStruct {
    type element;
    GuaNode *next;
};

struct GuaListStruct {
	int length;
    // 应该增加一个 freeElement 函数指针用来 free element 的内存
	GuaNode *tail;
	GuaNode *next;
};

// 创建并返回一个 List
// element 是一个 int 数组
// numberOfElements 是数组的长度
// 在 C 语言中, 数组的长度信息要额外提供
GuaList *
GuaListCreate(type *element, int numberOfElements) {
    // assert 是用于确保一定条件的断言
    assert(numberOfElements >= 0);

    // malloc 申请一块内存, 并初始化一下
    GuaList *list = malloc(sizeof(GuaList));
	list->length = numberOfElements;
    list->next = NULL;
    list->tail = NULL;
    // 循环插入初始化元素
    for(int i = numberOfElements - 1; i >= 0; i--) {
        GuaNode *n = malloc(sizeof(GuaNode));
        n->element = element[i];
        n->next = list->next;
		//
        list->next = n;
		// 设置 tail
		if (i == numberOfElements - 1) {
			list->tail = n;
		}
    }

    return list;
}

// 把一个 List 的数据打印出来
void
GuaListLog(GuaList *list) {
    GuaNode *l = list->next;
    while(l != NULL) {
        // printf("%d  ", l->element);
        l = l->next;
    }
    printf("\n");
}

int
GuaListLength(GuaList *list) {
	// int length = 0;
	// GuaNode *l = list->next;
    // while(l != NULL) {
	// 	length++;
    //     l = l->next;
    // }
	return list->length;
}

bool
GuaListIsEmpty(GuaList *list) {
    return GuaListLength(list) == 0;
}

bool
GuaListContains(GuaList *list, type element, FunctionElementEqual equal) {
	GuaNode *l = list->next;
	while(l != NULL) {
        // if (l->element == element) {
        if (equal(l->element, element)) {
			return true;
		}
		l = l->next;
	}
    return false;
}

void
GuaListAppend(GuaList *list, type element) {
	// list->length++
	list->length++;
	//
	GuaNode *n = malloc(sizeof(GuaNode));
	n->element = element;
	n->next = NULL;
    // 为第一次设置 next
	// 设置尾巴
    if (list->tail == NULL) {
        list->next = n;
    	list->tail = n;
    } else {
        list->tail->next = n;
        list->tail = n;
    }
}

void
GuaListPrepend(GuaList *list, type element) {
	// list->length++
	list->length++;
	GuaNode *n = malloc(sizeof(GuaNode));
	n->element = element;
	n->next = list->next;
	list->next = n;
}

int
GuaListIndexOfElement(GuaList *list, type element, FunctionElementEqual equal) {
	int index = -1;
	int i = 0;
	GuaNode *l = list->next;
    // printf("index of element %s\n", l);
	while(l != NULL) {
        if (equal(l->element, element)) {
			index = i;
			break;
		}
		i++;
		l = l->next;
	}
    return index;
}

void
GuaListInsertElementAtIndex(GuaList *list, type element, int index) {
	// list->length++
}

void
GuaListUpdateElementAtIndex(GuaList *list, type element, int index) {
    int i = 0;
    GuaNode *l = list->next;
    // printf("index of element %s\n", l);
    while(l != NULL) {
        if (i == index) {
            // type e = l->element;
            l->element = element;
            // TODO
            // 需要释放 e 的内存
        }
        i++;
        l = l->next;
    }
}

type
GuaListElementAtIndex(GuaList *list, int index) {
    int i = 0;
    GuaNode *l = list->next;
    // printf("index of element %s\n", l);
    while(l != NULL) {
        if (i == index) {
            return l->element;
        }
        i++;
        l = l->next;
    }
    return NULL;
}

void
GuaListRemoveFirstElement(GuaList *list) {
	list->length--;
	//
	GuaNode *n = list->next;
	list->next = n->next;
	free(n);
}

type
GuaListFirstElement(GuaList *list) {
	return list->next->element;
}
