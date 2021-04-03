#ifndef SQ_STACK_H_H
#define SQ_STACK_H_H
#include <stdbool.h>
#define MAX 1024

struct SStack
{
    // 顺序栈
    void *data[MAX];
    int m_size; // 栈的大小
};

typedef void * Stack;

// 初始化栈
Stack initStack();

// 入栈
void push(Stack stack, void * data);

// 出栈
void pop(Stack stack);

// 获取栈顶元素
void *top(Stack stack);

// 栈的大小
int size(Stack stack);

// 判断栈是否为空
bool stackIsEmpty(Stack stack);

// 销毁
void destroyStack(Stack stack);

#endif