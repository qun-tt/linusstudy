#include "./ch09.h"
int main()
	{
	int pid1,pid2;
	int fd;
	fd=open( "test2.txt",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR,0777);
	if(((pid1=fork())<0)||((pid2=fork())<0)){
	perror( "fork error ! \n" );
	}
	else if(pid1==0)
	{
	printf( " \n" );
	printf( "child1 running! pid=%d\n",getpid());
	for(int i=0;i<10;i++){
	char b[1000]="";
	sprintf(b, "pid:%dchild1: %d\n" ,getpid(),i);
	printf( " %s ",b);
	write(fd,b,strlen(b));
	}
	printf( " \n");
	exit(0);
	}
	else if(pid2==0){
	printf( "\n");
	printf( "chiid2 running! pid=%d\n" ,getpid());

	for(int i=0;i<10;i++)
	{
		char c[1000]="";
		sprintf(c,"pid: %dchild2: %d\n",getpid(),i);printf( " %s ",c);
		write(fd,c,strlen(c));
	}
		printf( "\n " );
		exit(0);
	}else
	{
	wait(&pid1);
	wait(&pid2);
	fd=open( "test2.txt",O_RDONLY);
	char d[10000]="";
	printf( " \n " );
	printf( "parent running! pid=%d\n " ,getpid());read(fd,d,sizeof(d));
	printf(" %s\n" ,d);
	printf( " \n");
	exit(0);
	}
	return 0;
}

