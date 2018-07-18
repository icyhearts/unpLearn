#include"unp.h"
int main(int argc, char **argv)
{
	int listenfd,connfd;
	socklen_t servlen, clilen;
	struct sockaddr_in cliaddr, servaddr;
	listenfd=Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	printf("INADDR_ANY=%d=%x\n",INADDR_ANY,INADDR_ANY);// this shows INADDR_ANY=0,means 0.0.0.0
	servaddr.sin_port=htons(SERV_PORT);// in unp.h #define∙SERV_PORT∙··∙··· 9877// you can run the server with nonRoot user
	printf("SERV_PORT=%d\n",SERV_PORT);
	bind(listenfd,(SA *)&servaddr,sizeof(servaddr));
	// getsockname
	Getsockname(listenfd, (SA*)&servaddr, &servlen);
	u_short servPort = ntohs(servaddr.sin_port);
	printf("servPort=%u\n",servPort);
	char myadd[100]="abc";
	printf("before call, arg, myadd=%s\n", myadd);
	const char *ipAddr = Inet_ntop(AF_INET, &servaddr.sin_addr, myadd, servlen);
	printf("arg, myadd=%s\n", myadd);
	printf("return, ipAddr=%s\n", ipAddr);
	// end of getsockname
	listen(listenfd,LISTENQ);// #define∙LISTENQ∙∙···1024∙ in unp.h
	return 0;
}
