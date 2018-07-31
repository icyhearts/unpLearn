//#include<unp.h>
#include<myunp.h>
void sig_child(int signo);
int main(int argc, char **argv)
{
	int listenfd,connfd;
	pid_t childpid;
	socklen_t clilen;
	struct sockaddr_in cliaddr, servaddr;
	listenfd=socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	printf("INADDR_ANY=%d=%x\n",INADDR_ANY,INADDR_ANY);// this shows INADDR_ANY=0,means 0.0.0.0
	servaddr.sin_port=htons(SERV_PORT);// in unp.h #define∙SERV_PORT∙··∙··· 9877// you can run the server with nonRoot user
#ifdef LIKE_LINUX_IN_H
	printf("linux/in.h is included\n");
#endif
#ifdef LIKE_NETINET_IN_H	
	printf("netinet/in.h is included\n");
#endif


	bind(listenfd,(SA *)&servaddr,sizeof(servaddr));
	listen(listenfd,LISTENQ);// #define∙LISTENQ∙∙···1024∙ in unp.h
	signal(SIGCHLD,sig_child);
	for(;;){
		clilen=sizeof(cliaddr);
		//connfd=accept(listenfd,(SA *)&cliaddr, &clilen);
		if( (connfd = accept(listenfd,(SA *)&cliaddr, &clilen)) < 0){
			if(errno == EINTR)
				continue;
			else 
				perror("accept error ");
		}
		if((childpid=fork()) ==0){
			close(listenfd);// close listening socket
			str_echo(connfd);
			exit(0);
		}
		close(connfd);
	}
	return 0;
}
void sig_child(int signo)
{
	pid_t pid;
	int stat;

	pid=wait(&stat);
	printf("child %d terminated\n",pid);
	return;
}
