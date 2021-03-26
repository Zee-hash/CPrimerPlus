/* queue.h -- Queue的接口 */
#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdbool.h>

// 专为解决具体问题定义的Item
typedef struct item
{
    long arrive; // 一位顾客加入队列的时间
    int processtime; // 该顾客咨询时花费的时间
}Item;

#define MAXQUEUE 10
typedef struct node
{
    Item item;
    struct node * next;
}Node;
typedef struct queue
{
    Node *front; // 指向队列首项的指针
    Node *rear; // 指向队列尾项的指针
    int items; //队列中的项数
}Queue;

/**
 * 操  作：初始化队列
 * 前提条件：pd指向一个队列
 * 后置条件：队列被初始化为空
**/
void InitializeQueue(Queue * pq);

/**
 * 操  作：检查队列是否已满
 * 前提条件：pd指向已被初始化的队列
 * 后置条件：如果队列满，则返回true；否则返回false
**/
bool QueueIsFull(const Queue *pq);

/**
 * 操  作：检查队列是否为空
 * 前提条件：pd指向已被初始化的队列
 * 后置条件：如果队列空，则返回true；否则返回false
**/
bool QueueIsEmpty(const Queue *pq);

/**
 * 操  作：确定队列中的项数
 * 前提条件：pd指向已被初始化的队列
 * 后置条件：返回队列中的项数
**/
int QueueItemCount(const Queue *pq);

/**
 * 操  作：在队列末尾添加项
 * 前提条件：pd指向已被初始化的队列，item是要被添加在队列末尾的项
 * 后置条件：如果队列不空，item将被添加在队列的末尾，添加成功返回true；否则返回false
**/
bool EnQueue(Item item, Queue *pq);

/**
 * 操  作：从队列的开头删除项
 * 前提条件：pd指向已被初始化的队列
 * 后置条件：如果队列不空，队列首端的item将被拷贝到*pitem中，删除成功，返回true；
 *          如果删除后队列为空，则重置队列为空
 *          如果在出队前为空，则返回false
**/
bool DeQueue(Item *pitem, Queue *pq);

/**
 * 操  作：清空队列
 * 前提条件：pd指向已被初始化的队列
 * 后置条件：队列被清空
**/
void EmptyTheQueue(Queue *pq);

#endif