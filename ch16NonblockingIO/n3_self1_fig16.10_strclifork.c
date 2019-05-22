#include	"unp.h"

void
str_cli_fork(FILE *fp, int sockfd)
{
	pid_t	pid;
	char	sendline[MAXLINE], recvline[MAXLINE];
	int n;

	if ( (pid = Fork()) == 0) {		/* child: server -> stdout */
	/*
		while (Readline(sockfd, recvline, MAXLINE) > 0)
			Fputs(recvline, stdout);
			*/
		while((n=read(sockfd, recvline, MAXLINE ) ) >0 ){

			write(STDOUT_FILENO, recvline, MAXLINE);
		}
		printf("killling\n");

		kill(getppid(), SIGTERM);	/* in case parent still running */
		exit(0);
	}

		/* parent: stdin -> server */
		/*
	while (Fgets(sendline, MAXLINE, fp) != NULL)
		Writen(sockfd, sendline, strlen(sendline));
		*/
	while((n=read(STDIN_FILENO, sendline, MAXLINE)) >0)
		write(sockfd, sendline, n);

	Shutdown(sockfd, SHUT_WR);	/* EOF on stdin, send FIN */
	pause();
	return;
}
int main(int argc, char **argv)
{
	int sockfd;
	struct sockaddr_in servaddr;
	if(argc != 3){
		err_quit("usage: .elf <IPaddress> <portnumber>");
	}
	sockfd = Socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[2]) );
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	Connect(sockfd, (SA*) &servaddr, sizeof(servaddr));

	str_cli_fork(stdin, sockfd);
	return 0;
}
