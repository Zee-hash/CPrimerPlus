/* parrot.c -- 使用fgets()和fputs()函数 */
#include <stdio.h>
#define MAXLINE 20
int main(void)
{
    char line[MAXLINE];

    // fgets()不丢弃最后的换行符
    while (fgets(line, MAXLINE, stdin) != NULL && line[0] != '\n')
    {
        fputs(line, stdout);
    }
    return 0;
}