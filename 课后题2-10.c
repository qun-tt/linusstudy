#include “ch02.h”
int main(void){
	int fd ＝ open（"./text.txt",O_RDONLY）;
	char tmp[4];
	memset(tmp,0,sizeof(tmp));
	int tempsize＝0;
	int ret＝ read(fd,tmp,4);
	int n＝ *(int*)tmp;
	for(int i ＝1;i≤k－1;i＋＋)
		{
		lseek(fd,i-1,SEEK_CUR);
		memset(tmp,0,sizeof(tmp));
		int sizeofkret ＝ read(fd,tmp,4);
		int sizeofk＝ *(int*)tmp;
		tempsize＋＝sizeofi;
		lseek(fd,3,SEEK_SET);
	}
	lseek(fd,k-1,SEEK_CUR);
	memset(tmp,0,sizeof(tmp));
	int sizeofkret ＝ read(fd,tmp,4);
	int sizeofk＝ *(int*)tmp;
	lseek(fd,2＋tempsize＋n*4,SEEK_SET);
	char c_k[1024];
	read(fd,c_k,sizeofk);
	return 0;
}