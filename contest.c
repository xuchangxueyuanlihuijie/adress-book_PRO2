#define _CRT_SECURE_NO_WARNINGS 1
#include"contest.h"//引用自己的头文件
//查找通讯录中的名字
static int find(const struct haha*psp, char b[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < psp->size; i++)
	{
		if (0 == strcmp(psp->data[i].name, b))
		{
			break;
		}
	}
	if (i < psp->size)
	{
		return i;
	}
	else
	{
		return -1;
	}
}
void kuorong(struct haha*psp);
void kuozhang(struct haha*psp);
//初始化函数
void chushihua(struct haha* psp)
{
	struct contest* uiu = (struct contest*)malloc(sizeof(struct contest) * 3);
	if (uiu != NULL)
	{
		psp->data = uiu;
		psp->size = 0;
		psp->capacity = 3;
		kuozhang(psp); 
	}
	else
	{
		printf("%s\n", strerror(errno));
		system("pause");
	}
	
}
void kuozhang(struct haha*psp)
{
	struct contest tmp = { 0 };
	FILE* pfread = fopen("text.dat", "rb");
	if (pfread == NULL)
	{
		printf("Loadcontest:%s\n", strerror(errno));
		return;
	}
	while (fread(&tmp, sizeof(struct contest), 1, pfread))
	{
		kuorong(psp);
		psp->data[psp->size] = tmp;
		psp->size++;
		
	}
}
void kuorong(struct haha*psp)
{
	if (psp->size == psp->capacity)
	{
		struct contest*mok = (struct contest*)realloc(psp->data, sizeof(struct contest) * (psp->capacity+2));
		psp->capacity += 2;
		if (mok != NULL)
		{
			psp->data = mok;
			printf("扩容成功\n");
		}
		else
		{
			printf("%s", strerror(errno));
			printf("开辟空间错误\n");
		}
		
	}
}
//创立通讯录函数
void set(struct haha* psp)
{
		kuorong(psp);
		printf("请输入姓名:>");
		scanf("%s", psp->data[psp->size].name);
		printf("请输入性别:");
		scanf("%s", psp->data[psp->size].sex);
		printf("请输入年龄：");
		scanf("%d", &(psp->data[psp->size].age));
		printf("请输入手机号：");
		scanf("%s", psp->data[psp->size].number);
		printf("请输入家庭住址：");
		scanf("%s", psp->data[psp->size].adress);
		psp->size++;
		printf("添加成功\n");		
}
//展示函数
void show(const struct haha *psp)
{
	if (psp->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-10s\t%-10s\t%-20s\t%-20s\t\n", "名字","性别", "年龄", "手机号", "家庭住址");
		for (i = 0; i < psp->size; i++)
		{
			printf("%-20s\t%-10s\t%-10d\t%-20s\t%-20s\t\n",
				 psp->data[i].name,
				 psp->data[i].sex,
				 psp->data[i].age,
				 psp->data[i].number,
				 psp->data[i].adress);
		}
	}
}
//删除函数
void del(struct haha *psp)
{
	char b[MAX_NAME];
	printf("请输入相信选的名字：");
	scanf("%s",b);
	int ret = find(psp, b);
	if (ret==-1)
	{
		printf("人员不存在\n");
	}
	else
	{
		int j = ret;
		for (j = ret; j < psp->size - 1; j++)
			psp->data[j] = psp->data[j + 1];
			psp->size--;
			printf("删除成功\n"); 
	}
}
//查找函数
void seach(const struct haha *psp)
{
	char b[MAX_NAME] = { 0 };
	printf("请输入你想选的名字");
	scanf("%s", b);
	int ret = find((const struct haha*)psp, b);
	if (ret == -1)
	{
		printf("通讯录中没有该用户");
	}
	else
	{
		printf("%-20s\t%-10s\t%-10s\t%-20s\t%-20s\t\n", "名字", "性别", "年龄", "手机号", "家庭住址");
		printf("%-20s\t%-10s\t%-10d\t%-20s\t%-20s\t\n",
			psp->data[ret].name,
			psp->data[ret].sex,
			psp->data[ret].age,
			psp->data[ret].number,
			psp->data[ret].adress);
	}
}
//修改函数
void modify(struct haha* psp)
{
	char b[MAX_NAME] = { 0 };
	printf("请输入姓名：");
	scanf("%s", b);
	int ret = find(psp, b);
	if (ret == -1)
	{
		printf("通讯录中没有该人\n");
	}
	else
	{
		printf("请输入姓名:>");
		scanf("%s", psp->data[ret].name);
		printf("请输入性别:>");
		scanf("%s", psp->data[ret].sex);
		printf("请输入年龄:>");
		scanf("%d", &(psp->data[ret].age));
		printf("请输入手机号：>");
		scanf("%s", psp->data[ret].number);
		printf("请输入家庭住址：>");
		scanf("%s", psp->data[ret].adress);
	}
}
//交换函数
void smp(char*pe, char*p2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = 0;
		tmp = *pe;
		*pe = *p2;
		*p2 = tmp;
		p2++;
		pe++;
	}
}
//比较名字字符串的函数
int comp(void*e1, void*e2)
{
	return strcmp(((struct contest*)e1)->name,((struct contest*)e2)->name);
}
//qsort函数的实现
void qsort(struct contest*psp, int size, int width, int(*comp)(void*e1, void*e2))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < size-1; i++)
	{
		for (j = 0; j < size-1-i;j++)
			if (comp((char*)psp+j*width, (char*)psp+(j+1)*width) > 0)
			{
				smp((char*)psp+j*width, (char*)psp+(j+1)*width, width);
			}
	}
	printf("排序完成\n");
}
void destroycontact(struct haha *psp)
{
	free(psp->data);
	psp->data = NULL;
}
void storage(struct haha* psp)
{
	int i = 0;
	FILE* pf = fopen("text.dat", "wb");
	if (pf == NULL)
	{
		printf("storage:%s\n", strerror(errno));
		return;
	}
	for (i = 0; i < psp->size; i++)
	{
		fwrite(&(psp->data[i]), sizeof(struct contest), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}