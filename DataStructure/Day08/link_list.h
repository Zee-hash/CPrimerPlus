#ifndef LINK_LIST_H_
#define LINK_LIST_H_
#include <stdbool.h>
struct LinkNode
{
    void *data;
    struct LinkNode *next;
};

struct LList
{
    struct LinkNode * pHeader;
    int m_size;
};

typedef void * LinkList;

// 初始化链表
LinkList initLinkList();

// 插入结点
void insertLinkList(LinkList list, int pos, void * data);

// 遍历链表
void foreachLinkList(LinkList list, void (*myPrint)(void *));

// 删除结点 -- 按位置
void removebyPosition(LinkList list, int pos);

// 删除结点 -- 按值
void removebyValue(LinkList list, void *data, bool (*myComp)(void *, void *));

// 清空链表
void clearLinkList(LinkList list);

// 返回链表长度
int sizeLinkList(LinkList list);

// 销毁链表
void destoryLinkList(LinkList list);

#endif