#define _GNU_SOURCE
#include <unistd.h>
#include <stdint.h>
#include <sys/syscall.h>

#define SYS_sched_setattr __NR_sched_setattr
#define SYS_sched_getattr __NR_sched_getattr

#define SCHED_NORMAL	0
#define SCHED_FIFO		1
#define SCHED_RR		2
#define SCHED_BATCH		3
/* SCHED_ISO: reserved but not implemented yet */
#define SCHED_IDLE		5
#define SCHED_DEADLINE	6

struct sched_attr {
	uint32_t size;
	uint32_t sched_policy;
	uint64_t sched_flags;

	/* SCHED_NORMAL, SCHED_BATCH */
	int32_t sched_nice;

	/* SCHED_FIFO, SCHED_RR */
	uint32_t sched_priority;

	/* SCHED_DEADLINE (nsec) */
	uint64_t sched_runtime;
	uint64_t sched_deadline;
	uint64_t sched_period;

	/* UTILIZATION CLAMPING */
	uint32_t sched_util_min;
	uint32_t sched_util_max;
};

static int sched_setattr(pid_t pid, const struct sched_attr *attr, unsigned int flags)
{
	return syscall(SYS_sched_setattr, pid, attr, flags);
}

static int sched_getattr(pid_t pid, struct sched_attr *attr, unsigned int size, unsigned int flags)
{
	return syscall(SYS_sched_getattr, pid, attr, size, flags);
}

#define NAME(p)	case p: return #p;

static const char *sched_policy_name(uint32_t policy)
{
	switch (policy) {
		NAME(SCHED_NORMAL);
		NAME(SCHED_FIFO);
		NAME(SCHED_RR);
		NAME(SCHED_BATCH);
		NAME(SCHED_IDLE);
		NAME(SCHED_DEADLINE);
		default:
			return "NULL";
	}
}
