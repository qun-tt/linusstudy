#include<stdio.h>
#include<stdlib.h>
int main()
{
        int count = 0;
        while (malloc(1 << 20))//一次性分配1M的内存空间
        {
                count++;
                printf("already malloc %d M\n",count);
        }
//      printf("%d\n", count);
        return 0;
}
