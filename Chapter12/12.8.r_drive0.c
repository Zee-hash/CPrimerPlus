/* r_drive0.c -- 测试rand0()函数 */
// gcc 12.7.rand0.c 12.8.r_drive0.c
#include <stdio.h>
extern int rand0(void);

int main(void)
{
    for (int count = 0; count < 5; count++)
    {
        printf("%hd\n", rand0());
    }
    return 0;
}
