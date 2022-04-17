#include <stdio.h>
#include <init.h>
#include <stdlib.h>

#include "cpuset.h"
#include "sched.h"

#define NCPU	6

static int print_task_info(uint32_t pid)
{
	struct sched_attr sa;
	uint32_t policy;
	int ret;

	if ((ret = sched_getattr(pid, &sa, sizeof(sa), 0)) != 0) {		
		perror("sched_getattr err.\n");
		return ret;
	}

	policy = sa.sched_policy;
	printf("policy\t\tsflags\t\tpriority\n");
	printf("%s\t0x%lx\t\t%d\n", 
			sched_policy_name(policy), sa.sched_flags, 
			policy == SCHED_NORMAL ? 120 - sa.sched_nice : sa.sched_priority);

	cpu_set_t set;
	int i = 0;
	int mask = 0;

	sched_getaffinity(pid, sizeof(set), &set);

	for (; i < NCPU; i++)
		if (CPU_ISSET(i, &set))
			mask |= 1 << i;

	printf("affinity: %x\n", mask);

	return 0;
}

static int sched_init(void)
{
	puts("sched_init ok.");

	print_task_info(1);
	print_task_info(14);

	return 0;
}

sys_init(sched_init);
