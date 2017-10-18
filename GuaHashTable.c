#include <stdio.h>

#include "GuaHashTable.h"
#include "GuaList.h"


// 结构的具体定义
struct GuaHashTableKeyValueStruct;
typedef struct GuaHashTableKeyValueStruct GuaKeyValue;
// struct GuaHashTableStruct;
// typedef struct GuaHashTableStruct GuaHashTable;

struct GuaHashTableKeyValueStruct {
    char *key;
    int value;
};

struct GuaHashTableStruct {
    int arrayLength;
	GuaList **array;
};

// 暂时把 stirng 处理函数写在这里
int
stringLength(const char *s) {
    int len = 0;
    while (*s != '\0') {
        len++;
        s++;
    }
    return len;
}

char *
stringCopy(const char *string) {
    int len = stringLength(string);
    char *s = malloc(len + 1);
    for (size_t i = 0; i < len; i++) {
        s[i] = string[i];
    }
    s[len] = '\0';
    return s;
}

bool
stringEqual(const char *s1, const char *s2) {
    int len1 = stringLength(s1);
    int len2 = stringLength(s2);
    if (len1 != len2) {
        return false;
    } else {
        for (size_t i = 0; i < len1; i++) {
            if (s1[i] != s2[i]) {
                return false;
            }
        }
    }
    return true;
}

// 内部函数
GuaKeyValue *
GuaKeyValueCreate(const char *key, int value) {
    GuaKeyValue *kv = malloc(sizeof(GuaKeyValue));
    kv->key = stringCopy(key);
    kv->value = value;
    return kv;
}

int
GuaKeyValueValue(GuaKeyValue *kv) {
    return kv->value;
}

bool
GuaKeyValueKeyEqual(void *kv1, void *kv2) {
    GuaKeyValue *p1 = kv1;
    GuaKeyValue *p2 = kv2;
    bool eq = stringEqual(p1->key, p2->key);
    // printf("kv equal (%c) (%s), (%s)", eq, p1->key, p2->key);
    return eq;
}

// 创建并返回一个 hashtable
GuaHashTable *
GuaHashTableCreate(void) {
    int length = 107;
    GuaHashTable *h = malloc(sizeof(GuaHashTable));
    h->arrayLength = length;
    //
    GuaList **array = malloc(sizeof(GuaList *) * length);
    // 初始化数组中所有元素为 NULL
    for (size_t i = 0; i < length; i++) {
        // array[i] = NULL;
        array[i] = GuaListCreate(NULL, 0);
    }
    h->array = array;
    //
    return h;
}

// static 修饰的函数只在本文件内可以被调用
static int
hash(const char *key) {
    // gua 计算过程如下
    // 'g' * 1 + 'u' * 10 + 'a' * 100
    int digit = 1;
    int sum = 0;
    const char *p = key;
    while (*p != '\0') {
        sum += *p * digit;
        digit *= 10;
        p++;
    }
    return sum;
}

// 往 hashtbale 中设置一个值, GuaHashTable 只支持 int 类型的值
void
GuaHashTableSet(GuaHashTable *table, const char *key, int value) {
    // 1, 通过 hash 得到 index
    int index = hash(key) % table->arrayLength;
    GuaList *list = table->array[index];
    printf("GuaHashTableSet hash %d\n", index);
    if (GuaListIsEmpty(list)) {
        // 说明这里没有存元素, 直接 append
        GuaKeyValue *kv = GuaKeyValueCreate(key, value);
        GuaListAppend(list, kv);
    } else {
        // 说明这里存了元素, 要看 key 是否存在 list 中
        GuaKeyValue *kv = GuaKeyValueCreate(key, value);
        int index = GuaListIndexOfElement(list, kv, GuaKeyValueKeyEqual);
        // printf("index %d\n", index);
        if(index != -1) {
            // 重设这个值
            GuaListUpdateElementAtIndex(list, kv, index);
        } else {
            GuaListAppend(list, kv);
        }
    }
}

// 检查 hashtable 中是否存在这个 key
bool
GuaHashTableHas(GuaHashTable *table, const char *key) {
    // 1, 通过 hash 得到 index
    int index = hash(key) % table->arrayLength;
    GuaList *list = table->array[index];
    // printf("GuaHashTableSet hash %d\n", index);
    if (GuaListIsEmpty(list)) {
        // 说明这里没有存元素, 直接 false
        return false;
    } else {
        // 说明这里存了元素, 要看 key 是否存在 list 中
        GuaKeyValue *kv = GuaKeyValueCreate(key, 0);
        int index = GuaListIndexOfElement(list, kv, GuaKeyValueKeyEqual);
        // printf("index %d\n", index);
        return index != -1;
    }
}

// 返回 hashtable 中 key 对应的值, 不考虑 key 不存在的情况, 用户应该用 GuaHashTableHas 自行检查是否存在
int
GuaHashTableGet(GuaHashTable *table, const char *key, bool *exist) {
    // 1, 通过 hash 得到 index
    int index = hash(key) % table->arrayLength;
    GuaList *list = table->array[index];
    // printf("GuaHashTableSet hash %d\n", index);
    if (GuaListIsEmpty(list)) {
        // 这里是不存在的, 因为函数要求必须存在 key
        *exist = false;
        return -1;
    } else {
        // 说明这里存了元素, 要看 key 是否存在 list 中
        GuaKeyValue *kv = GuaKeyValueCreate(key, 0);
        int index = GuaListIndexOfElement(list, kv, GuaKeyValueKeyEqual);
        // printf("index %d\n", index);
        if(index != -1) {
            // 重设这个值
            *exist = true;
            GuaKeyValue *kv = GuaListElementAtIndex(list, index);
            return GuaKeyValueValue(kv);
        } else {
            *exist = false;
            return -1;
        }
    }
}

// 销毁一个 hashtable
void
GuaHashTableRemove(GuaHashTable *table) {

}
