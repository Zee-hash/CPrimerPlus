/* friends.c -- 使用指向结构的指针 */
#include <stdio.h>
#define LEN 20

struct names
{
    char first[LEN];
    char last[LEN];
};

struct guy
{
    struct names handle;
    char favfood[LEN];
    char job[LEN];
    float income;
};

int main(void)
{
    struct guy fellow[2] = {
        {{"Ewen", "Villard"},
         "gralled salmon",
         "personality coach",
         58112.00},
        {{"Rodeny", "Swillbelly"},
         "tripe",
         "tabloid editor",
         232400.00}};
    struct guy * him;
    printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);
    him = &fellow[0];
    printf("address #1: %p #2: %p\n", him, him + 1);
    printf("him->income is $%.2f: (*him).income is $%.2f\n",
            him->income, (*him).income);
    him++;
    printf("him->favfood is %s: him->handle.last is %s\n",
            him->favfood, him->handle.last);
    return 0;
}