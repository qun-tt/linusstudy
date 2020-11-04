#include"my.h"
int main(void){
	char ch='1',p;
	while(ch>='1' && ch<='4'){
		system("clear");
		printf("1:从键盘写入到文件\n2:从文件显示到屏幕\n3:对文件里的数据按姓名进行排序\n4:随机生成一条通讯录数据并写入文件\n其他:退出程序\n请输入数字进行操作:");
		scanf(" %c",&ch);
		if(ch=='1'){
			input();
		}
		else if(ch == '2'){
			output();
		}
		else if(ch=='3'){
			mysort();
			output();
		}
		else if(ch=='4'){
			randdat();
			output();
		}
		else break;
		printf("按回车键继续...");
		getchar();
		getchar();

	}
	return 0;
}
