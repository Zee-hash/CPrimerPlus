/* compare.c -- 这个程序可以满足要求 */
#include <stdio.h>
#include <string.h>
#define ANSWER "Grant"
#define MAX 40
int main(void)
{
    char try[40];

    puts("Who is buried in Grant's tomb?");
    gets(try);
    while (strcmp(try, ANSWER))
    {
        puts("No, that's wrong. Try again. ");
        gets(try);
    }
    puts("That's right!");
    return 0;
}