#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "sq_queue.h"

// gcc sq_queue.c sq_queue_test.c dynamic_array.c

struct Person
{
    char name[64];
    int age;
};

// 用于打印
void printPerson(void *p)
{
    struct Person *person = p;
    printf("Name: %s; Age: %d\n", person->name, person->age);
}
// 用于比较
bool compPerson(void *p1, void *p2)
{
    struct Person * person1 = p1;
    struct Person * person2 = p2;
    if (strcmp(person1->name, person2->name)== 0 && person1->age == person2->age)
    {
        return true;
    }
    return false;
}
void test01()
{
    // 创建
    Queue myqueue = initQueue();
    struct Person p1 = {"Person One", 20};
    struct Person p2 = {"Person Two", 22};
    struct Person p3 = {"Person Three", 21};
    struct Person p4 = {"Person Four", 23};
    struct Person p5 = {"Person Five", 22};
    
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