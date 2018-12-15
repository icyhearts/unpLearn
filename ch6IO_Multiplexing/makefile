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

${BIN_DIR}/n1_fig6.9_EchoClient_select_strcliselect01.elf:n1_fig6.9_EchoClient_select_strcliselect01.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< -o $@ ${C_FLAGS}  ${LINK_FLAGS}
${BIN_DIR}/n2_fig6.13_EchoClient_select_strcliselect02.elf:n2_fig6.13_EchoClient_select_strcliselect02.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< -o $@ ${C_FLAGS}  ${LINK_FLAGS}
${BIN_DIR}/n3_fig6.21_EchoServer_tcpservselect01.elf:n3_fig6.21_EchoServer_tcpservselect01.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< -o $@ ${C_FLAGS}  ${LINK_FLAGS}
${BIN_DIR}/n4_fig6.25_EchoServer_tcpservpoll01.elf:n4_fig6.25_EchoServer_tcpservpoll01.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
${BIN_DIR}/self1_TCP_EchoServerEpoll.elf:self1_TCP_EchoServerEpoll.cpp ${MYLIB_INC_DIR}/unp.h
	${CXX} $< ${CXX_FLAGS}  -o $@ 
${BIN_DIR}/self2_TCP_EchoClientSelect.elf:self2_TCP_EchoClientSelect.cpp ${MYLIB_INC_DIR}/unp.h
	${CXX} $< ${CXX_FLAGS}  -o $@ 

${BIN_DIR}/self3_epoll-example.elf:self3_epoll-example.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
${BIN_DIR}/self4_epollTCPServerClient.elf:self4_epollTCPServerClient.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
${BIN_DIR}/self5_epollConstant.elf:self5_epollConstant.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
learn/${BIN_DIR}/n1tcpserverselect01.elf:learn/n1tcpserverselect01.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
learn/${BIN_DIR}/tcpservpoll01.elf:learn/tcpservpoll01.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
learn/${BIN_DIR}/n2_getopt.elf:learn/n2_getopt.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
${BIN_DIR}/n5_test.elf:n5_test.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
clean:
	rm -rf ${OBJ_DIR}/*.o ${BIN_DIR}/*.elf
