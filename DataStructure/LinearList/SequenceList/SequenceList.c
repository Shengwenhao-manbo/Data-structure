/**
 * @file SequenceList.c
 * @brief 顺序表的实现
 */

#include "SequenceList.h"
#include <stdio.h>
#include <stdlib.h>

Status InitList(SqList *L) {
    // 分配初始存储空间
    L->elem = (ElemType *)malloc(INIT_SIZE * sizeof(ElemType));
    if (!L->elem) {
        return MEMORY_ERROR; // 内存分配失败
    }
    L->length = 0;       // 初始长度为0
    L->size = INIT_SIZE; // 初始存储容量
    return SUCCESS;
}

Status DestroyList(SqList *L) {
    if (!L->elem) {
        return ERROR;
    }
    free(L->elem); // 释放分配的内存
    L->elem = NULL;
    L->length = 0;
    L->size = 0;
    return SUCCESS;
}

Status ClearList(SqList *L) {
    if (!L->elem) {
        return ERROR;
    }
    L->length = 0; // 将长度置为0，实际上并不需要清除内存
    return SUCCESS;
}

Bool ListEmpty(SqList *L) {
    if (!L->elem) {
        return TRUE;
    }
    return L->length == 0 ? TRUE : FALSE;
}

int ListLength(SqList *L) {
    if (!L->elem) {
        return 0;
    }
    return L->length;
}

Status GetElem(SqList *L, int i, ElemType *e) {
    if (!L->elem || i < 1 || i > L->length) {
        return ERROR; // 列表不存在或索引越界
    }
    *e = L->elem[i - 1]; // 注意索引从1开始，实际数组从0开始
    return SUCCESS;
}

int LocateElem(SqList *L, ElemType e, int (*compare)(ElemType, ElemType)) {
    if (!L->elem) {
        return 0;
    }
    
    int i;
    for (i = 0; i < L->length; i++) {
        if (compare ? compare(L->elem[i], e) : L->elem[i] == e) {
            return i + 1; // 返回位置（从1开始）
        }
    }
    return 0; // 未找到
}

Status ListInsert(SqList *L, int i, ElemType e) {
    // 检查参数有效性
    if (!L->elem || i < 1 || i > L->length + 1) {
        return ERROR;
    }
    
    // 检查是否需要扩容
    if (L->length >= L->size) {
        ElemType *newbase = (ElemType *)realloc(L->elem, (L->size + INCREMENT) * sizeof(ElemType));
        if (!newbase) {
            return OVERFLOW; // 内存分配失败
        }
        L->elem = newbase;
        L->size += INCREMENT;
    }
    
    // 将插入位置及以后的元素向后移动
    int j;
    for (j = L->length - 1; j >= i - 1; j--) {
        L->elem[j + 1] = L->elem[j];
    }
    
    // 插入新元素并增加长度
    L->elem[i - 1] = e;
    L->length++;
    
    return SUCCESS;
}

Status ListDelete(SqList *L, int i, ElemType *e) {
    // 检查参数有效性
    if (!L->elem || i < 1 || i > L->length) {
        return ERROR;
    }
    
    // 保存要删除的元素
    *e = L->elem[i - 1];
    
    // 将删除位置后的元素向前移动
    int j;
    for (j = i; j < L->length; j++) {
        L->elem[j - 1] = L->elem[j];
    }
    
    // 减少长度
    L->length--;
    
    return SUCCESS;
}

Status ListTraverse(SqList *L, void (*visit)(ElemType)) {
    if (!L->elem || !visit) {
        return ERROR;
    }
    
    int i;
    for (i = 0; i < L->length; i++) {
        visit(L->elem[i]);
    }
    
    return SUCCESS;
}
