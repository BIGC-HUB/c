/*
C 语言中的 #include 的意思实际上是复制整个文件的内容过来

所以为了防止重复包含头文件, 必须使用这种套路写法

在现代的 C 语言中有宏可以保证头文件只被包含一次
但是惯用的写法还是这样
*/
#ifndef __GuaList_H__
#define __GuaList_H__

#include <stdbool.h>


// interface
// 声明 结构名, 类型
struct GuaNodeStruct;
typedef struct GuaNodeStruct GuaNode;
struct GuaListStruct;
typedef struct GuaListStruct GuaList;
typedef void * type;


GuaList *
GuaListCreate(type *element, int numberOfElements);

void
GuaListLog(GuaList *list);

/*
1.1
返回一个 GuaList 的长度
*/
int
GuaListLength(GuaList *list);

bool
GuaListIsEmpty(GuaList *list);

/*
1.2
检查一个 GuaList 中是否存在某个元素
*/
typedef bool (*FunctionElementEqual)(void *, void *) ;
bool
GuaListContains(GuaList *list, type element, FunctionElementEqual);

/*
1.3
在 GuaList 的末尾添加一个元素
*/
void
GuaListAppend(GuaList *list, type element);

/*
1.4
在 GuaList 的头部添加一个元素
*/
void
GuaListPrepend(GuaList *list, type element);

/*
1.5
在一个 GuaList 中查找某个元素, 返回下标(序号)
如果不存在, 返回 -1
*/
int
GuaListIndexOfElement(GuaList *list, type element, FunctionElementEqual equal);

type
GuaListElementAtIndex(GuaList *list, int index);

void
GuaListUpdateElementAtIndex(GuaList *list, type element, int index);

/*
1.6
往一个 GuaList 中插入一个元素, 下标(序号) 为 index
不考虑非法情况(下标大于长度)
*/
void
GuaListInsertElementAtIndex(GuaList *list, type element, int index);

type
GuaListFirstElement(GuaList *list);

void
GuaListRemoveFirstElement(GuaList *list);

#endif
