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
all:${BIN_DIR}/c11n1_fig11.3_hostent.elf ${BIN_DIR}/self1_gethostbyaddr.elf ${BIN_DIR}/c11n2_fig11.11_daytimetcpcli.elf ${BIN_DIR}/c11n3_fig11.13_daytimetcpsrv1.elf ${BIN_DIR}/c11n4_fig11.14_daytimetcpsrv2.elf 

${BIN_DIR}/c11n1_fig11.3_hostent.elf:c11n1_fig11.3_hostent.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
${BIN_DIR}/self1_gethostbyaddr.elf:self1_gethostbyaddr.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
${BIN_DIR}/c11n2_fig11.11_daytimetcpcli.elf:c11n2_fig11.11_daytimetcpcli.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
${BIN_DIR}/c11n3_fig11.13_daytimetcpsrv1.elf:c11n3_fig11.13_daytimetcpsrv1.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
${BIN_DIR}/c11n4_fig11.14_daytimetcpsrv2.elf:c11n4_fig11.14_daytimetcpsrv2.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
${BIN_DIR}/c11n5_fig11.16_daytimeudpcli1.elf:c11n5_fig11.16_daytimeudpcli1.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
${BIN_DIR}/c11n6_fig11.19_daytimeudpsrv2.elf:c11n6_fig11.19_daytimeudpsrv2.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
${BIN_DIR}/c11n7_fig11.17_daytimeudpCli2.elf:c11n7_fig11.17_daytimeudpCli2.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 

${BIN_DIR}/self2_daytimeClient_getaddrinfo.elf:self2_daytimeClient_getaddrinfo.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
clean:
	rm -rf ${OBJ_DIR}/*.o ${BIN_DIR}/*.elf learn/bin/*.elf
