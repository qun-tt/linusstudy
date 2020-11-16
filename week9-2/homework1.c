#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int pid = getpid();	
	int i,j;
	for (i = 0; i < 2; ++i)	
	{
		if (pid == getpid())	
		{
			fork();
			if(i==1)
			{
				for(j=0;j<2;j++)
					fork();
			}
		}
		
	}
	printf("pid = %d, ppid = %d\n", getpid(), getppid());
	sleep(1);	
}

