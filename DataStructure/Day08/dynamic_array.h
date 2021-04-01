#ifndef DYNAMIC_ARRAY_H_
#define DYNAMIC_ARRAY_H_
#include <stdbool.h>
typedef struct dynamic_array {
    void ** pAddr; // 指向真实存储在堆区的数据
    int m_capacity; // 数组的容量
    int m_size; // 数组的大小 
} DynamicArray;

// 动态数组初始化
DynamicArray * initDynamicArray(int capacity);

// 插入数据
void insertDynamicArray(DynamicArray * array, int pos, void * data);

// 遍历数组
void foreachDynamicArray(DynamicArray *array, void (*fun)(void *));

// 删除数组中的元素 -- 按位置
void removeDynamicArray(DynamicArray *array, int pos);

// 删除数组中的元素 -- 按值
void removeByValue(DynamicArray *array, void *data, bool (*myComp)(void *, void *));

// 销毁数组
void destroyDynamicArray(DynamicArray *array);
#endif