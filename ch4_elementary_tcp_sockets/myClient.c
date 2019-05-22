#include"unp.h"
#include<stdio.h>
#include<stdlib.h>
#include<strings.h> // bzero()
#include<netinet/in.h> // provide struct sockaddr_in 
#include<arpa/inet.h>
#include<unistd.h> //read
#include<sys/socket.h>
int main(int argc,char **argv)
{
	int sockfd,n;
	char recvline[MAXLINE+1];
	struct sockaddr_in servaddr;
	if(argc!=3){
		printf("use: a.out <IPaddress> <portNumber>");
		return 1;
	}

	if( (sockfd=socket(AF_INET,SOCK_STREAM,0))<0)err_sys("socket error\n");
	
	bzero(&servaddr,sizeof(servaddr)); 
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(atoi(argv[2]));
	// convert 127.0.0.1 -> servaddr.sin_addr
	if(inet_pton(AF_INET,argv[1],&servaddr.sin_addr) <=0 )printf("inet_pton error for %s",argv[1]);
	if(connect(sockfd,(SA *) &servaddr,sizeof(servaddr)) < 0 ) perror("connect errorn");
	while( (n=read(sockfd,recvline,MAXLINE)) >0 ){
		recvline[n]=0;
		if(fputs(recvline,stdout) == EOF)perror("fputs error");
	}

	if(n<0)err_sys("read error");
	exit(0);
}
