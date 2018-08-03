#include"unp.h"
void dg_cli_self(FILE *fp, int sockfd, const SA* pservaddr, socklen_t servlen);
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

	dg_cli_self(stdin, sockfd, (SA *)&servaddr, sizeof(servaddr));

	exit(0);
}
void dg_cli_self(FILE *fp, int sockfd, const SA* pservaddr, socklen_t servlen)
{
	int		n;
	char		sendline[MAXLINE], recvline[MAXLINE+1];

	while(Fgets(sendline, MAXLINE, fp) != NULL){
		Sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);
	}
}
