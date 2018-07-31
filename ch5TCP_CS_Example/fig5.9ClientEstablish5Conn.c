#include<unp.h>
int main(int argc,char **argv)
{
	int i,sockfd[5];

	struct sockaddr_in servaddr;

	if(argc!=2){
		printf("usage: tcpcli <IP address>\n");
	}
	for(i=0;i<5;i++){
	
		sockfd[i]=socket(AF_INET,SOCK_STREAM,0);
		bzero(&servaddr,sizeof(servaddr));
		servaddr.sin_family=AF_INET;
		servaddr.sin_port=htons(SERV_PORT);
		inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
		connect(sockfd[i], (SA*)&servaddr, sizeof(servaddr));
	}
	str_cli(stdin,sockfd[0]);
	return 0;
}

