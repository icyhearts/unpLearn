.PHONY:clean
CC=gcc
CXX=g++
MYLIB_INC_DIR=../mylib
DEBUG=1
ifeq ($(DEBUG),1)
C_FLAGS=-Wall -I ${MYLIB_INC_DIR} -g 
CXX_FLAGS=-Wall -g
else
C_FLAGS=-Wall -I ${MYLIB_INC_DIR}
CXX_FLAGS=-Wall
endif
BIN_DIR=bin
OBJ_DIR=obj

MYLIB_LINK_DIR=../obj
LINK_FLAGS=-L ${MYLIB_LINK_DIR} -lunp

all:${BIN_DIR}/n4_fig6.25_EchoServer_tcpservpoll01.elf ${BIN_DIR}/n3_fig6.21_EchoServer_tcpservselect01.elf

${BIN_DIR}/n1_fig16.3-16.4-16.5_strclinonb.elf:n1_fig16.3-16.4-16.5_strclinonb.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< -o $@ ${C_FLAGS}  ${LINK_FLAGS}
clean:
	rm -rf ${OBJ_DIR}/*.o ${BIN_DIR}/*.elf
