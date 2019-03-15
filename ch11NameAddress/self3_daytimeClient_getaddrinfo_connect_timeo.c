#include	"unp.h"
/*
 * use connect_timeo in page 382
 */

int
tcp_connectSelf(const char *host, const char *serv, int sin6_scope_id)
{
	int				sockfd, n;
	struct addrinfo	hints, *res, *ressave;
	struct sockaddr_in6 * v6addrp;
	bzero(&hints, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if ( (n = getaddrinfo(host, serv, &hints, &res)) != 0)
		err_quit("tcp_connect error for %s, %s: %s",
				 host, serv, gai_strerror(n));
	ressave = res;

	do {
		sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
		if (sockfd < 0)
			continue;	/* ignore this one */
		if(res->ai_family == AF_INET6){
			v6addrp = (struct sockaddr_in6 *)res->ai_addr;
			v6addrp->sin6_scope_id = sin6_scope_id;
		}
//		if (connect(sockfd, res->ai_addr, res->ai_addrlen) == 0)
// same as self2_daytimeClient_getaddrinfo.c, except that use connect_timeo to set time out
		if (connect_timeo(sockfd, res->ai_addr, res->ai_addrlen, 5) == 0)
			break;		/* success */

		Close(sockfd);	/* ignore this one */
	} while ( (res = res->ai_next) != NULL);

	if (res == NULL)	/* errno set from final connect() */
		err_sys("tcp_connect error for %s, %s", host, serv);

	freeaddrinfo(ressave);

	return(sockfd);
}
int
main(int argc, char **argv)
{
	int				sockfd, n;
	char			recvline[MAXLINE + 1];
	socklen_t		len;
	struct sockaddr_storage	ss;

	if (argc != 4)
		err_quit("usage: daytimetcpcli <hostname/IPaddress> <service/port#> <sin6_scipe_id>");
	int sin6_scope_id = atoi(argv[3]);
	sockfd = tcp_connectSelf(argv[1], argv[2], sin6_scope_id);
	
	len = sizeof(ss);
	Getpeername(sockfd, (SA *)&ss, &len);
	printf("connected to %s\n", Sock_ntop_host((SA *)&ss, len));

	while ( (n = Read(sockfd, recvline, MAXLINE)) > 0) {
		recvline[n] = 0;	/* null terminate */
		Fputs(recvline, stdout);
	}
	exit(0);
}
