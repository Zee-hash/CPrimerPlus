#ifndef ADVANCED_LINK_LIST_H_
#define ADVANCED_LINK_LIST_H_
struct LinkNode 
{
    // 只维护指针域，数据提供一份存放地址的空间。
    struct LinkNode *next;
};

struct LList
{
    struct LinkNode * pHeader;
    int m_size;
};

typedef void *LinkList;

// 初始化链表
LinkList initLinkList();

// 插入
void insertLinkList(LinkList list, int pos, void *data);

// 遍历链表
void foreachLinkList(LinkList list, void (*myPrint)(void *));

// 删除 -- 按位置
void removeByIndex(LinkList list, int pos);

// 销毁
void destoryLinkList(LinkList list);

#endif