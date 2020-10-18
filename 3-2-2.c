#include "ch3.h"
int main()
{
	FILE* fd;
	fd = fopen("./test1.txt","w");
	printf("file fd = %d \n",fd->_fileno);
	fclose(fd);
	return 0;
}
