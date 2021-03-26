/* altnames.c -- 可移植的数据类型名 */
#include <stdio.h>
#include <inttypes.h> // 支持可移植类型
int main(void)
{
	int16_t me16; // me16是一个16位有符号变量

	me16 = 4593;
	printf("First, assume int16_t is short: ");
	printf("me16 = %hd\n", me16);
	printf("Next, let's not make any assumptions.\n");
	printf("Instead, use a \"macro\" from inttypes.h: ");
	printf("me16 = %" PRId16 "\n", me16); // 实际运行的结果是 me16 = %d \n
	return 0;
}
