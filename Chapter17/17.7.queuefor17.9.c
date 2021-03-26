/* queue.c -- Queue类型的实现 */
#include <stdio.h>
#include <stdlib.h>
#include "17.6.queuefor17.9.h"

// 局部函数
static void CopyToNode(Item item, Node *pn);
static void CopyToItem(Node *pn, Item *pi);

void InitializeQueue(Queue * pq)
{
    pq->front = NULL;
    pq->rear = NULL;
    pq->items = 0;
}

bool QueueIsFull(const Queue *pq)
{
    return pq->items == MAXQUEUE;
}

bool QueueIsEmpty(const Queue *pq)
{
    return pq->items == 0;
}

int QueueItemCount(const Queue *pq)
{
    return pq->items;
}

bool EnQueue(Item item, Queue *pq)
{
    Node *pnew;
    if(QueueIsFull(pq))
    {
        return false;
    }
    pnew = (Node *)malloc(sizeof(Node));
    if(pnew == NULL)
    {
        fprintf(stderr, "Unable to allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if(QueueIsEmpty(pq))
    {
        pq->front = pnew;
    }
    else
    {
        pq->rear->next = pnew;
    }
    pq->rear = pnew;
    pq->items++;
    return true;
}

bool DeQueue(Item *pitem, Queue *pq)
{
    Node *pt;
    if(QueueIsEmpty(pq))
    {
        return false;
    }
    CopyToItem(pq->front, pitem);
    pt = pq->front;
    pq->front = pq->front->next;
    free(pt);
    pq->items--;
    if(pq->items == 0)
    {
        // 列表被清空
        pq->rear = NULL;
    }
    return true;
}

void EmptyTheQueue(Queue *pq)
{
    Item dumy;
    while (!QueueIsEmpty(pq))
    {
        DeQueue(&dumy, pq);
    }
}

static void CopyToNode(Item item, Node *pn)
{
    pn->item = item;
}
static void CopyToItem(Node *pn, Item *pi)
{
    *pi = pn->item;
}