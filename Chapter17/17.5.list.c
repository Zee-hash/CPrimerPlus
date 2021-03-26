/* list.c -- 支持链表操作的函数 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "17.3.list.h"
// 局部函数原型
static void CopyToNode(Item item, Node * pnode);

// 接口函数
// 把链表设置为空
void InitializeList(List * plist)
{
    *plist = NULL;
}

// 如果链表为空，返回true
bool ListIsEmpty(const List * plist)
{
    if(*plist == NULL)
        return true;
    return false;
}

// 如果链表已满，返回true
bool ListIsFull(const List * plist)
{
    Node *pt;
    bool full;
    pt = (Node *)malloc(sizeof(Node));
    if(pt == NULL)
    {
        full = true;
    }
    else
    {
        full = false;
        free(pt);
    }
    return full;
}

// 返回结点的数量
unsigned int ListItemCount(const List * plist)
{
    unsigned int count = 0;
    Node * pnode = *plist;
    while(pnode != NULL)
    {
        ++count;
        pnode = pnode -> next;
    }
    return count;
}

// 创建存储项的结点，并将其添加至plist指向的链表末尾
bool AddItem(Item item, List *plist)
{
    Node *pnew;
    Node *scan = *plist;
    pnew = (Node *)malloc(sizeof(Node));
    if(pnew == NULL)
    {
        return false;
    }
    CopyToNode(item, pnew);
    pnew -> next = NULL;
    if(scan == NULL) // 空链表
    {
        *plist = pnew;
    }
    else
    {
        while(scan->next != NULL)
            scan = scan -> next;
        scan -> next = pnew;// 添加到末尾
    }
    return true;   
}

// 访问每个结点并执行pfun指针指向的函数
void Traverse(const List *plist, void (*pfun)(Item item))
{
    Node *pnode = *plist;
    while(pnode != NULL)
    {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }
}

// 释放由malloc分配的内存
void EmptyTheList(List *plist)
{
    Node *psave;
    while(*plist != NULL)
    {
        psave = (*plist)->next;
        free(*plist);
        *plist = psave; // 前进至下一结点
    }
}

// 居住函数定义
// 把一个项拷贝到结点中
static void CopyToNode(Item item, Node *pnode)
{
    pnode->item = item;
}