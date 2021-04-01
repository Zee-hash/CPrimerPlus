#include <stdio.h>
#include "ln_stack.h"

struct Person
{
    // 与之前不同的地方，若想隐藏，可使用void *
    struct StackNode *node;
    char name[64];
    int age;
};

int main(void)
{
    struct Person p1 = {NULL, "Person One", 20};
    struct Person p2 = {NULL, "Person Two", 22};
    struct Person p3 = {NULL, "Person Three", 21};
    struct Person p4 = {NULL, "Person Four", 23};
    struct Person p5 = {NULL, "Person Five", 22};

    Stack stack = initStack();
    push(stack, &p1);
    push(stack, &p2);
    push(stack, &p3);
    push(stack, &p4);
    push(stack, &p5);
    printf("Size of Stack: %d\n", size(stack));
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