/* copy2.c -- strcpy()示例程序 */
#include <stdio.h>
#include <string.h>
#define WORDS "beast"
#define SIZE 40
int main(void)
{
    char *orig = WORDS;
    char copy[SIZE] = "Be the best that you can be.";
    char *ps;

    puts(orig);
    puts(copy);
    // 返回第一个参数的地址
    ps = strcpy(copy + 7, orig);
    puts(copy);
    puts(ps);
    return 0;
}