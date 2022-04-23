#include <stdio.h>
#include <init.h>
#include <sys/sysinfo.h>
#include <unistd.h>

static int print_sys_info(void)
{
	struct sysinfo info = { 0 };
	int ret;

	if ((ret = sysinfo(&info)) != 0) {
		printf("sysinfo err.\n");
		return ret;
	}

	puts("__________________________________");
	printf("uptime: %ld\n", info.uptime);

	puts("__________________________________");
	printf("loads: %ld %ld %ld\n", info.loads[0], info.loads[1], info.loads[2]);

	puts("__________________________________");
	printf("total: %ld\tfree: %ld\tshm: %ld\tbuffer: %ld\n", 
		info.totalram, info.freeram, info.sharedram, info.bufferram);
	printf("totalswap: %ld\tfreeswap: %ld\n", info.totalswap, info.freeswap);
	printf("mem_unit: %d\n", info.mem_unit);

	/* TODO: How does sysconf work */
	printf("pagesize: %ld\n", sysconf(_SC_PAGESIZE));

	puts("__________________________________");
	printf("total procs: %d\n", info.procs);

	puts("__________________________________");
	printf("totalhigh: %ld\tfreehigh: %ld\n", info.totalhigh, info.freehigh);

	return 0;
}

static int mem_init(void)
{
	puts("mem_init ok.");

	print_sys_info();

	return 0;
}

sys_init(mem_init);
