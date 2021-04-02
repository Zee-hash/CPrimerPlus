#include "sq_queue.h"
#include <stdio.h>
// 使用动态数组来实现队列
#include "dynamic_array.h"
// 初始化队列
Queue initQueue()
{
    DynamicArray * myqueue = initDynamicArray(MAX);
    return myqueue;
}
// 入队
void enQueue(Queue queue, void *data)
{
    if (queue == NULL || data == NULL)
    {
        return;
    }
    DynamicArray * myqueue = queue;
    if (myqueue->m_size == MAX)
    {
        return;
    }
    // 传入大小，即尾插
    insertDynamicArray(myqueue, myqueue->m_size, data);
}
// 出队
void deQueue(Queue queue)
{
    if (queue == NULL)
    {
        return;
    }
    DynamicArray * myqueue = queue;
    if (myqueue->m_size == 0)
    {
        return;
    }
    removeDynamicArray(myqueue, 0);
}
// 返回队首元素
void *front(Queue queue)
{
    if (queue == NULL)
    {
        return NULL;
    }
    DynamicArray * myqueue = queue;
    return myqueue->pAddr[0];
}
// 返回队尾元素
void *back(Queue queue)
{
    if (queue == NULL)
    {
        return NULL;
    }
    DynamicArray * myqueue = queue;
    return myqueue->pAddr[myqueue->m_size-1];
}
// 返回队列大小
int size(Queue queue)
{
    if (queue == NULL)
    {
        return -0;
    }
    DynamicArray * myqueue = queue;
    return myqueue->m_size;
}
// 销毁
void destroyQueue(Queue queue)
{
    if (queue == NULL)
    {
        return ;
    }
    destroyDynamicArray(queue);
}