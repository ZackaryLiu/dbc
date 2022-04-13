OBJ := dbc
CC := gcc
SRC := main.o ftrace.o init.o mem.o sched.o
INC := ../include

${OBJ}: ${SRC}
	@${CC} $^ -o $@ -Tlink.lds
	@rm -f *.o
	@echo $(shell date) " - compiled ok"

%.o: %.c
	@${CC} -c $^ -o $@ -I${INC}
