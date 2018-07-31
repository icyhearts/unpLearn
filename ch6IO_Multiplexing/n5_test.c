#define NOTDEF
#include	"unp.h"
#include	<limits.h>		/* for OPEN_MAX */
#define OPEN_MAX 1024
int
main(int argc, char **argv)
{
	int i1 = POLLRDNORM;
	int i2 = POLLERR;
	int i3 = POLLRDNORM | POLLERR;
	int i4 = POLLRDNORM || POLLERR;
	printf("i1=%x\n", i1);
	printf("i2=%x\n", i2);
	printf("i3=%x\n", i3);
	printf("i4=%x\n", i4);
}
/* end fig02 */
