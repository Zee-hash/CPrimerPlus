#include <stdlib.h>
#include <stdio.h>
#include "link_list.h"

// 初始化链表
LinkList initLinkList()
{
    // 初始化头结点
    struct LList *mylist = malloc(sizeof(struct LList));
    if (mylist == NULL)
    {
        return NULL;
    }
    mylist->pHeader = malloc(sizeof(struct LinkNode));
    // 头结点中数据不关心
    mylist->pHeader->data = NULL;
    mylist->pHeader->next = NULL;
    mylist->m_size = 0;
    // 返回值转换为void *，从而隐藏数据细节
    return mylist;
}

// 插入结点
void insertLinkList(LinkList list, int pos, void * data)
{
    if (list == NULL || data == NULL)
    {
        return;
    }
    // 将传递过来隐藏的信息还原
    struct LList * mylist = list;
    if (pos < 0 || pos > mylist->m_size)
    {
        // 无效位置执行尾插
        pos = mylist->m_size;
    }
    // 创建临时结点
    struct LinkNode * pCurrent = mylist->pHeader;
    for (int i = 0; i < pos; i++)
    {
        // 由于头结点的存在，使得插入位置为pos时，插入位置的前驱结点为指向头结点指针往后移动pos次
        pCurrent = pCurrent->next;
    }
    // 新结点
    struct LinkNode *newNode = malloc(sizeof(struct LinkNode));
    newNode->data = data;
    newNode->next = NULL;
    // 新结点插入到链表
    newNode->next = pCurrent->next;
    pCurrent->next = newNode;
    // 长度+1
    mylist->m_size++;
}

// 遍历链表
void foreachLinkList(LinkList list, void (*myPrint)(void *))
{
    if (list == NULL || myPrint == NULL)
    {
        return;
    }
    
    // 将传递过来隐藏的信息还原
    struct LList * mylist = list;
    // 第一个有数据的结点
    struct LinkNode *pCurrent = mylist->pHeader->next;
    for (int i = 0; i < mylist->m_size; i++)
    {
        // 交给用户打印
        myPrint(pCurrent->data);
        pCurrent = pCurrent->next;
    }
}

// 删除结点
void removebyPosition(LinkList list, int pos)
{
    if (list == NULL)
    {
        return;
    }
    // 将传递过来隐藏的信息还原
    struct LList * mylist = list;
    if (pos < 0 || pos > mylist->m_size - 1)
    {
        return;
    }
    struct LinkNode * pCurrent = mylist->pHeader;
    for (int i = 0; i < pos; i++)
    {
        // 由于头结点的存在，使得插入位置为pos时，插入位置的前驱结点为指向头结点指针往后移动pos次
        pCurrent = pCurrent->next;
    }
    // 暂存待删除结点的指针
    struct LinkNode * pDel = pCurrent->next;
    // 删除结点
    pCurrent->next = pDel->next;
    // 释放内存
    free(pDel);
    pDel = NULL;
    // 更新链表长度
    mylist->m_size--;
}

// 删除结点 -- 按值
void removebyValue(LinkList list, void *data, bool (*myComp)(void *, void *))
{
    if (list == NULL || data == NULL || myComp == NULL)
    {
         return;
    }
    struct LList * mylist = list;
    struct LinkNode * pPre = mylist->pHeader;
    struct LinkNode * pCur = pPre->next;

    for (int i = 0; i < mylist->m_size; i++)
    {
        if (myComp(pCur->data, data))
        {
            pPre->next = pCur->next;
            free(pCur);
            pCur = NULL;
            mylist->m_size--;
            break;
        }
        // 此次比较不成功
        pPre = pCur;
        pCur = pCur->next;
    }
}

// 清空链表
void clearLinkList(LinkList list)
{
    if (list == NULL)
    {
        return;
    }
    struct LList * mylist = list;
    struct LinkNode * pCurrent = mylist->pHeader;
    for (int i = 0; i < mylist->m_size; i++)
    {
        struct LinkNode *pNext = pCurrent->next;
        free(pCurrent);
        pCurrent = pNext;
    }
    mylist->pHeader->next = NULL;
    mylist->m_size = 0;
}

// 返回链表长度
int sizeLinkList(LinkList list)
{
    if (list == NULL)
    {
        return 0;
    }
    struct LList * mylist = list;
    return mylist->m_size;
}

// 销毁链表
void destoryLinkList(LinkList list)
{
    if (list == NULL)
    {
        return;
    }
    // 首先清空链表
    clearLinkList(list);
    // 释放结点数据
    free(list);
    list = NULL;
}