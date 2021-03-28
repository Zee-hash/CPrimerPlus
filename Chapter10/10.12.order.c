/* order.c -- 指针运算的优先级 */
#include <stdio.h>
int data[2] = {100, 200};
int moredate[2] = {300, 400};
int main(void)
{
    int *p1, *p2, *p3;
    p1 = p2 = data;
    p3 = moredate;

    // 一元运算符*和++具有相同的优先级，但它在结合时是从右往左进行的。
    printf("  *p1 = %d,   *p2 = %d,     *p3 = %d\n", 
            *p1, *p2, *p3);
    printf("*p1++ = %d, *p2++ = %d, (*p3)++ = %d\n",
            *p1++, *p2++, (*p3)++);
     printf("  *p1 = %d,   *p2 = %d,     *p3 = %d\n", 
            *p1, *p2, *p3);
    return 0;
}