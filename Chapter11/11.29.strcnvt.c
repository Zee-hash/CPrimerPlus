/* strcnvt.c -- 尝试使用strtol()函数 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char number[30];
    char *end;
    long value;

    puts("Enter a number (empt line to quit): ");
    while (gets(number) && number[0] != '\0')
    {
        // str	-	pointer to the null-terminated byte string to be interpreted
        // str_end	-	pointer to a pointer to character.
        // base	-	base of the interpreted integer value
        value = strtol(number, &end, 10);
        printf("value: %ld, stopped at %s (%d)\n", value, end, *end);
        value = strtol(number, &end, 16);
        printf("value: %ld, stopped at %s (%d)\n", value, end, *end);
        puts("Next number: ");
    }
    puts("Bye!\n");
    return 0;
}