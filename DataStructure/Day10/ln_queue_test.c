#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "ln_queue.h"


struct Person
{
    void * node;
    char name[64];
    int age;
};

// 用于打印
void printPerson(void *p)
{
    struct Person *person = p;
    printf("Name: %s; Age: %d\n", person->name, person->age);
}

void test01()
{
    // 创建
    Queue myqueue = initQueue();
    struct Person p1 = {NULL, "Person One", 20};
    struct Person p2 = {NULL, "Person Two", 22};
    struct Person p3 = {NULL, "Person Three", 21};
    struct Person p4 = {NULL, "Person Four", 23};
    struct Person p5 = {NULL, "Person Five", 22};
    
    enQueue(myqueue, &p1);
    enQueue(myqueue, &p2);
    enQueue(myqueue, &p3);
    enQueue(myqueue, &p4);
    enQueue(myqueue, &p5);
    
    while (size(myqueue))
    {
        printf("current front: ");
        printPerson(front(myqueue));
        printf("size of queue: %d\n\n", size(myqueue));
        deQueue(myqueue);
    }
    printf("size of queue: %d\n", size(myqueue));
}

int main(void)
{
    test01();
    return 0;
}