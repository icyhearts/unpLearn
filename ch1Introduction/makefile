.PHONY:clean
CC=gcc
MYLIB_DIR=../mylib
C_FLAGS=-Wall -g -I ${MYLIB_DIR}
LIB_OBJS=../obj/error.o ../obj/wrapsock.o ../obj/writen.o ../obj/wrapunix.o

fig1.5.daytimetcpcli.elf:fig1.5.daytimetcpcli.o ${LIB_OBJS}
	${CC} ${C_FLAGS} $^  -o $@
fig1.5.daytimetcpcli.o:fig1.5.daytimetcpcli.c ${MYLIB_DIR}/unp.h
	${CC} -c ${C_FLAGS} $<  -o $@

fig1.9.daytimetcpsrv.elf:fig1.9.daytimetcpsrv.o ${LIB_OBJS}
	${CC} ${C_FLAGS} $^  -o $@
fig1.9.daytimetcpsrv.o:fig1.9.daytimetcpsrv.c ${MYLIB_DIR}/unp.h
	${CC} -c ${C_FLAGS} $<  -o $@
clean:
	rm -rf *.o
