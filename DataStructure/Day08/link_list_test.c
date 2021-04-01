#include <stdio.h>
#include <string.h>
#include "link_list.h"

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
    LinkList mylist = initLinkList();
    struct Person p1 = {"Person One", 20};
    struct Person p2 = {"Person Two", 22};
    struct Person p3 = {"Person Three", 21};
    struct Person p4 = {"Person Four", 23};
    struct Person p5 = {"Person Five", 22};
    struct Person p6 = {"Person Six", 21};

    insertLinkList(mylist, 0, &p1);
    insertLinkList(mylist, 0, &p2);
    insertLinkList(mylist, 1, &p3);
    insertLinkList(mylist, 0, &p4);
    insertLinkList(mylist, 1, &p5);
    insertLinkList(mylist, 100, &p6);
    // 452316
    foreachLinkList(mylist, printPerson);

    // remove "Person four"
    printf("--------------------------------------\n");
    removebyPosition(mylist, 0);
    foreachLinkList(mylist, printPerson);
    // remove "Person one"
    struct Person temp = {"Person One", 20};
    removebyValue(mylist, &temp, compPerson);
    printf("--------------------------------------\n");
    foreachLinkList(mylist, printPerson);
    printf("The length of the LinkList: %d\n", sizeLinkList(mylist));
    // 清空
    clearLinkList(mylist);
    printf("--------------------------------------\n");
    foreachLinkList(mylist, printPerson);

    printf("The length of the LinkList: %d\n", sizeLinkList(mylist));
    destoryLinkList(mylist);
}

int main(void)
{
    test01();
    return 0;
}