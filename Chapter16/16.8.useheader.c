/* useheader.c -- 使用names_st结构 */
#include <stdio.h>
#include "16.6.names.h"
// gcc 16.7.names.c 16.8.useheader.c
int main(void)
{
    names candidate;
    get_names(&candidate);
    printf("Let's welcome ");
    show_names(&candidate);
    printf(" to this program!\n");
    return 0;
}