/* name1.c -- 读取一个名字 */
#include <stdio.h>
#define MAX 81
int main(void)
{
    char name[MAX];
    printf("Hi, what's your name?\n");
    gets(name);
    printf("Nice name, %s.\n", name);
    return 0;
}