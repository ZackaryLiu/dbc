OBJ := dbc
CC := gcc
SRC := main.o

${OBJ}: ${SRC}
	@${CC} $^ -o $@
	@rm -f *.o

%.o: %c
	@${CC} -c $^ -o $@
