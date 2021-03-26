/* strings.c -- 字符串的格式化 */
#include <stdio.h>
#define BLURB "Authentic imitation!"
int main(void)
{
    printf("/%2s/\n", BLURB);
    printf("/%24s/\n", BLURB);
    // 格式说明符中的.5告诉printf()只打印5个字符。
    printf("/%24.5s/\n", BLURB);
    printf("/%-24.5s/\n", BLURB);
    return 0;
}