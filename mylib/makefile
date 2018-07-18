.PHONY:clean
CC=gcc
DEBUG=1
ifeq ($(DEBUG),1)
C_FLAGS=-fPIC -c -g 
else
C_FLAGS=-fPIC -c
endif
LIB_OBJS=../obj/error.o ../obj/wrapsock.o ../obj/writen.o ../obj/wrapunix.o ../obj/wraplib.o ../obj/str_echo.o ../obj/str_cli.o ../obj/wrapstdio.o ../obj/readline.o ../obj/signal.o ../obj/readn.o

../obj/libunp.so:${LIB_OBJS}
	${CC} -shared -fPIC $^ -o $@
../obj/error.o:error.c
	${CC} ${C_FLAGS} $< -o $@

../obj/wrapsock.o:wrapsock.c
	${CC} ${C_FLAGS} $< -o $@

../obj/writen.o:writen.c
	${CC} ${C_FLAGS} $< -o $@

../obj/wrapunix.o:wrapunix.c
	${CC} ${C_FLAGS} $< -o $@

../obj/wraplib.o:wraplib.c
	${CC} ${C_FLAGS} $< -o $@
../obj/str_echo.o:str_echo.c
	${CC} ${C_FLAGS} $< -o $@
../obj/str_cli.o:str_cli.c
	${CC} ${C_FLAGS} $< -o $@

../obj/wrapstdio.o:wrapstdio.c
	${CC} ${C_FLAGS} $< -o $@

../obj/readline.o:readline.c
	${CC} ${C_FLAGS} $< -o $@

../obj/signal.o:signal.c
	${CC} ${C_FLAGS} $< -o $@
../obj/readn.o:readn.c
	${CC} ${C_FLAGS} $< -o $@
all:../obj/libunp.so
	@echo "makeing all"
clean:
	rm -rf ../obj/*.o ../obj/*.so
