/* doubincl.c -- 两次包含同一个文件 */
#include <stdio.h>
#include "16.10.names_st.h"
#include "16.10.names_st.h"

int main(void)
{
    names winner = {"Less", "Ismoor"};
    printf("The winner is %s %s.\n", winner.first, winner.last);
    return 0;
}