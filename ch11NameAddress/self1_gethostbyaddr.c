#include	"unp.h"

int
main(int argc, char **argv)
{
	struct sockaddr_in servaddr;
	char			str[INET_ADDRSTRLEN];
	char			*ptr, **pptr;
	struct hostent * hptr;
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	hptr = gethostbyaddr((const char *)&servaddr.sin_addr, sizeof(servaddr.sin_addr), AF_INET);
	printf("official hostname: %s\n", hptr->h_name);
	for (pptr = hptr->h_aliases; *pptr != NULL; pptr++)
		printf("\talias: %s\n", *pptr);

	pptr = hptr->h_addr_list;
	for ( ; *pptr != NULL; pptr++)
		printf("\taddress: %s\n",
			Inet_ntop(hptr->h_addrtype, *pptr, str, sizeof(str)));
	exit(0);
}
