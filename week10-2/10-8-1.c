#include "ch06.h"
void pr_exit(int status,pid_t pid)
{
	int sig;
	if(WIFEXITED(status))
		printf("process %d normal termination ,exit status=%d\n",pid,WEXITSTATUS(status));
	else if(WEXITSTATUS(status)){
		sig=WTEERMSIG(status);
		printf("process %d abnormal termination,signal number=%d%s",pid,sig,
#ifdef WCOREDUMP
				WCOREDUMP(status)?"(core file generated)":"");
#else
			"");

	}
}
