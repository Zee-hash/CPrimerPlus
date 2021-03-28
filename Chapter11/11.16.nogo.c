/* nogo.c -- 这个程序能满足要求吗？ */
#include <stdio.h>
#define ANSWER "Grant"
int main(void)
{
    char try[40];

    puts("Who is buried in Grant's tomb?");
    gets(try);
    // 不满足要求，比较的实际上是两个地址值
    while (try != ANSWER)
    {
        puts("No, that's wrong. Try again. ");
        gets(try);
    }
    puts("That's right!");
    return 0;
}