#define _CRT_SECURE_NO_WARNINGS 1
#include"contest.h"//�����Լ���ͷ�ļ�
//����ͨѶ¼�е�����
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
//��ʼ������
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
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("%s", strerror(errno));
			printf("���ٿռ����\n");
		}
		
	}
}
//����ͨѶ¼����
void set(struct haha* psp)
{
		kuorong(psp);
		printf("����������:>");
		scanf("%s", psp->data[psp->size].name);
		printf("�������Ա�:");
		scanf("%s", psp->data[psp->size].sex);
		printf("���������䣺");
		scanf("%d", &(psp->data[psp->size].age));
		printf("�������ֻ��ţ�");
		scanf("%s", psp->data[psp->size].number);
		printf("�������ͥסַ��");
		scanf("%s", psp->data[psp->size].adress);
		psp->size++;
		printf("��ӳɹ�\n");		
}
//չʾ����
void show(const struct haha *psp)
{
	if (psp->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-10s\t%-10s\t%-20s\t%-20s\t\n", "����","�Ա�", "����", "�ֻ���", "��ͥסַ");
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
//ɾ������
void del(struct haha *psp)
{
	char b[MAX_NAME];
	printf("����������ѡ�����֣�");
	scanf("%s",b);
	int ret = find(psp, b);
	if (ret==-1)
	{
		printf("��Ա������\n");
	}
	else
	{
		int j = ret;
		for (j = ret; j < psp->size - 1; j++)
			psp->data[j] = psp->data[j + 1];
			psp->size--;
			printf("ɾ���ɹ�\n"); 
	}
}
//���Һ���
void seach(const struct haha *psp)
{
	char b[MAX_NAME] = { 0 };
	printf("����������ѡ������");
	scanf("%s", b);
	int ret = find((const struct haha*)psp, b);
	if (ret == -1)
	{
		printf("ͨѶ¼��û�и��û�");
	}
	else
	{
		printf("%-20s\t%-10s\t%-10s\t%-20s\t%-20s\t\n", "����", "�Ա�", "����", "�ֻ���", "��ͥסַ");
		printf("%-20s\t%-10s\t%-10d\t%-20s\t%-20s\t\n",
			psp->data[ret].name,
			psp->data[ret].sex,
			psp->data[ret].age,
			psp->data[ret].number,
			psp->data[ret].adress);
	}
}
//�޸ĺ���
void modify(struct haha* psp)
{
	char b[MAX_NAME] = { 0 };
	printf("������������");
	scanf("%s", b);
	int ret = find(psp, b);
	if (ret == -1)
	{
		printf("ͨѶ¼��û�и���\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", psp->data[ret].name);
		printf("�������Ա�:>");
		scanf("%s", psp->data[ret].sex);
		printf("����������:>");
		scanf("%d", &(psp->data[ret].age));
		printf("�������ֻ��ţ�>");
		scanf("%s", psp->data[ret].number);
		printf("�������ͥסַ��>");
		scanf("%s", psp->data[ret].adress);
	}
}
//��������
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
//�Ƚ������ַ����ĺ���
int comp(void*e1, void*e2)
{
	return strcmp(((struct contest*)e1)->name,((struct contest*)e2)->name);
}
//qsort������ʵ��
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
	printf("�������\n");
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