/* repeat.c -- 带有参数的main()函数 */
#include <stdio.h>
int main(int argc, char *argv[])
{
    int count;

    printf("The command line had %d arguments: \n", argc - 1);
    for (count = 1; count < argc; count++)
    {
        printf("%d: %s\n", count, argv[count]);
    }
    printf("\n");
    return 0;
}