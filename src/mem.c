#include <stdio.h>
#include <init.h>


static int mem_init(void)
{
	puts("mem_init ok.");

	return 0;
}

sys_init(mem_init);
