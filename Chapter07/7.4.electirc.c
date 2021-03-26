/* electric.c -- 计算用电账目 */
#include <stdio.h>
#define RATE1 0.12589 // 0-360kwh
#define RATE2 0.17901 // 360-680kwh
#define RATE3 0.20971 // >680kwh
#define BREAK1 360.0
#define BREAK2 680.0
#define BASE1 (RATE1 * BREAK1)                      //用电360时的费用
#define BASE2 (BASE1 + (RATE2 * (BREAK2 - BREAK1))) // 用电680时的费用

int main(void)
{
    double kwh;  // 用电的千瓦小时数
    double bill; // 费用

    printf("Please enter the kwh used.\n");
    scanf("%lf", &kwh); // lf是double类型说明符，Lf是long double类型说明符
    if (kwh <= BREAK1)
    {
        bill = RATE1 * kwh;
    }
    else if (kwh <= BREAK2)
    {
        bill = BASE1 + (RATE2 * (kwh - BREAK1));
    }
    else
    {
        bill = BASE2 + (RATE3 * (kwh - BREAK2));
    }
    printf("The charge for %.1f kwh is $%1.2f.\n", kwh, bill);
    return 0;
}
