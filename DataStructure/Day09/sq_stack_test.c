#include <stdio.h>
#include "sq_stack.h"

// 宏
#define STRCAT(X) (p##X)

struct Person
{
    char name[64];
    int age;
};

int main(void)
{
    struct Person p1 = {"Person One", 20};
    struct Person p2 = {"Person Two", 22};
    struct Person p3 = {"Person Three", 21};
    struct Person p4 = {"Person Four", 23};
    struct Person p5 = {"Person Five", 22};

    Stack stack = initStack();
    push(stack, &p1);
    push(stack, &p2);
    push(stack, &p3);
    push(stack, &p4);
    push(stack, &p5);

    while (stackIsEmpty(stack) == 0)
    {
        // 查看栈顶元素
        struct Person * p = top(stack);
        printf("Name :%s, Age: %d\n", p->name, p->age);
        // 出栈
        pop(stack);
        printf("Size of Stack: %d\n", size(stack));
    }
    destroyStack(stack);
}