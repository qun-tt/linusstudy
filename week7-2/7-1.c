#include "./ch07.h"
static void __attribute__ ((constructor)) before_main()
{
	printf("------------Before Main-------------\n");
}

static void __attribute__ ((constructor)) after_main()
{
        printf("------------After Main-------------\n");
}

int main()
{
	printf("-----------Main Before-----------\n");
	return 0;
}
