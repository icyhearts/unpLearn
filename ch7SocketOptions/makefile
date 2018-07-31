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

all:learn/${BIN_DIR}/checkopts.elf

learn/${BIN_DIR}/checkopts.elf:learn/checkopts.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
${BIN_DIR}/n5_test.elf:n5_test.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
clean:
	rm -rf ${OBJ_DIR}/*.o ${BIN_DIR}/*.elf
