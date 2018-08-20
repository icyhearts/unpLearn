#include	"unp.h"
void dg_cli_static(FILE *fp, int sockfd, const SA* pservaddr, socklen_t servlen);
int
main(int argc, char **argv)
{
	int					sockfd;
	struct sockaddr_in	servaddr;

	if (argc != 3)
		err_quit("usage: udpcli <IPaddress> port");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[2]));
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

	dg_cli_static(stdin, sockfd, (SA *) &servaddr, sizeof(servaddr));

	exit(0);
}
void dg_cli_static(FILE *fp, int sockfd, const SA* pservaddr, socklen_t servlen)
{
	int			n;
	char		sendline[MAXLINE], recvline[MAXLINE];
	socklen_t	len;
	struct		sockaddr *preply_addr;
	
	preply_addr	=Malloc(servlen);
	while(Fgets(sendline, MAXLINE, fp) != NULL){
		Sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);
		len = servlen;
		n= Recvfrom(sockfd, recvline, MAXLINE, 0, preply_addr, &len);
		if(len != servlen || memcmp(pservaddr, preply_addr, len ) != 0){
			printf("reply from %s (ignored)\n",
				Sock_ntop(preply_addr, len));
			continue;
		}

		recvline[n] = 0; // null terminate
		Fputs(recvline, stdout);
	}
}
