#ifndef __GuaHashTable_H__
#define __GuaHashTable_H__

#include <stdbool.h>
#include <stdlib.h>


// interface
// 声明 结构名, 类型
// struct GuaNodeStruct;
// typedef struct GuaNodeStruct GuaNode;
struct GuaHashTableStruct;
typedef struct GuaHashTableStruct GuaHashTable;
// typedef int type;

/*
hashtable 所有操作都是 O(1)
用一个大数组来存储数字
key 是 string, 被计算为一个数字作为下标
这个计算过程叫做 hash(取摘要)
这样就可以 O(1) 的时间存取值

当 2 个 key 的 hash 值相等的时候
称之为碰撞
解决碰撞有很多种方法
最方便的一种叫做链表法

数组的长度通常为一个素数
在 C 语言中, 数组长度是固定的



假设数组长度为 100, 要存取 100000000000 个元素, 就不是 O(1) 了
    这个问题解决了

*/

// string
// [iuywiruha\0]
// x32      32位
// amd64    64位
// x86-64
// i64

// 创建并返回一个 hashtable
GuaHashTable *
GuaHashTableCreate(void);

// 往 hashtbale 中设置一个值, GuaHashTable 只支持 int 类型的值
void
GuaHashTableSet(GuaHashTable *table, const char *key, int value);

// 检查 hashtable 中是否存在这个 key
bool
GuaHashTableHas(GuaHashTable *table, const char *key);

// 返回 hashtable 中 key 对应的值, 不考虑 key 不存在的情况, 用户应该用 GuaHashTableHas 自行检查是否存在
int
GuaHashTableGet(GuaHashTable *table, const char *key, bool *exist);

// 销毁一个 hashtable
void
GuaHashTableRemove(GuaHashTable *table);

#endif
