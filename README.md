# 数据结构（考研408）

这个项目包含了考研408数据结构课程中常见的数据结构实现，使用C语言编写。每个数据结构都提供了标准的创建、销毁、增删查等基本操作。

## 目录结构

```
/DataStructure408
  ├── Common.h           # 通用定义和错误码
  ├── LinearList/        # 线性表
  │   ├── SequenceList/  # 顺序表
  │   └── LinkedList/    # 链表
  ├── Stack/             # 栈
  │   ├── SequenceStack/ # 顺序栈
  │   └── LinkedStack/   # 链栈
  ├── Queue/             # 队列
  │   ├── SequenceQueue/ # 顺序队列
  │   └── LinkedQueue/   # 链队列
  ├── Tree/              # 树
  │   ├── BinaryTree/    # 二叉树
  │   └── BST/           # 二叉搜索树
  ├── Graph/             # 图
  │   ├── AdjMatrix/     # 邻接矩阵
  │   └── AdjList/       # 邻接表
  ├── Search/            # 查找
  └── Sort/              # 排序
```

## 接口设计

每个数据结构都提供以下标准接口：

1. 创建/初始化 - `Create` / `Init`
2. 销毁 - `Destroy`
3. 增加元素 - `Insert` / `Add` / `Push`
4. 删除元素 - `Delete` / `Remove` / `Pop`
5. 查找/获取元素 - `Find` / `Get`
6. 其他特定操作（如遍历、判空等）

## 编译和运行

本项目使用C语言编写，可以使用gcc编译器进行编译。
