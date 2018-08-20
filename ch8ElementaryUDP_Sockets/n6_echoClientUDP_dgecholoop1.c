#include	"unp.h"
void dg_echo_loop1(int sockfd, SA *pcliaddr, socklen_t clilen);
static void	recvfrom_int(int);
static int	count;

int 
main(int argc, char **argv)
{
	int					sockfd;
	struct sockaddr_in	servaddr, cliaddr;

	sockfd	=	Socket(AF_INET, SOCK_DGRAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family		= AF_INET;
	servaddr.sin_addr.s_addr	= htonl(INADDR_ANY);
	servaddr.sin_port			= htons(atoi(argv[1]));

	Bind(sockfd, (SA *)&servaddr, sizeof(servaddr));

	dg_echo_loop1(sockfd, (SA*) &cliaddr, sizeof(cliaddr));
}
void
dg_echo_loop1(int sockfd, SA *pcliaddr, socklen_t clilen)
{
	socklen_t	len;
	char		mesg[MAXLINE];

	Signal(SIGINT, recvfrom_int);

	for ( ; ; ) {
		len = clilen;
		Recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len);

		count++;
	}
}

static void
recvfrom_int(int signo)
{
	printf("\nreceived %d datagrams\n", count);
	exit(0);
}
