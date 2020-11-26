#include "./ch10.h"
int main()
{
	pid_t pid;
	pid =fork();
	if(pid<0)
	{
		printf("error!\n");
		exit(-1);
	}
	else if(pid==0)
	{
		pid_t pid1;
		pid1=fork();
		if(pid1<0)
		{
			printf("error!\n");
	                exit(-1);
		}
		else if(pid1==0)
		{
			printf("child1 %d is running!\n",getpid());
			while(1);
		}
		else
		{
			getchar();
			printf("child %d is running!\n",getpid());
			return 99;
		}
	}
	else
	{
		getchar();
		printf("parent %d will exit now!\n",getpid());
		return 107;
	}
	return 0;
}
