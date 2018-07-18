#include<stdio.h>
int main(int argc, char **argv)
{
	FILE * fp1 = fopen("n3_learnIO.txt", "w");
	char *str = "aBfffb";
	int ret = fputs(str, fp1);
	printf("ret by fputs=%d\n",ret);
	if ( fclose(fp1)!= 0){
		printf("close error\n");
		return 1;
	}
	return 0;
}
