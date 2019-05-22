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


${BIN_DIR}/n1_fig16.3-16.4-16.5_strclinonb.elf:n1_fig16.3-16.4-16.5_strclinonb.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< -o $@ ${C_FLAGS}  ${LINK_FLAGS}
${BIN_DIR}/n2_fig16.10_strclifork.elf:n2_fig16.10_strclifork.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< -o $@ ${C_FLAGS}  ${LINK_FLAGS}
${BIN_DIR}/n3_self1_fig16.10_strclifork.elf:n3_self1_fig16.10_strclifork.c ${MYLIB_INC_DIR}/unp.h
	${CC} $< -o $@ ${C_FLAGS}  ${LINK_FLAGS}

${BIN_DIR}/n4_daytimetcpcli.elf:${OBJ_DIR}/n4_daytimetcpcli.o  ${OBJ_DIR}/connect_nonb.o
	${CC} $^ -o $@ ${C_FLAGS}  ${LINK_FLAGS}

${OBJ_DIR}/n4_daytimetcpcli.o:n4_daytimetcpcli.c ${MYLIB_INC_DIR}/unp.h
	${CC} -c $< -o $@ ${C_FLAGS}  
${OBJ_DIR}/connect_nonb.o:connect_nonb.c ${MYLIB_INC_DIR}/unp.h
	${CC} -c $< -o $@ ${C_FLAGS} 
clean:
	rm -rf ${OBJ_DIR}/*.o ${BIN_DIR}/*.elf
