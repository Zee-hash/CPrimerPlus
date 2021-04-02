#ifndef SQ_QUEUE_H_
#define SQ_QUEUE_H_

#define MAX 1024
typedef void * Queue;
// 初始化队列
Queue initQueue();
// 入队
void enQueue(Queue queue, void *data);
// 出队
void deQueue(Queue queue);
// 返回队首元素
void *front(Queue queue);
// 返回队尾元素
void *back(Queue queue);
// 返回队列大小
int size(Queue queue);
// 销毁
void destroyQueue(Queue queue);
#endif