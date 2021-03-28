/* name2.c -- 读取一个名字 */
// gcc -std=c99 11.5.name2.c

#include <stdio.h>
#define MAX 81
int main(void)
{
    char name[MAX];
    char *ptr;

    printf("Hi, what's your name?\n");
    // gets()函数已废弃使用，与之对应的puts()仍在使用中
    ptr = gets(name);
    printf("%s? Ah! %s!\n", name, ptr);
    return 0;
}