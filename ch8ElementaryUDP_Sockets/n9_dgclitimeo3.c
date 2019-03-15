#include	"unp.h"
/*
 * page 384 advio/dgclitime03.c
 */

static void	sig_alrm(int);
void dg_cli_timeo3(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen);

int
main(int argc, char **argv)
{
	int					sockfd;
	struct sockaddr_in	servaddr;

	if(argc != 3)
		err_quit("usage: bin/n2_echoClientUDP.elf <IP addr> port");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family		= AF_INET;
	servaddr.sin_port		= htons(atoi(argv[2]));
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	sockfd		= Socket(AF_INET, SOCK_DGRAM, 0);

	dg_cli_timeo3(stdin, sockfd, (SA *)&servaddr, sizeof(servaddr));

	exit(0);
}
void
dg_cli_timeo3(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen)
{
	int	n;
	char	sendline[MAXLINE], recvline[MAXLINE + 1];

	Signal(SIGALRM, sig_alrm);

	while (Fgets(sendline, MAXLINE, fp) != NULL) {

		Sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);

		alarm(5);
		if ( (n = recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL)) < 0) {
			if (errno == EINTR)
				fprintf(stderr, "socket timeout\n");
			else
				err_sys("recvfrom error");
		} else {
			alarm(0);
			recvline[n] = 0;	/* null terminate */
			Fputs(recvline, stdout);
		}
	}
}

static void
sig_alrm(int signo)
{
	return;			/* just interrupt the recvfrom() */
}
