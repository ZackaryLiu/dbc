#include <stdio.h>
#include <init.h>
#include <unistd.h>

#define TRACE	"/sys/kernel/debug/tracing"

static int ftrace_stat(void)
{
	if (!access("TRACE", F_OK)) {
		puts(TRACE "not exist");
		return -1;
	}

	return 0;
}

static int ftrace_main(const char *args)
{
	
	return 0;
}

static int ftrace_init(void)
{
	puts("ftrace_init ok.");

	return 0;
}

sys_init(ftrace_init);
