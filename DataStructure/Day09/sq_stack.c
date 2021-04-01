#include "sq_stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 初始化栈
Stack initStack()
{
    struct SStack * stack = malloc(sizeof(struct SStack));
    if (stack == NULL)
    {
        return NULL;
    }
    // 清空数组的每个元素
    memset(stack->data, 0, sizeof(void *) * MAX);
    stack->m_size = 0;
    return stack;
}

// 入栈
void push(Stack stack, void * data)
{
    if (stack == NULL || data == NULL)
    {
        return;
    }
    struct SStack * mystack = stack;
    // 判满
    if (mystack->m_size == MAX)
    {
        return;
    }
    // 入栈
    mystack->data[mystack->m_size] = data;
    // 更新大小
    mystack->m_size++;
}

// 出栈
void pop(Stack stack)
{
    if (stack == NULL)
    {
        return;
    }
    if(stackIsEmpty(stack))
    {
        return;
    }
    // 执行出栈操作
    struct SStack * mystack = stack;
    // mystack->data[mystack->m_size-1] = NULL
    // 伪删除
    mystack->m_size--;
}

// 获取栈顶元素
void *top(Stack stack)
{
    if (stack == NULL)
    {
        return NULL;
    }
    struct SStack * mystack = stack;
    if (stackIsEmpty(stack))
    {
        return NULL;
    }
    return mystack->data[mystack->m_size - 1];
}

// 栈的大小
int size(Stack stack)
{
    if (stack == NULL)
    {
        return -1;
    }
    struct SStack * mystack = stack;
    return mystack->m_size;
}

// 判断栈是否为空
bool stackIsEmpty(Stack stack)
{
    if (stack == NULL)
    {
        return true;
    }
    
    struct SStack * mystack = stack;
    if (mystack->m_size <= 0)
    {
        return true;
    }
    return false;
}

// 销毁
void destroyStack(Stack stack)
{
    if (stack == NULL)
    {
        return;
    }
    free(stack);
    stack = NULL;
}