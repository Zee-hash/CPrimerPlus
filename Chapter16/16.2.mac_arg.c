/* max_arg.c -- 带有参数的宏 */
#include <stdio.h>
#define SQUARE(X) X*X
#define PR(X) printf("The result is %d.\n", X);

int main(void)
{
    int x = 4;
    int z;

    printf("x = %d\n", x);
    z = SQUARE(x);
    printf("Evaluating SQUARE(X): ");
    PR(z);
    z = SQUARE(2);
    printf("Evaluating SQUARE(2): ");
    PR(z);
    // x+2*x+2 4+8+2
    printf("Evaluating SQUARE(x+2): ");
    PR(SQUARE(x+2));
    // 100/2*2
    printf("Evaluating 100/SQUARE(2): ");
    PR(100/SQUARE(2));
    printf("x is %d.\n", x);
    // ++x*++x 不同编译器可能有不同的结果
    printf("Evaluating SQUARE(++x): ");
    PR(SQUARE(++x));
    printf("After incrementing, x is %d.\n", x);
    return 0;
}