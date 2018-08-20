#include	"unp.h"
void dg_cli_loop1(FILE *fp, int sockfd, const SA* pservaddr, socklen_t servlen);

#define	NDG		2000	/* datagrams to send */
#define	DGLEN	1400	/* length of each datagram */

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

	dg_cli_loop1(stdin, sockfd, (SA *)&servaddr, sizeof(servaddr));

	exit(0);
}
void
dg_cli_loop1(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen)
{
	int		i;
	char	sendline[DGLEN];

	for (i = 0; i < NDG; i++) {
		Sendto(sockfd, sendline, DGLEN, 0, pservaddr, servlen);
	}
}
