/* checking.c -- 输入确认 */
#include <stdio.h>
#include <stdbool.h>
// 确认输入了一个数
int get_int(void);
// 确认输入的上下界是否有效
bool bad_limits(int begin, int end, int low, int high);
// 计算从a到b之间的整数的平方和
double sum_squares(int a, int b);
int main(void)
{
    const int MIN = -1000;// 取值范围
    const int MAX = +1000;// 取值范围
    int start; // 计算开始下界
    int stop; // 计算结束上界
    double answer;

    printf("This program computes the sum of the squares of ");
    printf("integets in a range.\nThe lower bound should not ");
    printf("be less than -1000 and\nthe upper bound should not ");
    printf("be more than +1000.\nEnter the limits (enter 0 for ");
    printf("both limits to quit):\nlower limit: ");
    start = get_int();
    printf("upper limit: ");
    stop = get_int();
    while (start != 0 && stop != 0)
    {
        if (bad_limits(start, stop, MIN, MAX))
        {
            printf("Please try again.\n");
        }
        else
        {
            answer = sum_squares(start, stop);
            printf("The sum of the squares of the integers from ");
            printf("form %d to %d is %g\n", start, stop, answer);
        }
        printf("Enter the limits (enter 0 for both limits to quit): \n");
        printf("lower limit: ");
        start = get_int();
        printf("upper limit: ");
        stop = get_int();
    }
    printf("Done.\n");
    return 0;
}

int get_int(void)
{
    int input;
    char ch;
    while (scanf("%d", &input) != 1)
    {
        while((ch = getchar()) != '\n')
        {
            // 剔除错误的输入
            putchar(ch);
        }
        printf(" is not an integer.\nPlease enter an ");
        printf("integer value, such as 25, -178, or 3: ");
    }
    return input;
}

double sum_squares(int a, int b)
{
    double total = 0.0;
    int i;

    for (i = a; i <= b; i++)
    {
        total += i * i;
    }
    return total;
}

bool bad_limits(int begin, int end, int low, int high)
{
    bool not_good = false;

    if (begin > end)
    {
        printf("%d isn't smaller than %d.\n", begin, end);
        not_good = true;
    }
    if (begin < low || end < low)
    {
        printf("Values must be %d or greater.\n", low);
        not_good = true;
    }
    if (begin > high || end > high)
    {
        printf("Values must be %d or less.\n", high);
        not_good = true;
    }
    return not_good;
}