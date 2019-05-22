.PHONY:clean
CC=gcc
MYLIB_INC_DIR=../mylib
DEBUG=1
ifeq ($(DEBUG),1)
C_FLAGS=-Wall -I ${MYLIB_INC_DIR} -g 
else
C_FLAGS=-Wall -I ${MYLIB_INC_DIR}
endif
BIN_DIR=bin
OBJ_DIR=obj

MYLIB_LINK_DIR=../obj
LINK_FLAGS=-L ${MYLIB_LINK_DIR} -lunp


myServer.elf:myServer.c
	${CC} $<   ${C_FLAGS} ${LINK_FLAGS} -o $@
myClient.elf:myClient.c
	${CC} $<   ${C_FLAGS} ${LINK_FLAGS} -o $@
clean:
	rm -rf *.o *.elf
