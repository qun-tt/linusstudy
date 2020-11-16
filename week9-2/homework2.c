#include"./ch09.h"
int g=0;
int main()
{

        printf("My pid is %d\n", getpid());
        int fd_out;
        fd_out=open("./out.dat",O_CREAT|O_WRONLY);
        char buf[1024];
        memset(buf,0,1024);
        pid_t pid;
//      bool flag = false;
        int i=0, j=0;
        g++;
        sprintf(buf,"%d :%d\n",getpid(),g);
        write(fd_out,buf,strlen(buf));

         memset(buf,0,1024);
        for( i=0; i<2; ++i) {
                pid = fork();
                if(pid == 0) {
                        printf("My pid is %d, my parent's pid is %d\n", getpid(), getppid());
                        g++;
                        sprintf(buf,"%d :%d\n",getpid(),g);
                          write(fd_out,buf,strlen(buf));

                         memset(buf,0,1024);
                        if( i == 0) {

                                for( j=0; j<2; ++j) {
                                        pid_t pid1=fork();
                                        if(pid1 == 0) {
                                                g++;
                                                sprintf(buf,"%d :%d\n",getpid(),g);
                                                 write(fd_out,buf,strlen(buf));

                                                   memset(buf,0,1024);
                                                printf("My pid is %d, my parent's pid is %d\n", getpid(), getppid());
                                                exit(0);
                                        }
                                        else {
                                                printf("Process %d create %d\n", getpid(), pid);
                                        }
                                        sleep(1);
                                }
                        }
                        exit(0);
                }
                else {
                        printf("Process %d create %d\n", getpid(), pid);
                }
                sleep(1);
        }



}
