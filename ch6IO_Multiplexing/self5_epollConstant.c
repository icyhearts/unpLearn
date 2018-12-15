#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#define DEFAULT_PORT    8080
#define MAX_CONN        16
#define MAX_EVENTS      32
#define BUF_SIZE        16
#define MAX_LINE        256


int main(int argc, char *argv[])
{
	printf("EPOLLIN=0x%x\n", EPOLLIN);
	printf("EPOLLOUT=0x%x\n", EPOLLOUT);
	printf("EPOLLET=0x%x\n", EPOLLET);
	printf("EPOLLRDHUP=0x%x\n", EPOLLRDHUP);
	printf("EPOLLHUP=0x%x\n", EPOLLHUP);
	return 0;
}
