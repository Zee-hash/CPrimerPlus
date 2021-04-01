#include <stdio.h>
#include <string.h>
#include "dynamic_array.h"


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
    // 创建动态数组
    DynamicArray * array = initDynamicArray(5);
    struct Person p1 = {"Person One", 20};
    struct Person p2 = {"Person Two", 22};
    struct Person p3 = {"Person Three", 21};
    struct Person p4 = {"Person Four", 23};
    struct Person p5 = {"Person Five", 22};
    struct Person p6 = {"Person Six", 21};
   
    printf("Capacity: %d, Size: %d\n", array->m_capacity, array->m_size);
    
    insertDynamicArray(array, 0, &p1);
    insertDynamicArray(array, 0, &p2);
    insertDynamicArray(array, 0, &p3);
    insertDynamicArray(array, 2, &p4);
    insertDynamicArray(array, 1, &p5);
    printf("Capacity: %d, Size: %d\n", array->m_capacity, array->m_size);
    insertDynamicArray(array, 0, &p6);
    printf("Capacity: %d, Size: %d\n", array->m_capacity, array->m_size);
    // 635241
    printf("Before removing...\n");
    foreachDynamicArray(array, printPerson);
    removeDynamicArray(array, 1);
    printf("After removing...\n");
    foreachDynamicArray(array, printPerson);

    struct Person temp = {"Person Five", 22};
    removeByValue(array, &temp, compPerson);
    printf("After removing...\n");
    foreachDynamicArray(array, printPerson);

    // 销毁数组
    destroyDynamicArray(array);
}

int main(void)
{
    test01();
    return 0;
}