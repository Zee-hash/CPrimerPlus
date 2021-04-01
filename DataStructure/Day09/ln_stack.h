#ifndef LN_STACK_H_
#define LN_STACK_H_

#include <stdbool.h>
struct StackNode
{
    struct StackNode *next;
};

struct LStack
{
    struct StackNode *pHeader;
    int m_size;
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