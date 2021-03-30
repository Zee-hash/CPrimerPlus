/* ifdef.c -- 使用条件编译 */
#include <stdio.h>
#define JUST_CHECK
#define LIMIT 4

int main(void)
{
    int i;
    int total = 0;

    for (i = 0; i < LIMIT; i++)
    {
        total += 2 * i * i + 1;
        // 可以用这种方法辅助调试程序
#ifdef JUST_CHECK
        printf("i = %d, running total = %d\n", i, total);
#endif
        printf("Grand total = %d\n", total);
        return 0;
    }
}