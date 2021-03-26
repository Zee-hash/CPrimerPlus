/* skip2.c -- 跳过输入中的前两个整数 */
#include <stdio.h>
int main()
{
    int n;
    printf("Please enter three integer:\n");
    scanf("%*d %*d %d", &n);
    printf("The last integer was %d\n", n);
    return 0;
}