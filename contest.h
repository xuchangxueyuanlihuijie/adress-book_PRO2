//#define MAX 1000//���ͨѶ¼������
#define MAX_SEX 10//����Ա������
#define MAX_NAME 20//������ֵ�����
#define MAX_NUMBER 12 //���绰���������
#define MAX_ADRESS 20//����ַ������
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
//ö������
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
//��������ͨѶ¼������
struct contest
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char number[MAX_NUMBER];
	char adress[MAX_ADRESS];
	int age;
};
//����ͨѶ¼����
struct haha
{
	struct contest *data;
	int size;
	int capacity;
};
//��ʼ������
void chushihua(struct haha*psp);
//����ͨѶ¼
void set(struct haha*psp);
//չʾͨѶ¼
void show(const struct haha *psp);
//ɾ��ͨѶ¼
void del(struct haha *psp);
//����ͨѶ¼
void seach(const struct haha *psp);
//�޸�ͨѶ¼
void modify(struct haha *psp);
//ð������qsort����
void qsort(struct contest*psp, int number, int with, int (*comp)(void*e1, void*e2));
//�ȽϺ���
int comp(void*e1, void*e2);
//����
void destroycontact(struct haha *psp);
//�洢
void storage(struct haha*psp);
