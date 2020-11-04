#include"my.h"
// 假定数据最大条数为65536
#define MAXN 65536
// PhoneAllocation数组保存手机号前三位
const int PhoneAllocationNum=53;
const int PhoneAllocation[53]={134,135,136,137,138,139,144,147,148,150,151,152,157,158,159,172,178,182,183,184,187,188,195,197,198,130,131,132,145,146,155,156,166,171,175,176,185,186,196,133,141,149,153,173,174,177,180,181,189,190,191,193,199};

// AreaCode数组保存区号
const int AreaCodeNum=323;
const char* AreaCode[323]={"010","021","022","023","024","025","027","028","029","020","0311","0312","0313","0314","0315","0316","0317","0318","0319","0310","0335","0349","0351","0352","0353","0354","0355","0356","0357","0358","0359","0350","0371","0372","0373","0374","0375","0376","0377","0379","0370","0391","0392","0393","0394","0395","0396","0398","0378","0397","0411","0412","0415","0416","0417","0418","0419","0421","0427","0429","0431","0432","0433","0434","0435","0436","0437","0438","0439","0451","0452","0453","0454","0455","0456","0457","0458","0459","0464","0467","0468","0469","0471","0472","0473","0474","0475","0476","0477","0478","0479","0470","0482","0483","0511","0512","0513","0514","0515","0516","0517","0518","0519","0510","0523","0527","0531","0532","0533","0534","0535","0536","0537","0538","0539","0530","0543","0546","0551","0552","0553","0554","0555","0556","0557","0558","0559","0550","0561","0562","0563","0564","0566","0571","0572","0573","0574","0575","0576","0577","0578","0579","0570","0580","0591","0592","0593","0594","0595","0596","0597","0598","0599","0631","0632","0633","0635","0660","0662","0663","0668","0691","0692","0711","0727","0712","0713","0714","0715","0716","0717","0718","0719","0710","0722","0724","0728","0731","0734","0735","0736","0737","0738","0739","0730","0743","0744","0745","0746","0750","0751","0752","0753","0754","0755","0756","0757","0758","0759","0760","0762","0763","0766","0768","0769","0771","0772","0773","0774","0775","0776","0777","0778","0779","0770","0791","0792","0793","0794","0795","0796","0797","0798","0799","0790","0701","0812","0813","0816","0817","0818","0825","0826","0827","0831","0832","0833","0834","0835","0836","0837","0838","0839","0830","0851","0854","0855","0856","0857","0858","0859","0871","0872","0873","0874","0875","0876","0877","0878","0879","0870","0883","0886","0887","0888","0891","0892","0893","0894","0895","0896","0897","0898","0911","0912","0913","0914","0915","0916","0917","0919","0931","0932","0933","0934","0935","0936","0937","0938","0939","0930","0941","0943","0951","0952","0953","0954","0955","0971","0972","0973","0974","0975","0976","0977","0979","0970","0991","0992","0993","0994","0995","0996","0997","0998","0999","0990","0901","0902","0903","0906","0908","0909"};


// input函数将从键盘输入的通讯录数据传入save函数并根据id查重
void input(void){
	int i,n; 	// i为for循环用到的变量,n用来记录键盘输入的信息条数
	int flag; 	// 该flag变量标记id是否重复
	FILE *fp;
	record *u=(record*)malloc(sizeof(record));	// u变量用来存储从键盘读入的通讯录信息
	record *t=(record*)malloc(sizeof(record));	// t变量用来存储从文件中读入的信息
	
	if(access("./user.dat",F_OK)!=0){
		fp=fopen("./user.dat","w");
		fclose(fp);
		fp=NULL;
	}
	fp=fopen("./user.dat","r");
	/*
	while((fp=fopen("./user.dat","r"))==NULL){
		fp=fopen("./user.dat","w");
		fclose(fp);
	}
	*/
	printf("请输入写入通讯录的数据的条数:");
	scanf("%d",&n);
	printf("请依次输入 通讯录的序号 用户名 手机号 电话号码(空格隔开,每组数据用回车换行隔开):\n");
	for(i=0;i<n;i++){
		scanf("%u %s %s %s",&(u->id),u->name,u->htel,u->tel);
		flag=0;
		fseek(fp,0,SEEK_SET);	// 将文件指针移动到文件首部防止，便于输入多条数据时的查重
		while(fscanf(fp,"%u %s %s %s",&(t->id),t->name,t->htel,t->tel)!=EOF){
			if(t->id == u->id){
				flag=1;
				break;
			}
		}
		if(flag == 1){
			printf("序号重复了，请重新输入！\n");
		}
		else{
			save(u,"a");
		}
	}
	fclose(fp);
	fp=NULL;
	free(t);
	t=NULL;
	free(u);
	u=NULL;
	return;
}

void save(record* u,const char* mode){
	FILE *fp=fopen("./user.dat",mode);
	fprintf(fp,"%u %s %s %s\n",u->id,u->name,u->htel,u->tel);
	fclose(fp);
	fp=NULL;
}


//1为升序2为降序
int cmpById1(const void* a,const void* b){
	return ((record*)a)->id<((record*)b)->id?-1:1;
}
int cmpById2(const void* a,const void* b){
	return ((record*)b)->id<((record*)a)->id?-1:1;
}
int cmpByName1(const void* a,const void* b){
	return strcmp(((record*)a)->name,((record*)b)->name);
}
int cmpByName2(const void* a,const void* b){
        return strcmp(((record*)b)->name,((record*)a)->name);
}


void mysort(void){
	unsigned int i=0;
	FILE *fp;
	int flag=0;
	/*
	if((fp=fopen("./user.dat","r"))==NULL){
		printf("通讯录为空！\n");
		fp=fopen("./user.dat","w");
		fclose(fp);
		return;
	}
	*/
	if(access("./user.dat",F_OK)!=0){
		fp=fopen("./user.dat","w");
		fclose(fp);
		fp=NULL;
	}
	fp=fopen("./user.dat","r");
	record* s=(record*)calloc(MAXN,sizeof(record));
	while(fscanf(fp,"%u %s %s %s",&(s[i].id),s[i].name,s[i].htel,s[i].tel)!=EOF){
		i++;
	}
	fclose(fp);
	fp=NULL;
	printf("请输入数字表示排序方式(1:升序 2:降序 其他:取消):");
	scanf("%d",&flag);
	if(flag==1){
		int x=0;
		qsort(s,i,sizeof(record),cmpByName1);
		for(x=0;x<i;x++){
			if(x==0) save(&s[x],"w");
			else save(&s[x],"a");
		}
	}
	else if(flag==2){
		int x=0;
		qsort(s,i,sizeof(record),cmpByName2);
		for(x=0;x<i;x++){
			if(x==0) save(&s[x],"w");
			else save(&s[x],"a");
		}
	}
	free(s);
	s=NULL;
	return;
}

void randdat(void){
	printf("正在生成随机通讯录信息...\n");
	record* u=(record*)malloc(sizeof(record));
	record* rt=(record*)malloc(sizeof(record));
	int i,t,lenName,flag;
	char name1[2]={"A"},name2[2]={"a"};
	char beg1[5],end1[8];
	char beg2[4],end2[9];
	FILE *fp;
	/*
	while((fp=fopen("./user.dat","r"))==NULL){
		fp=fopen("./user.dat","w");
		fclose(fp);
		fp=NULL;
	}
	*/
	if(access("./user.dat",F_OK)!=0){
		fp=fopen("./user.dat","w");
		fclose(fp);
		fp=NULL;

	}
	fp=fopen("./user.dat","r");
	//对u的成员属性进行初始化
	u->id=0;
	strcpy(u->name,"");
	strcpy(u->htel,"");
	strcpy(u->tel,"");
	//生成随机数种子
	srand(time(NULL));
	//随机生成id,然后判断是否重复
	flag=1;
	while(flag==1){
		flag=0;
		u->id=rand();
		u->id=u->id+rand();
		while(fscanf(fp,"%d %s %s %s",&(rt->id),rt->name,rt->htel,rt->tel)!=EOF){
			if(u->id == rt->id){
				flag=1;
				break;
			}
		}
	}
	fclose(fp);
	free(rt);
	rt=NULL;


	//随机生成姓名
	lenName = 1 + rand()%7;//姓名长度不能为0
	for(i = 0;i < lenName;i++){
		t=rand()%26;
		if(i==0){
			name1[0]=name1[0]+t;
			strcat(u->name,name1);
			name1[0]='A';
		}
		else{
			name2[0]=name2[0]+t;
			strcat(u->name,name2);
			name2[0]='a';
		}
	}
	//随机生成区号，并判断是否合法
	flag=0;
	while(flag != 1){
		t=rand()%1000;
		if(t<30) sprintf(beg1,"%03d",t);
		else sprintf(beg1,"%04d",t);
		for(i=0;i<AreaCodeNum;i++){
			if(strcmp(beg1,AreaCode[i])==0){
				flag=1;
			}
		}
	}
	//随机生成座机号（由于有的地区座机号为8位，有的为7位，判断起来太麻烦，所以统一设置为7位）
	t=rand()%10000000;
	sprintf(end1,"%07d",t);
	//将区号-座机号按格式放入u->htel中
	strcat(u->htel,beg1);
	strcat(u->htel,"-");
	strcat(u->htel,end1);
	//随机生成手机号
	flag=0;
	while(flag != 1){
		t=100+rand()%100;
		for(i=0;i<PhoneAllocationNum;i++){
			if(t==PhoneAllocation[i]){
				flag=1;
			}
		}
	}
	sprintf(beg2,"%d",t);
	t=rand()%100000000;
	sprintf(end2,"%08d",t);
	//将手机号写入u->tel中
	strcat(u->tel,beg2);
	strcat(u->tel,end2);
	
	printf("成功生成随机通讯录信息并写入文件！\n");
	save(u,"a");
	free(u);
	u=NULL;
}

void output(void){
	int i;
	record *u=(record*)malloc(sizeof(record));
	FILE *fp;
	/*
	while((fp=fopen("./user.dat","r"))==NULL){
		fp=fopen("./user.dat","w");
		fclose(fp);
		fp=NULL;
	}
	*/
	if(access("./user.dat",F_OK)!=0){
		fp=fopen("./user.dat","w");
		fclose(fp);
		fp=NULL;
	}
	fp=fopen("./user.dat","r");
	printf("userid      name     htel            tel\n");
	while(fscanf(fp,"%u %s %s %s ",&u->id,u->name,u->htel,u->tel)!=EOF){
		printf("%-12u%s  %s    %s\n",u->id,u->name,u->htel,u->tel);
	}
	fclose(fp);
}

