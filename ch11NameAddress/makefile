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


${BIN_DIR}/c11n1_fig11.3_hostent.elf:c11n1_fig11.3_hostent.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
${BIN_DIR}/self1_gethostbyaddr.elf:self1_gethostbyaddr.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
${BIN_DIR}/c11n2_fig11.11_daytimetcpcli.elf:c11n2_fig11.11_daytimetcpcli.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< ${C_FLAGS}  ${LINK_FLAGS} -o $@ 
clean:
	rm -rf ${OBJ_DIR}/*.o ${BIN_DIR}/*.elf learn/bin/*.elf
