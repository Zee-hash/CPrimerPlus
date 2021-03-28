/* forc99.c -- C99关于代码块的新规则 */
#include <stdio.h>
int main()
{
    int n = 10;

    printf("Initially, n = %d\n", n);
    // 语句若为循环或者if语句的一部分，即使没有使用{}，也认为是一个代码块
    for (int i = 0; i < 3; i++)
        printf("loop 1: n = %d\n", n);
    printf("After loop 1, n = %d\n", n);
    for (int i = 0; i < 3; i++)
    {
        printf("loop 2 index n = %d\n", n);
        int n = 30;
        printf("loop 2: n = %d\n", n);
        n++;
    }
    printf("After loop 2, n = %d\n", n);
    return 0;
}