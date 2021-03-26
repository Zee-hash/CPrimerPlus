/* sizeof.c -- 使用sizeof运算符 */
#include <stdio.h>
// 使用C99新增的%zd转换说明符
int main(void)
{
    int n = 0;
    size_t intsize;
    intsize = sizeof(int);
    printf("n = %d, n has %zd bytes; all ints have %zd bytes.\n",
        n, sizeof n, intsize);
    return 0;
}