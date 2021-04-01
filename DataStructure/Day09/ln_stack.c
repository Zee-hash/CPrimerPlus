#include "ln_stack.h"
#include <stdio.h>
#include <stdlib.h>
// 初始化栈
Stack initStack()
{
    struct LStack * mystack = malloc(sizeof(struct LStack));
    if (mystack == NULL)
    {
        return NULL;
    }
    // !!!!!
    mystack->pHeader = malloc(sizeof(struct StackNode));
    mystack->pHeader->next = NULL;
    mystack->m_size = 0;
    return mystack;
}

// 入栈
void push(Stack stack, void * data)
{
    if (stack == NULL || data == NULL)
    {
        return;
    }
    // 入栈即头插
    struct LStack *mystack = stack;
    // 获取用户数据地址
    struct StackNode * mynode = data;
    // 插入结点
    mynode->next = mystack->pHeader->next;
    mystack->pHeader->next = mynode;
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
    if (size(stack) == 0)
    {
        return;
    }
    struct LStack * mystack = stack;
    struct StackNode *pFirst = mystack->pHeader->next;
    mystack->pHeader->next = pFirst->next;
    // 不用释放pFirst指向的用户数据！！！！
    mystack->m_size--;
}

// 获取栈顶元素
void *top(Stack stack)
{
    if (stack == NULL)
    {
        return NULL;
    }
    if (stackIsEmpty(stack))
    {
        return NULL;
    }
    struct LStack * mystack = stack;
    return mystack->pHeader->next;
}

// 栈的大小
int size(Stack stack)
{
    if (stack == NULL)
    {
        return -1;
    }
    struct LStack *mystack = stack;
    return mystack->m_size;
}

// 判断栈是否为空
bool stackIsEmpty(Stack stack)
{
    if (stack == NULL)
    {
        return true;
    }
    
    struct LStack * mystack = stack;
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
