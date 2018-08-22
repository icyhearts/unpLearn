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

all:${BIN_DIR}/fig1.9.daytimetcpsrv.elf  ${BIN_DIR}/fig1.5.daytimetcpcli.elf  ${BIN_DIR}/c1n1_fig11.6_daytimetcpcliv6.elf  ${BIN_DIR}/c1n2_daytimetcpsrvv6.elf 

MYLIB_LINK_DIR=../obj
LINK_FLAGS=-L ${MYLIB_LINK_DIR} -lunp
#
${BIN_DIR}/fig1.9.daytimetcpsrv.elf:fig1.9.daytimetcpsrv.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
${BIN_DIR}/fig1.5.daytimetcpcli.elf:fig1.5.daytimetcpcli.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
${BIN_DIR}/c1n1_fig11.6_daytimetcpcliv6.elf:c1n1_fig11.6_daytimetcpcliv6.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
${BIN_DIR}/c1n2_daytimetcpsrvv6.elf:c1n2_daytimetcpsrvv6.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
##
clean:
	rm -rf ${OBJ_DIR}/*.o ${BIN_DIR}/*.elf learn/bin/*.elf *.o *.elf
