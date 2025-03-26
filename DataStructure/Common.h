/**
 * @file Common.h
 * @brief 通用定义和错误码
 */

#ifndef DATASTRUCTURE408_COMMON_H
#define DATASTRUCTURE408_COMMON_H

// 状态码定义
typedef enum {
    SUCCESS = 0,           // 操作成功
    ERROR = -1,           // 一般错误
    OVERFLOW = -2,        // 溢出错误
    UNDERFLOW = -3,       // 下溢错误
    NOT_FOUND = -4,       // 未找到元素
    INVALID_PARAM = -5,   // 无效参数
    MEMORY_ERROR = -6     // 内存分配错误
} Status;

// 布尔类型定义
typedef enum {
    FALSE = 0,
    TRUE = 1
} Bool;

#endif // DATASTRUCTURE408_COMMON_H
