.PHONY:clean
CC=gcc
DEBUG=1
ifeq ($(DEBUG),1)
C_FLAGS=-fPIC -c -g 
else
C_FLAGS=-fPIC -c
endif
LIB_OBJS=../obj/error.o ../obj/wrapsock.o ../obj/writen.o ../obj/wrapunix.o ../obj/wraplib.o ../obj/str_echo.o ../obj/str_cli.o ../obj/wrapstdio.o ../obj/readline.o ../obj/signal.o ../obj/readn.o ../obj/sock_ntop.o\
	../obj/dg_cli.o ../obj/dg_echo.o ../obj/tcp_connect.o ../obj/sock_ntop_host.o ../obj/tcp_listen.o ../obj/udp_server.o ../obj/daemon_init.o  ../obj/connect_timeo.o\
	../obj/read_fd.o ../obj/readable_timeo.o ../obj/write_fd.o ../obj/gf_time.o

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

../obj/daemon_init.o:daemon_init.c
	${CC} ${C_FLAGS} $< -o $@

../obj/dg_cli.o:dg_cli.c
	${CC} ${C_FLAGS} $< -o $@
../obj/dg_echo.o:dg_echo.c
	${CC} ${C_FLAGS} $< -o $@
../obj/signal.o:signal.c
	${CC} ${C_FLAGS} $< -o $@
../obj/readn.o:readn.c
	${CC} ${C_FLAGS} $< -o $@
../obj/sock_ntop.o:sock_ntop.c
	${CC} ${C_FLAGS} $< -o $@
../obj/tcp_connect.o:tcp_connect.c
	${CC} ${C_FLAGS} $< -o $@
../obj/tcp_listen.o:tcp_listen.c
	${CC} ${C_FLAGS} $< -o $@
../obj/sock_ntop_host.o:sock_ntop_host.c
	${CC} ${C_FLAGS} $< -o $@
../obj/udp_server.o:udp_server.c
	${CC} ${C_FLAGS} $< -o $@
../obj/connect_timeo.o:connect_timeo.c
	${CC} ${C_FLAGS} $< -o $@
../obj/readable_timeo.o:readable_timeo.c
	${CC} ${C_FLAGS} $< -o $@
../obj/read_fd.o:read_fd.c
	${CC} ${C_FLAGS} $< -o $@
../obj/write_fd.o:write_fd.c
	${CC} ${C_FLAGS} $< -o $@
../obj/gf_time.o:gf_time.c
	${CC} ${C_FLAGS} $< -o $@
all:../obj/libunp.so
	@echo "makeing all"
clean:
	rm -rf ../obj/*.o ../obj/*.so
