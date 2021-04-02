#include "ln_queue.h"
#include <stdlib.h>
#include <stdio.h>
// 初始化队列
Queue initQueue()
{
    struct lQueue * myqueue = malloc(sizeof(struct lQueue));
    if (myqueue == NULL)
    {
        return NULL;
    }
    myqueue->pHeader = malloc(sizeof(struct Node));
    myqueue->pHeader->next = NULL;
    myqueue->pTail = myqueue->pHeader;
    myqueue->m_size = 0;
}
// 入队
void enQueue(Queue queue, void *data)
{
    if (queue == NULL || data == NULL)
    {
        return;
    }
    struct lQueue * myqueue = queue;
    // 取出用户数据的前四个字节
    struct Node * mynode = data;
    // 插入新的结点
    myqueue->pTail->next = mynode;
    mynode->next = NULL;
    // 移动尾指针
    myqueue->pTail = mynode;
    // 大小更新
    myqueue->m_size++;
}
// 出队
void deQueue(Queue queue)
{
    if (queue == NULL)
    {
        return;
    }
    if (size(queue) == 0)
    {
        return;
    }
    struct lQueue * myqueue = queue;
    if (size(queue) == 1)
    {
        // 仅剩一个结点时
        myqueue->pHeader->next = NULL;
        myqueue->pTail = myqueue->pHeader;
        myqueue->m_size = 0;
        return;
        
    }
    // 第一个有效结点
    struct Node *pfirst =  myqueue->pHeader->next;
    myqueue->pHeader->next = pfirst->next;
    // 不用free
    myqueue->m_size--;
}
// 返回队首元素
void *front(Queue queue)
{
    if (queue == NULL)
    {
        return NULL;
    }
    if (size(queue) == 0)
    {
        return NULL;
    }
    struct lQueue * myqueue = queue;
    return myqueue->pHeader->next;
}
// 返回队尾元素
void *back(Queue queue)
{
    if (queue == NULL)
    {
        return NULL;
    }
    if (size(queue) == 0)
    {
        return NULL;
    }
    struct lQueue * myqueue = queue;
    return myqueue->pTail;
}
// 返回队列大小
int size(Queue queue)
{
    if (queue == NULL)
    {
        return -1;
    }
   
    struct lQueue * myqueue = queue;
    return myqueue->m_size;
}
// 销毁
void destroyQueue(Queue queue)
{
    if (queue == NULL)
    {
        return;
    }
    free(queue);
}