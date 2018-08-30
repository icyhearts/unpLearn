#include"unp.h"
void dg_echo_self(int sockfd, SA *pcliaddr, socklen_t clilen);
int 
main(int argc, char **argv)
{
	int					sockfd;
	struct sockaddr_in	servaddr, cliaddr;
	if(argc !=2){
		printf("usage: %s, <portNumber>\n", argv[0]);
		return 1;
	}
	sockfd	=	Socket(AF_INET, SOCK_DGRAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family		= AF_INET;
	servaddr.sin_addr.s_addr	= htonl(INADDR_ANY);
	servaddr.sin_port			= htons(atoi(argv[1]));

	Bind(sockfd, (SA *)&servaddr, sizeof(servaddr));

	dg_echo_self(sockfd, (SA*) &cliaddr, sizeof(cliaddr));
}
void dg_echo_self(int sockfd, SA *pcliaddr, socklen_t clilen)
{
	int 				n;
	socklen_t			len;
	char				mesg[MAXLINE];

	for(;;){
		len		= clilen;
		n		= Recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len);
		Sendto(sockfd, mesg, n, 0, pcliaddr, len);
	}
}
