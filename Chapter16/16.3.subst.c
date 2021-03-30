/* subst.c -- 在字符串中进行替换 */
#include <stdio.h>
#define PSQX(x) printf("The square of " #x " is %d.\n", ((x)*(x)))
int main(void)
{
    int y = 5;
    // 调用宏时，用“y”代替 #x
    PSQX(y);
    // 调用宏时，用"2 + 4" 代替 #x
    PSQX(2 + 4);
    return 0;
}