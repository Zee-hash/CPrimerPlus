/* nono.c -- 不要效仿这个程序 */
#include <stdio.h>
int main(void)
{
    char side_a[] = "SIDE A";
    char dont[] = {'W', 'O', 'W', '!'};
    char side_b[] = "SIDE B";

    // dont最后没有空字符，不是字符串
    puts(dont); 
    return 0;
}