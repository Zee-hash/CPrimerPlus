/* variadic.c -- 可变宏 */
#include <stdio.h>
// gcc 16.5.variadic.c -lm
#include <math.h>
// 省略号只能代替最后的宏参数
#define PR(X, ...) printf("Message " #X ": " __VA_ARGS__)
int main(void)
{
    double x = 48;
    double y;

    y = sqrt(x);
    // printf("Message " "1" ": " "x = %g\n", x);
    PR(1, "x = %g\n", x);
    PR(2, "x = %.2f, y = %.4f\n", x, y);
    return 0;
}