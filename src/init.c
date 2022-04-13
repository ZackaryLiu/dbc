#include <stdio.h>
#include <init.h>

extern initcall_t __init_sys_start[];
extern initcall_t __init_sys_end[];

int run_sys_init(void)
{
	initcall_t *fn;
	int ret;

	printf("[%s] __init_sys_start: %p - __init_sys_end: %p\n",
		__func__,__init_sys_start, __init_sys_end);

	for (fn = __init_sys_start; fn < __init_sys_end; fn++) {
		ret = (*fn)();
		if (ret) {
			printf("the func %p was initialed fail\n", *fn);	
			return ret;	
		}
	}

	return 0;
}
