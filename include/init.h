#ifndef __INC_INIT__
#define __INC_INIT__

typedef int (*initcall_t)(void);
typedef void (*exitcall_t)(void);

#define ___PASTE(a,b) a##b
#define __PASTE(a,b) ___PASTE(a,b)

#define sys_init(fn) \
	static initcall_t __PASTE(__, __PASTE(__LINE, fn)) \
	__attribute__((__section__(".init_entry_sys"))) = fn;

int run_sys_init(void);

#endif
