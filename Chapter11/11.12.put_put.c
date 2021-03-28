/* put_put.c -- 用户自定义的输出函数 */
#include <stdio.h>
void put1(const char *);
int put2(const char *);

int main(void)
{
    put1("If I's as much money");
    put1(" as I could spend, \n");
    printf("I count %d characaters.\n",
            put2("I never would cry old chairs to meng."));
    return 0;
}

void put1(const char * string)
{
    while (*string)
    {
        putchar(*string++);
    }
}

int put2(const char *string)
{
    int count = 0;
    while (*string)
    {
        putchar(*string++);
        count++;
    }
    // 不统计换行符
    putchar('\n');
    return count;
}

