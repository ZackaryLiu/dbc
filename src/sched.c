#include <stdio.h>
#include <init.h>


static int sched_init(void)
{
	puts("sched_init ok.");

	return 0;
}

sys_init(sched_init);
