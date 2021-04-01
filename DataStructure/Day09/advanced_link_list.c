#include "advanced_link_list.h"
#include <stdlib.h>
#include <stdio.h>
// 初始化链表
LinkList initLinkList()
{
    struct LList * mylist = malloc(sizeof(struct LList));
    if (mylist == NULL)
    {
        return NULL;
    }
    mylist->pHeader = malloc(sizeof(struct LinkNode));
    mylist->pHeader->next = NULL;
    mylist->m_size = 0;
    return mylist;
}

// 插入
void insertLinkList(LinkList list, int pos, void *data)
{
    if (list == NULL || data == NULL)
    {
        return;
    }
    struct LList * mylist = list;
    if (pos < 0 || pos > mylist->m_size)
    {
        // 无效位置尾插
        pos = mylist->m_size;
    }
    // 将用户的数据前四个字节转为LinkNode类型
    struct LinkNode * myNode = data;
    // printf("data address : %p\n", myNode);
    struct LinkNode * pCurrent = mylist->pHeader;
    for (int i = 0; i < pos; i++)
    {
        pCurrent = pCurrent->next;
    }
    //pCurrent当前之前插入位置的前驱
    myNode->next = pCurrent->next;
    pCurrent->next = myNode;
    mylist->m_size++;
}

// 遍历链表
void foreachLinkList(LinkList list, void (*myPrint)(void *))
{
    if (list == NULL || myPrint == NULL)
    {
        return;
    }
    struct LList * mylist = list;
    // 第一个有效数据
    struct LinkNode *pCurrent = mylist->pHeader->next;
    for (int i = 0; i < mylist->m_size; i++)
    {
        myPrint(pCurrent);
        pCurrent = pCurrent->next;
    }
}

// 删除 -- 按位置
void removeByIndex(LinkList list, int pos)
{
    if (list == NULL)
    {
         return;
    }
    struct LList * mylist = list;
    if(pos < 0 || pos > mylist->m_size - 1)
    {
        return;
    }
    struct LinkNode *pCurrent = mylist->pHeader;
    for (int i = 0; i < pos; i++)
    {
        pCurrent = pCurrent->next;
    }
    struct LinkNode *pDel = pCurrent->next;
    pCurrent->next = pDel->next;
    // 此时的数据释放由用户自己管理，如果free()会释放用户维护的数据域!!!!!
    //free(pDel);
    mylist->m_size--;
}

// 销毁
void destoryLinkList(LinkList list)
{
    if (list == NULL)
    {
        return;
    }
    // 只需要释放掉指针即可
    
    free(list);
    list = NULL;
}