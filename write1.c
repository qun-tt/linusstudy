#include "ch03.h"
int main()
{
	int n,i,fd;
	char buf;
	fd=open("./test.dat",O_CREAT|O_TRUNC|O_WRONLY,0644);
	for(i=0;i<2;i++)
	{
		srand(time(0));
		n=rand()%26;
		buf=(char)('a'+n);
		write(fd,&buf,1);
		sleep(50);
	}
	close(fd);
}
