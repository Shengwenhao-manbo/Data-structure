/**
 * @file SequenceList.h
 * @brief 顺序表的定义和接口
 */

#ifndef DATASTRUCTURE408_SEQUENCE_LIST_H
#define DATASTRUCTURE408_SEQUENCE_LIST_H

#include "../../Common.h"
#include <stdlib.h>

// 默认的顺序表初始大小
#define INIT_SIZE 100
// 顺序表增长的幅度
#define INCREMENT 10

// 元素类型定义
typedef int ElemType;

// 顺序表结构定义
typedef struct {
    ElemType *elem;    // 存储空间基址
    int length;       // 当前长度
    int size;         // 当前分配的存储容量
} SqList;

/**
 * @brief 初始化顺序表
 * @param L 顺序表指针
 * @return Status 操作结果
 */
Status InitList(SqList *L);

/**
 * @brief 销毁顺序表
 * @param L 顺序表指针
 * @return Status 操作结果
 */
Status DestroyList(SqList *L);

/**
 * @brief 清空顺序表
 * @param L 顺序表指针
 * @return Status 操作结果
 */
Status ClearList(SqList *L);

/**
 * @brief 判断顺序表是否为空
 * @param L 顺序表指针
 * @return Bool 判断结果
 */
Bool ListEmpty(SqList *L);

/**
 * @brief 获取顺序表长度
 * @param L 顺序表指针
 * @return int 顺序表长度
 */
int ListLength(SqList *L);

/**
 * @brief 获取顺序表中指定位置的元素
 * @param L 顺序表指针
 * @param i 位置索引（从1开始）
 * @param e 返回的元素值
 * @return Status 操作结果
 */
Status GetElem(SqList *L, int i, ElemType *e);

/**
 * @brief 在顺序表中定位元素
 * @param L 顺序表指针
 * @param e 要定位的元素
 * @param compare 比较函数指针
 * @return int 元素位置，如果找不到返回0
 */
int LocateElem(SqList *L, ElemType e, int (*compare)(ElemType, ElemType));

/**
 * @brief 在顺序表的指定位置插入元素
 * @param L 顺序表指针
 * @param i 插入位置（从1开始）
 * @param e 要插入的元素
 * @return Status 操作结果
 */
Status ListInsert(SqList *L, int i, ElemType e);

/**
 * @brief 删除顺序表中指定位置的元素
 * @param L 顺序表指针
 * @param i 删除位置（从1开始）
 * @param e 返回被删除的元素
 * @return Status 操作结果
 */
Status ListDelete(SqList *L, int i, ElemType *e);

/**
 * @brief 遍历顺序表中的每个元素
 * @param L 顺序表指针
 * @param visit 访问函数指针
 * @return Status 操作结果
 */
Status ListTraverse(SqList *L, void (*visit)(ElemType));

#endif // DATASTRUCTURE408_SEQUENCE_LIST_H
