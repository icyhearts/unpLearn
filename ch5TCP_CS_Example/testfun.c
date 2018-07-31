#include<myunp.h>
#include"myfun.h"
/*
to test functions: readline
*/
int main()
{
	char recvline[MAXLINE];
	char *writeline=(char *)malloc(sizeof(char)*MAXLINE);
	ssize_t cnt;
	int fd;
	writeline="hello\n";
	if( (fd=open("text.txt",O_RDWR)) <0 )perror("open error ");
	cnt=readline(fd,recvline,MAXLINE);
	printf("MAXLINE=%d,cnt=%d\n",MAXLINE,cnt);
	printf("%s",recvline);

	cnt=readline(fd,recvline,MAXLINE);
	printf("MAXLINE=%d,cnt=%d\n",MAXLINE,cnt);
	printf("%s",recvline);

	cnt=readline(fd,recvline,MAXLINE);
	printf("MAXLINE=%d,cnt=%d\n",MAXLINE,cnt);
	printf("%s",recvline);
	lseek(fd,0,SEEK_END);
	write(fd,writeline,strlen(writeline));
	close(fd);
	return 0;
}
