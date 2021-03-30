/* glue.c -- 使用##运算符 */
#include <stdio.h>
#define XNAME(n) x##n 
#define PRINT_XN(n) printf("x" #n " = %d\n", x##n)

int main(void)
{
    // int x1 = 14;
    int XNAME(1) = 14;
    int XNAME(2) = 20;
    // printf("x" "1" " = %d\n", x1)
    PRINT_XN(1);
    PRINT_XN(2);
    return 0;
}