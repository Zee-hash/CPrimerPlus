#include <stdio.h>
#include <string.h>
#include "advanced_link_list.h"

struct Person
{
    // 与之前不同的地方，若想隐藏，可使用void *
    struct LinkNode * node;
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
    LinkList * mylist = initLinkList();
    if (mylist == NULL)
    {
        return;
    }
    struct Person p1 = {NULL, "Person One", 20};
    struct Person p2 = {NULL, "Person Two", 22};
    struct Person p3 = {NULL, "Person Three", 21};
    struct Person p4 = {NULL, "Person Four", 23};
    struct Person p5 = {NULL, "Person Five", 22};

    insertLinkList(mylist, 0, &p1);
    insertLinkList(mylist, 0, &p2);
    insertLinkList(mylist, 0, &p3);
    insertLinkList(mylist, 1, &p4);
    insertLinkList(mylist, 5, &p5);
    // 34215
    foreachLinkList(mylist, printPerson);
    
    removeByIndex(mylist, 0);
    // 4215
    printf("------------------------\n");
    foreachLinkList(mylist, printPerson);

    destroyLinkList(mylist);
}

int main(void)
{
    test01();
    return 0;
}