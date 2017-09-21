// 编译头
#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//创建两个单链表 A、B,要求 A、B 的元素按升序排列,输出单链表 A、B,
//然后将 A、B中相同的元素放在单链表 C中，C也按升序排列，输出单链表C。
//
// interface

// struct node;
// typedef struct node GuaList;
// typedef int type;
#define GuaList struct node

struct node {
    int element;
    struct node *next;
};

struct node *
GuaListCreate(int *element, int numberOfElements) {
    assert(numberOfElements >= 0);

	struct node *list = (struct node*)malloc(sizeof(struct node));
    list->next = NULL;

    for(int i = numberOfElements - 1; i >= 0; i--) {
		struct node *n = (struct node*)malloc(sizeof(struct node));
        n->element = element[i];
        n->next = list->next;

        list->next = n;
    }

    return list;
}

void
GuaListLog(struct node *list) {
    struct node *l = list->next;
    while(l != NULL) {
        printf("%d  ", l->element);
        l = l->next;
    }
    printf("\n");
}

void
GuaListSort(struct node *list) {
    struct node *cusor = list->next;

    while(cusor != NULL) {
        struct node *l = cusor;
        struct node *min = l;

        while(l != NULL) {
            if(min->element > l->element) {
                min = l;
            }
            l = l->next;
        }
        int tmp = min->element;
        min->element = cusor->element;
        cusor->element = tmp;

        cusor = cusor->next;
    }
}

//struct node *
//GuaListFindTail(struct node *list) {
//    struct node *l = list->next;
//    while(list != NULL) {
//        l = l->next;
//    }
//    return l;
//}
//
//void
//GuaListAppendList(struct node *list, struct node *anotherList) {
//    struct node l = GuaListFindTail(list);
//    l->next = anotherList->next;
//    free(anotherList);
//}

void
GuaListInsert(struct node *list, int element) {
	struct node *n = (struct node*)malloc(sizeof(struct node));
    n->element = element;
    n->next = list->next;
    list->next = n;
}

struct node *
DisgustingAlgorithm(struct node *a, struct node *b) {
    struct node *c = GuaListCreate(0, 0);

    a = a->next;
    b = b->next;
    while(a != NULL && b != NULL) {
        if(a->element < b->element) {
            a = a->next;
        } else if(a->element > b->element) {
            b = b->next;
        } else {
            GuaListInsert(c, a->element);
            a = a->next;
            b = b->next;
        }
    }
    return c;
}

int
main(int argc, const char * argv[]) {
    // 创建两个单链表A、B
    int data_a[] = {1, 2, 3, 4, 5};
    int data_b[] = {3, 5, 6, 7, 8};

    struct node *A = GuaListCreate(data_a, 5);
    struct node *B = GuaListCreate(data_b, 5);

    // 要求A、B 的元素按升序排列
    GuaListSort(A);
    GuaListSort(B);

    // 输出单链表A、B
    GuaListLog(A);
    GuaListLog(B);

    // 然后将A、B中相同的元素放在单链表C中
    struct node *C = DisgustingAlgorithm(A, B);

    // C也按升序排列
    GuaListSort(C);

    // 输出单链表C
    GuaListLog(C);

    // insert code here...
	getchar();
    printf("Hello, World!\n");
    return 0;
}
