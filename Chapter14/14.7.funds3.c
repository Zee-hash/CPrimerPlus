/* funds3.c -- 把结构作为参数传递 */
#include <stdio.h>
#define FUNDLEN 50
struct funds
{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};

double sum(const struct funds moolah);

int main(void)
{
    struct funds stan = {
        "Garlic-Melon Bank",
        3024.72,
        "Lucky's Savings and Loan",
        9237.11
    };

    printf("Stan has a total of  $%.2f.\n",
        sum(stan));
    return 0;
}   

double sum(const struct funds moolah)
{
    return (moolah.bankfund + moolah.savefund);
}