#include "ch3.h"
int main()
{
	FILE* fp;
	int fd;
	char buf[80];
	fd=open("./test1.txt",O_RDWR);
	fp=fdopen(fd,"w+");
	//fprintf(fp,"test data %s\n","hello world");

	 fgets(buf,sizeof(buf),stdin);
	fwrite(buf,1,sizeof(buf),fp);

	fclose(fp);
	return 0;


/*

	FILE* fp;
	int fd;

	fd=open("./test1.txt",O_RDWR);
	fp=fdopen(fd,"w+");
	//fprintf(fp,"test data %s\n","hello world");

	 fprintf(fp,"test data %s \n","hello world");
	fclose(fp);
	return 0;
*/
}
