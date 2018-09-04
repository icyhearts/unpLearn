#include	"unp.h"

int
udp_connect_sin6_scope_id(const char *host, const char *serv, SA **saptr, socklen_t *lenp, int sin6_scope_id)
{
	int				sockfd, n;
	struct addrinfo	hints, *res, *ressave;
	struct sockaddr_in6 *v6addrp;
	bzero(&hints, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;

	if ( (n = getaddrinfo(host, serv, &hints, &res)) != 0)
		err_quit("udp_connect error for %s, %s: %s",
				 host, serv, gai_strerror(n));
	ressave = res;

	do {
		if(res->ai_family == AF_INET6){
			v6addrp = (struct sockaddr_in6 *)res->ai_addr;
			v6addrp->sin6_scope_id = sin6_scope_id;
		}
		sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
		if (sockfd < 0)
			continue;	/* ignore this one */

		if (connect(sockfd, res->ai_addr, res->ai_addrlen) == 0)
			break;		/* success */

		Close(sockfd);	/* ignore this one */
	} while ( (res = res->ai_next) != NULL);

	if (res == NULL)	/* errno set from final connect() */
		err_sys("udp_connect error for %s, %s", host, serv);

	*saptr = Malloc(res->ai_addrlen);
	memcpy(*saptr, res->ai_addr, res->ai_addrlen);
	*lenp = res->ai_addrlen;

	freeaddrinfo(ressave);

	return(sockfd);
}
/* end udp_connect */
int
main(int argc, char **argv)
{
	int				sockfd, n;
	char			recvline[MAXLINE + 1];
	struct sockaddr	*sa;
	socklen_t		salen = sizeof(sa);

	if (argc != 4)
		err_quit("usage: %s <hostname/IPaddress> <service/port#> <sin6_scipe_id>", argv[0]);
	int sin6_scope_id = atoi(argv[3]);

	sockfd = udp_connect_sin6_scope_id(argv[1], argv[2], (SA **) &sa, &salen, sin6_scope_id );


	printf("sending to %s\n", Sock_ntop_host(sa, salen));

	Write(sockfd, "", 1);	/* send 1-byte datagram */

	n = Read(sockfd, recvline, MAXLINE);
	recvline[n] = '\0';	/* null terminate */
	Fputs(recvline, stdout);

	exit(0);
}
