/* misuse.c -- 不正确地使用函数 */
#include <stdio.h>
int imax(); // 旧式声明
int main(void)
{
    /**
     * 对于执行结果的说明：
     * 函数执行时，调用函数首先把参数放在一个称为堆栈stack的临时存储区，然后
     * 被调函数从堆栈中读取这些参数。但是这两个过程并没有相互协调的进行。调用
     * 函数根据调用过程的实际参数确定需要传递的数值类型，但是被调函数是根据其
     * 形式参数的类型进行数据读取的。
    **/ 
    printf("The maximum of %d and %d is %d.\n", 3, 5, imax(3));
    printf("The maximum of %d and %d is %d.\n", 3, 5, imax(3.0, 5.0));
    return 0;
}

int imax(n, m)
int n, m;
{
    int max;
    if (n > m)
    {
        max = n;
    }
    else
    {
        max = m;
    }
    return max;
}