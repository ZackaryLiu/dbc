#include <stdio.h>
#include <init.h>
#include <sys/sysinfo.h>

static int print_sys_info(void)
{
	struct sysinfo info = { 0 };
	int ret;

	if ((ret = sysinfo(&info)) != 0) {
		printf("sysinfo err.\n");
		return ret;
	}

	
}

static int mem_init(void)
{
	puts("mem_init ok.");

	return 0;
}

sys_init(mem_init);
