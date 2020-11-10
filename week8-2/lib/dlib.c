#include "../ch08.h"
void dynamic_lib_fun_call(void)
{
	printf("Dynamic Lib Fun Called!\n");
}
void mysort(int *a,int n)
{
	int i,j,t;
	for(i=1;i<n-1;i++)
	{
		for(j=j+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
			
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
}
void myrand(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		srand((unsigned)time(NULL));
		a[i]=rand()%(100-1+1)+1;
	}
}
void pyprint(int *a,int n)
{
	for(int i=0;i<n;i++)
		printf("a[%d]=%d\n",i,a[i]);
}
