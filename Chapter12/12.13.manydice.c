/* manydice.c -- 多次掷骰子的模拟程序 */
// gcc 12.11.diceroll.c 12.13.manydice.c
#include <stdio.h>
#include <stdlib.h> // srand()
#include <time.h> // time()
#include "12.12.diceroll.h"

int main(void)
{
    int dice, roll;
    int sides;

    srand((unsigned int)time(0));
    printf("Enter the number of sides per die, 0 to stop.\n");
    while (scanf("%d", &sides) == 1 && sides > 0)
    {
        printf("How many dice?\n");
        scanf("%d", &dice);
        roll = roll_n_dice(dice, sides);
        printf("You have rolled a %d using %d %d-sided dice.\n", roll, dice, sides);
        printf("How many sides? Enter 0 to stop.\n");
    }
    printf("The rollom() function was called %d times.\n", roll_count);
    printf("GOOD FORTUNE TO YOU!\n");
    return 0;
}