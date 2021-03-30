/* varargs.c -- 使用可变个数的参数 */
#include <stdio.h>
#include <stdarg.h>
double sum(int, ...);
int main(void)
{
    double s, t;

    s = sum(3, 1.1, 2.5, 13.3);
    t = sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1);
    printf("return value for "
           "sum(3, 1.1, 2.5, 13.3): %g\n",
           s);
    printf("return value for "
           "sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1): %g\n",
           t);

    return 0;
}

double sum(int lim, ...)
{
    // 声明用于存放参数的变量
    va_list ap;
    double tot = 0;
    int i;
    // 把ap初始化为参数列表
    va_start(ap, lim);
    for (i = 0; i < lim; i++)
    {
        // 访问参数，执行一次取出一个参数
        tot += va_arg(ap, double);
    }
    // 清理工作
    va_end(ap);
    return tot;
}