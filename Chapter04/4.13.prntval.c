/* prntval.c -- printf()的返回值 */
#include <stdio.h>
int main(void)
{
    int bph2o = 212;
    int rv;
    // 注意，该返回值针对所有字符，包括空格和不可见的换行符。
    rv =  printf("%d F is water's boiling point.\n", bph2o);
    printf("The printf() function printed %d characters.\n", rv);
    return 0;
}