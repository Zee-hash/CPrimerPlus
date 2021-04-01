#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memcpy()
#include "dynamic_array.h"


// 动态数组初始化
DynamicArray * initDynamicArray(int capacity)
{
    if (capacity <= 0)
    {
        return NULL;
    }
    DynamicArray * array = malloc(sizeof(DynamicArray));
    if (array == NULL)
    {
        return NULL;
    }
    // 设置其他属性
    array->pAddr = malloc(sizeof(void *) * capacity);
    array->m_capacity = capacity;
    array->m_size = 0;
    return array;
}

// 插入数据
void insertDynamicArray(DynamicArray * array, int pos, void * data)
{
    // pos从开始
    if (array == NULL || data == NULL)
    {
        return ;
    }
    if (pos < 0 || pos > array->m_size)
    {
        // 无效的位置，强制尾插
        pos = array->m_size;
    }
    // 判断是否已经满载
    if (array->m_size >= array->m_capacity)
    {
        // 申请一个更大的空间
        int newCapacity = array->m_capacity * 2;
        void ** newAddr = malloc(sizeof(void *) * newCapacity);
        // 拷贝原来的数据，此时m_size == m_capacity
        memcpy(newAddr, array->pAddr, sizeof(void *) * array->m_size);
        // 释放原有空间
        free(array->pAddr);
        // 更改指针的指针
        array->pAddr = newAddr;
        array->m_capacity = newCapacity;
    }
    // 插入新的数据元素
    // 写的时候用了size_t类型，使得当m_size - 1 = -1时出现错误！！！！！
    for (int i = array->m_size - 1; i >= pos; i--)
    {
        // 往后移动
        array->pAddr[i+1] = array->pAddr[i]; 
    }
    // 将数据放到最终位置
    array->pAddr[pos] = data;
    // 更新大小
    array->m_size++;
}

// 遍历数组
void foreachDynamicArray(DynamicArray *array, void (*myForeach)(void *))
{
    if (array == NULL)
    {
        return;
    }
    if (myForeach == NULL)
    {
        return;
    }
    
    for (size_t i = 0; i < array->m_size; i++)
    {
        myForeach(array->pAddr[i]); // 由用户自己实现打印函数
    }
}

// 删除数组中的元素
void removeDynamicArray(DynamicArray *array, int pos)
{
    if (array == NULL)
    {
        return;
    }
    if (pos < 0 || pos > array->m_size - 1)
    {
        // 无效的位置
        return;
    }
    // 逻辑上的删除，实际上空间不释放
    for (int i = pos; i < array->m_size; i++)
    {
        array->pAddr[i] = array->pAddr[i+1];
    }
    array->m_size--;
}

// 删除数组中的元素 -- 按值
void removeByValue(DynamicArray *array, void *data, bool (*myComp)(void *, void *))
{
    if (array == NULL || data == NULL)
    {
        return;
    }
    for (int i = 0; i < array->m_size; i++)
    {
        // 实际比较的类型交给用户自己来实现，因此需要多加一个参数
        if(myComp(array->pAddr[i], data))
        {
            // 找到，删除
            removeDynamicArray(array, i);
            break;
        }
    }
}

// 销毁数组
void destroyDynamicArray(DynamicArray *array)
{
    if (array == NULL)
    {
        return;
    }
    if (array->pAddr != NULL)
    {
        free(array->pAddr);
    }
    free(array);
    array = NULL;
}