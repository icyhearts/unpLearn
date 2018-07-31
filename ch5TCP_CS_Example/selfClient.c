#include<myunp.h>
#include"myfun.h"
int main(int argc,char *argv[])
{
	int sockfd;
	struct sockaddr_in servaddr;
	char sendline[MAXLINE], recvline[MAXLINE];
	int fgetsCnt=0;
	if(argc!=2){
		printf("usage: tcpcli <IP address>\n");
	}
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	bzero(&servaddr,sizeof(servaddr));

	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(SERV_PORT);
	inet_pton(AF_INET,argv[1],&servaddr.sin_addr);// to sin_addr, not sin_addr.s_addr

	connect(sockfd,(SA *)&servaddr,sizeof(servaddr)); // SYN_SEND
	while(fgets(sendline,MAXLINE,stdin) != NULL){// read from terminal
		printf("fgetsCnt=%d\n",fgetsCnt++);
		writen(sockfd,sendline,strlen(sendline));// write to socket
		//printf("here\n");// my line
		if(readline(sockfd,recvline,MAXLINE) == 0){// read from socket
			printf("server terminated prematurely\n");
		}
		//readline(sockfd,recvline,MAXLINE);// my line read from socket
		fputs(recvline,stdout);// write to terminal
	}
	// will return if you Ctrl-D
	printf("finished\n");
	return 0;
}
