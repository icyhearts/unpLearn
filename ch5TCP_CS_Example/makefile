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

#LIB_OBJS=../obj/error.o ../obj/wrapsock.o ../obj/writen.o ../obj/wrapunix.o ../obj/wraplib.o

fig4.11.server.print.elf:fig4.11.server.print.o ${LIB_OBJS}
	${CC} ${C_FLAGS} $^  -o $@
fig4.11.server.print.o:fig4.11.server.print.c ${MYLIB_INC_DIR}/unp.h
	${CC} -c ${C_FLAGS} $<  -o $@

n1_selfLearnGetsockname.elf:n1_selfLearnGetsockname.o 
	${CC} ${C_FLAGS} ${LINK_FLAGS} $^  -o $@
n1_selfLearnGetsockname.o:n1_selfLearnGetsockname.c ${MYLIB_INC_DIR}/unp.h
	${CC} -c ${C_FLAGS} $<  -o $@


n2_self_fig5.2TCP_EchoServer.elf:n2_self_fig5.2TCP_EchoServer.o
	${CC} ${C_FLAGS} ${LINK_FLAGS} $^  -o $@
n2_self_fig5.2TCP_EchoServer.o:n2_self_fig5.2TCP_EchoServer.c ${MYLIB_INC_DIR}/unp.h
	${CC} -c ${C_FLAGS} $<  -o $@

n3_learnIO.elf:n3_learnIO.c
	${CC} ${C_FLAGS} $<  -o $@

${BIN_DIR}/n4_fig5.4TcpEchoClient.elf:n4_fig5.4TcpEchoClient.c ${MYLIB_INC_DIR}/unp.h
	${CC} ${C_FLAGS} ${LINK_FLAGS} $<  -o $@
${BIN_DIR}/n5_tcpserverSigchld.elf:n5_tcpserverSigchld.c ${MYLIB_INC_DIR/unp.h}
	${CC} ${C_FLAGS} ${LINK_FLAGS} $<  -o $@
${BIN_DIR}/n6_fig5.9Tcpcli04.elf:n6_fig5.9Tcpcli04.c ${MYLIB_INC_DIR/unp.h}
	${CC} ${C_FLAGS} ${LINK_FLAGS} $<  -o $@
${BIN_DIR}/n7_fig5.12Tcpserv04.elf:n7_fig5.12Tcpserv04.c ${MYLIB_INC_DIR/unp.h}
	${CC} ${C_FLAGS} ${LINK_FLAGS} $<  -o $@
${BIN_DIR}/n8_fig5.14Str_cli11.elf:n8_fig5.14Str_cli11.c ${MYLIB_INC_DIR/unp.h}
	${CC} ${C_FLAGS} ${LINK_FLAGS} $<  -o $@
${BIN_DIR}/n9_errorLearn.elf:n9_errorLearn.c ${MYLIB_INC_DIR/unp.h}
	${CC} ${C_FLAGS} ${LINK_FLAGS} $<  -o $@
${BIN_DIR}/n10_fig5.17_EchoServerStr_echo08.elf:n10_fig5.17_EchoServerStr_echo08.c ${MYLIB_INC_DIR/unp.h}
	${CC} ${C_FLAGS} ${LINK_FLAGS} $<  -o $@
${BIN_DIR}/n11_fig5.19_EchoClientStr_cli09.elf:n11_fig5.19_EchoClientStr_cli09.c ${MYLIB_INC_DIR/unp.h}
	${CC} ${C_FLAGS} ${LINK_FLAGS} $<  -o $@
${BIN_DIR}/n12_fig5.20EchoServerStr_echo09.c:n12_fig5.20EchoServerStr_echo09.c ${MYLIB_INC_DIR/unp.h}
	${CC} ${C_FLAGS} ${LINK_FLAGS} $<  -o $@
clean:
	rm -rf *.o *.elf
