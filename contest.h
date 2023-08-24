//#define MAX 1000//最大通讯录的数量
#define MAX_SEX 10//最大性别的数量
#define MAX_NAME 20//最大名字的数量
#define MAX_NUMBER 12 //最大电话号码的数量
#define MAX_ADRESS 20//最大地址的数量
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
//枚举类型
enum number
{
	EXIT,
	SET,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
//创建单个通讯录的内容
struct contest
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char number[MAX_NUMBER];
	char adress[MAX_ADRESS];
	int age;
};
//创建通讯录数组
struct haha
{
	struct contest *data;
	int size;
	int capacity;
};
//初始化变量
void chushihua(struct haha*psp);
//创建通讯录
void set(struct haha*psp);
//展示通讯录
void show(const struct haha *psp);
//删除通讯录
void del(struct haha *psp);
//查找通讯录
void seach(const struct haha *psp);
//修改通讯录
void modify(struct haha *psp);
//冒泡排序qsort函数
void qsort(struct contest*psp, int number, int with, int (*comp)(void*e1, void*e2));
//比较函数
int comp(void*e1, void*e2);
//销毁
void destroycontact(struct haha *psp);
//存储
void storage(struct haha*psp);
