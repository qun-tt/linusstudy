#include "../ch08.h"
int main()
{
	
        void *fpt=dlopen("./libdlib.so",RTLD_NOW);
	int a[20]={0};

        if(!fpt){
                printf("dlopen failed!\n");
                exit(1);
        }
        void (*fp1)(void)=dlsym(fpt,"dynamic_lib_dun_call");
	void (*fp2)(int *,int)=dlsym(fpt,"myrand");
	void (*fp3)(int *,int)=dlsym(fpt,"pyprint");
	void (*fp4)(int *,int)=dlsym(fpt,"mysort");
	
        if(!fp1||!fp2||!fp3)
        {
                printf("Dlsym Failde!\n");
                exit(1);
	}
        fp1();
	printf("----------INIT---------\n");
	fp3(a,20);
	sleep(5);
	fp2(a,20);
	printf("----------RAND---------\n");
        fp3(a,20);
        sleep(5);
	printf("----------SORT---------\n");
        fp4(a,20);
        fp3(a,20);

        dlclose(fpt);
	return 0;
}

