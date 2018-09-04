#include	"unp.h"
//#define MYDEBUG

void
str_cliselect01(FILE *fp, int sockfd)
{
	int			maxfdp1;
	fd_set		rset;
	char		sendline[MAXLINE], recvline[MAXLINE];

	FD_ZERO(&rset);
	for ( ; ; ) {
		FD_SET(fileno(fp), &rset);
		FD_SET(sockfd, &rset);
		maxfdp1 = max(fileno(fp), sockfd) + 1;
#ifdef MYDEBUG
		printf("%d, before Select called\n",__LINE__);
#endif
		Select(maxfdp1, &rset, NULL, NULL, NULL);
#ifdef MYDEBUG
		printf("%d, after Select called\n",__LINE__);
#endif
		if (FD_ISSET(sockfd, &rset)) {	/* socket is readable */
#ifdef MYDEBUG
		printf("%d, sockfd ready \n",__LINE__);
#endif
			if (Readline(sockfd, recvline, MAXLINE) == 0)
				err_quit("str_cli: server terminated prematurely");
			Fputs(recvline, stdout);
		}

		if (FD_ISSET(fileno(fp), &rset)) {  /* input is readable */
#ifdef MYDEBUG
		printf("%d, terminal input ready \n",__LINE__);
#endif
			if (Fgets(sendline, MAXLINE, fp) == NULL){
#ifdef MYDEBUG
				printf("%d, fgets return null\n",__LINE__);
#endif
				return;		/* all done */
			}
			Writen(sockfd, sendline, strlen(sendline));
		}
	}
}
int main(int argc, char  **argv)
{
	int sockfd;
	struct sockaddr_in servaddr;

	if(argc != 3)
		err_quit("usage: .elf <IPaddress> <PortNumber>");
	
	sockfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[2]));
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	Connect(sockfd, (SA*) &servaddr, sizeof(servaddr));
	str_cliselect01(stdin, sockfd);
	exit(0);
}
