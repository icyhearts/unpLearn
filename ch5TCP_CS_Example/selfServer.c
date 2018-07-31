#include<myunp.h>
#include"myfun.h"
int main()
{
	int listenfd,connfd,fd;
	int cnt=0,readCnt=0,resSize=0,i;
	int n;
	char buf[MAXLINE];
	pid_t childpid;
	socklen_t clilen;
	char *result=(char *)malloc(MAXLINE*sizeof(char));
	struct sockaddr_in cliaddr,servaddr;
	
	strcpy(result,"result is\n");
	listenfd=socket(AF_INET,SOCK_STREAM,0);//Specifying a protocol of 0 causes socket() to use an unspecified
//default protocol appropriate for the requested socket type.
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);// 0.0.0.0(I test this by printf())
	servaddr.sin_port=htons(SERV_PORT);// 9877
	bind(listenfd,(SA *)&servaddr,sizeof(servaddr));
	listen(listenfd,LISTENQ);// 1024, now server is LISTEN stat, passive open
	printf("result=%s",result);
	for(i=0;result[i];i++);
	resSize=i+1;
	printf("sizeof result=%d\n",resSize);
	for(;;){
		printf("connection %d\n",cnt++);
		clilen=sizeof(cliaddr);
		connfd=accept(listenfd,(SA *)&cliaddr,&clilen);
		fd=open("text.txt",O_RDWR);
		while( (n=read(connfd,buf,MAXLINE)) > 0){// read from socket
			printf("readCnt=%d\n",readCnt++);
			//writen(connfd,buf,n);// write to socket
			writen(connfd,result,resSize);// write to socket// myline
			//writen(connfd,result,n);// my line
			write(fd,result,resSize);// myline
			}
		close(connfd); // close the connfd
		close(fd);// myline
	}
		close(listenfd); // finally, close listenfd;
	return 0;
}
