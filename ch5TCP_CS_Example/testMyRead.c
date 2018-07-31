#include<unp.h>
static int read_cnt;
static char *read_ptr;
static char read_buf[MAXLINE];
static ssize_t my_read(int fd, char *ptr)
{// my_read(int sockfd, &c) // char c// called like this in echo C/S
	if(read_cnt <= 0){
		again:
			if((read_cnt=read(fd, read_buf, sizeof(read_buf))) < 0){
				if(errno == EINTR)
					goto again;
				return (-1);
			}else if(read_cnt == 0)
				return 0;
			read_ptr = read_buf;
	}
	read_cnt--;
	*ptr=*read_ptr++;
	return 1;
}

int main()
{
int n,i,fd;
char c, *ptr;
size_t rc;
	n=100;
//	printf("%d\n",stdin);
//	printf("%d\n",stdout);
//	printf("%d\n",stderr);
	if ( (fd=open("op.txt",O_RDONLY)) == -1 ){
		printf("open error\n");
	}
		printf("fd=%d\n",fd);
	for(i=1;i<10;i++){
		rc=my_read(fd,&c);
		printf("c=%c,rc=%d\n",c,rc);
	}
	return 0;

}
