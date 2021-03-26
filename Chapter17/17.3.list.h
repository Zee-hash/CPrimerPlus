/* list.h -- 简单链表类型的头文件 */
#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h>
// 特定程序的声明
#define TSIZE 45 // 储存电影名的数组大小
struct film
{
    char title[TSIZE];
    int rating;
};

// 通用类型定义
typedef struct film Item;
typedef struct node
{
    Item item;
    struct node *next;
} Node;
typedef Node *List;

// 函数原型
/**
 * 操   作：初始化一个链表
 * 前提条件：plist指向一个链表
 * 后置条件：链表初始化为空
**/
void InitializeList(List *plist);

/**
 * 操   作：确定链表是否为空定义
 * 前提条件：plist指向一个已初始化的链表
 * 后置条件：如果链表为空，该函数返回true；否则返回false
**/
bool ListIsEmpty(const List *plist);

/**
 * 操   作：确定链表是否已满
 * 前提条件：plist指向一个已初始化的链表
 * 后置条件：如果链表已满，该函数返回true；否则返回false
**/
bool ListIsFull(const List *plist);

/**
 * 操   作：在链表的末尾添加项
 * 前提条件：item是一个待添加至链表的项，plist指向一个已初始化的链表
 * 后置条件：如果添加成功，函数将在链表末尾添加一项，且返回true；否则返回false
**/
bool AddItem(Item item, List *plist);

/**
 * 操   作：返回结点的个数
 * 前提条件：plist指向一个已初始化的链表
 * 后置条件：如果执行成功，返回链表结点个数
**/
unsigned int ListItemCount(const List *plist);

/**
 * 操   作：把函数作用于链表的每一项
 * 前提条件：plist指向一个已初始化的链表,pfun指向一个函数，该函数接受一个Item类型的参数，且无返回值
 * 后置条件：pfun指向的函数作用于链表中的每一项一次
**/
void Traverse(const List *plist, void (*pfun)(Item item));

/**
 * 操   作：释放已分配的内存（如果有的话）
 * 前提条件：plist指向一个已初始化的链表
 * 后置条件：释放为链表分配的所有内存，链表设置为空
**/
void EmptyTheList(List *plist);

#endif