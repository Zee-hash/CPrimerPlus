/* flags.c -- 一些格式标志的使用示例 */
#include <stdio.h>
int main(void)
{
    printf("%x %X %#x\n", 31, 31, 31);
    printf("**%d**% d**% d**\n", 42, 42, -42);
    printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6); // 最后由于0和精度说明符同时出现，所以0标志被忽略。
    return 0;
}