/* assert.c -- 使用assert.c */
#include <stdio.h>
#include <math.h>
#include <assert.h>
// gcc 16.16.assert.c -lm
int main(void)
{
    double x, y, z;
    puts("Enter a pair of numbers (0 0 to quit): ");
    while (scanf("%lf %lf", &x, &y) ==  2 &&
            (x != 0 || y != 0))
    {
        z = x * x - y * y;
        // assert()宏的作用为：标识出程序中某个条件应为真的关键位置，并在条件为假时
        // 终止该程序。如果assert()终止程序，那么它首先会显示失败的判断、包含该判断
        // 的文件名和行号
        assert(z >= 0);
        printf("answer is %f\n", sqrt(z));
        puts("Next pair of numbers: ");
    }
    puts("Done");
    return 0;
}