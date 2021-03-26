/* print2.c -- printf()的更多属性 */
#include <stdio.h>
int main()
{
	unsigned int un = 3000000000; // int 为32位
	short end = 200; // short 为16位
	long big = 65537;
	long long verybig = 12345678908642;
	printf("un = %u and not %d\n", un, un);
	printf("end = %hd and %d\n", end, end);
	printf("big = %ld and not %hd\n", big, big);
	printf("verybig = %lld and not %ld\n", verybig, verybig);

	return 0;
}

