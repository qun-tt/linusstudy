#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<unistd.h>


typedef struct user{
	unsigned int id;
	char name[9];
	char htel[13];
	char tel[13];
}record;
void input(void);
void save(record*,const char*);
void mysort(void);
void randdat(void);
void output(void);
