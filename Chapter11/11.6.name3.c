/* name2.c -- 使用fgets()读取一个名字 */
#include <stdio.h>
#define MAX 81
int main(void)
{
    char name[MAX];
    char *ptr;

    printf("Hi, what's your name?\n");
    // fgets()会就输入中的换行存储到字符串中
    ptr = fgets(name, MAX, stdin);
    printf("%s? Ah! %s!\n", name, ptr);
    return 0;
}