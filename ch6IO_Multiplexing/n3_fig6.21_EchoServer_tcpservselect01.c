/* include fig01 */
#include	"unp.h"
#define NOTDEF
#define MYDEBUG

int
main(int argc, char **argv)
{
	if(argc != 2){
		printf("usage: bin/n3_fig6.21_EchoServer_tcpservselect01.elf <portNumber>\n");
		exit(1);
	}
	int					i, maxi, maxfd, listenfd, connfd, sockfd;
	int					nready, client[FD_SETSIZE];
	ssize_t				n;
	fd_set				rset, allset;
	char				buf[MAXLINE];
	socklen_t			clilen;
	struct sockaddr_in	cliaddr, servaddr;

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);
	#ifdef MYDEBUG
	printf("listenfd=%d, FD_SETSIZE=%d\n", listenfd, FD_SETSIZE);
	#endif
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(atoi(argv[1]) );

	Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

	Listen(listenfd, LISTENQ);

	maxfd = listenfd;			/* initialize */
	maxi = -1;					/* index into client[] array */
	for (i = 0; i < FD_SETSIZE; i++)
		client[i] = -1;			/* -1 indicates available entry */
	FD_ZERO(&allset);
	FD_SET(listenfd, &allset);
/* end fig01 */

	struct timeval tv_start, tv_stop;
	#ifdef MYDEBUG
		int accu = 0;
	#endif
/* include fig02 */
	for ( ; ; ) {
		rset = allset;		/* structure assignment */

		gettimeofday(&tv_start, NULL);
#ifdef MYDEBUG
		printf("before select called\n");
#endif
#ifdef MYDEBUG
		if (FD_ISSET(listenfd, &rset)) {	/* new client connection */
			printf("line %d, before Select, listenfd is set\n", __LINE__);
		}else{
			printf("line %d, before Select, listenfd is NOT  set\n", __LINE__);
		}
		accu = 0;
		for (i = 0; i <= maxi; i++) {	/* check all clients for data */
			if ( (sockfd = client[i]) < 0)
				continue;
			if (FD_ISSET(sockfd, &rset)) {
				accu += 1;
			}
		}
		printf(" before select, line %d, accumulated sockfd total number in set= %d\n", __LINE__, accu);
#endif
		nready = Select(maxfd+1, &rset, NULL, NULL, NULL); // if Select is waken by sockfd, listen in rset will be cleared
// if Select is woken by listenfd, all flags about sockfd is cleared:  before Select: x/8bx &rset 0x7fffffffc180: 0x78, after Select: x/8bx &rset 0x7fffffffc180: 0x08
#ifdef MYDEBUG
		printf("after select called, nready=%d\n", nready);
		if (FD_ISSET(listenfd, &rset)) {	/* new client connection */
			printf("line %d, after Select, listenfd is set\n", __LINE__);
		}else{
			printf("line %d, after Select, listenfd is NOT  set\n", __LINE__);
		}
		accu = 0;
		for (i = 0; i <= maxi; i++) {	/* check all clients for data */
			if ( (sockfd = client[i]) < 0)
				continue;
			if (FD_ISSET(sockfd, &rset)) {
				accu += 1;
			}
		}
		printf(" before select, line %d, accumulated sockfd total number in set= %d\n", __LINE__, accu);
#endif
		if (FD_ISSET(listenfd, &rset)) {	/* new client connection */
		#ifdef MYDEBUG
		printf("new connection connected \n");
		#endif
			clilen = sizeof(cliaddr);
			connfd = Accept(listenfd, (SA *) &cliaddr, &clilen);
		#ifdef MYDEBUG
		printf("connfd = %d\n", connfd);
		#endif
		#ifdef MYDEBUG
		if (FD_ISSET(listenfd, &rset)) {	/* new client connection */
			printf("line %d, after Accept, listenfd is set\n", __LINE__);
		}else{
			printf("line %d, after Accept, listenfd is NOT set\n", __LINE__);
		}
		#endif
		#ifdef	NOTDEF
			char dst[16];
			printf("new client: %s, port %d\n",
					Inet_ntop(AF_INET, &cliaddr.sin_addr, dst, sizeof(dst)),
					ntohs(cliaddr.sin_port));
		#endif

			for (i = 0; i < FD_SETSIZE; i++)
				if (client[i] < 0) {
					client[i] = connfd;	/* save descriptor */
					break;
				}
		#ifdef MYDEBUG
			for(int idx=0; idx < FD_SETSIZE; ++ idx){
				if(client[idx] >= 0){
					printf("client[%d]=%d ",idx, client[idx]);
				}
			}
			printf("\n");
		#endif
			if (i == FD_SETSIZE)
				err_quit("too many clients");

			FD_SET(connfd, &allset);	/* add new descriptor to set */
		#ifdef MYDEBUG
		if (FD_ISSET(listenfd, &rset)) {	/* new client connection */
			printf("line %d,  after FD_SET(connfd) , listenfd is set\n", __LINE__);
		}else{
			printf("line %d, after FD_SET(connfd), listenfd is NOT set\n", __LINE__);
		}
		#endif
			if (connfd > maxfd)
				maxfd = connfd;			/* for select */
			if (i > maxi)
				maxi = i;				/* max index in client[] array */

			if (--nready <= 0){
		#ifdef MYDEBUG
				printf("line=%d, after --nready, nready=%d\n", __LINE__, nready);
		#endif
				continue;				/* no more readable descriptors */
			}
		}

		#ifdef MYDEBUG
		if (FD_ISSET(listenfd, &rset)) {	/* new client connection */
			printf("line %d, before read from client, listenfd is set\n", __LINE__);
		}else{
			printf("line %d, before read from client, listen is NOT set\n", __LINE__);
		}
		#endif
		for (i = 0; i <= maxi; i++) {	/* check all clients for data */
			if ( (sockfd = client[i]) < 0)
				continue;
			if (FD_ISSET(sockfd, &rset)) {
		#ifdef MYDEBUG
				printf("BEFORE call Read\n");
		#endif
				if ( (n = Read(sockfd, buf, MAXLINE)) == 0) {
						/*4connection closed by client */
					Close(sockfd);
					FD_CLR(sockfd, &allset);
					client[i] = -1;
				} else
		#ifdef MYDEBUG
				printf("AFTER  Read returns, BEFORE call Writen, n=Read()=%d\n", n);
		#endif
					Writen(sockfd, buf, n);

				if (--nready <= 0)
					break;				/* no more readable descriptors */
			}
		}
		#ifdef MYDEBUG
		if (FD_ISSET(listenfd, &rset)) {	/* new client connection */
			printf("line %d, after read from client, listenfd is set\n", __LINE__);
		}else{
			printf("line %d, after read from client , listenfd is NOT set\n", __LINE__);
		}
		#endif
	}
}
/* end fig02 */
