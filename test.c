#define _CRT_SECURE_NO_WARNINGS 1
#include"contest.h"//�����Լ���ͷ�ļ�
void mune()
{
	printf("*********************************\n");
	printf("****1.set                2.del****\n");
	printf("****3.search            4.modify*\n");
	printf("****5.show              6.sort***\n");
	printf("****0.exit              *********\n");
	printf("**********��0Ϊ�����ļ�**********\n");
}
int main()
{
	int intput = 0;
	struct haha con;
	chushihua(&con);
	do
	{
		mune();
		printf("����������ѡ�����ͣ�");
		scanf("%d", &intput);
		switch (intput)
		{
		case SET:
			set(&con);//����ͨѶ¼
			fflush(stdin);
			break;
		case DEL:
			del(&con);//ɾ��ͨѶ¼
			fflush(stdin);
			break;
		case SEARCH:
			seach(&con);//����ͨѶ¼
			fflush(stdin);
			break;
		case MODIFY:
			modify(&con);//�޸�ͨѶ¼
			fflush(stdin);
			break;
		case SHOW:
			show(&con);//չʾͨѶ¼
			fflush(stdin);
			break;
		case SORT://ð������
			qsort(con.data,con.size,sizeof(con.data[0]),comp);//qsort����
			fflush(stdin);
			break;
		case EXIT:
			break;
		default:
			printf("����������");
			fflush(stdin);
			break;
			fflush(stdin);
		}
	} while (intput);
	system("pause");
	storage(&con);
	destroycontact(&con);
	return 0;
}