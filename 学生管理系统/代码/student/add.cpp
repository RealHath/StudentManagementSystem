#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern void login();
extern void select();


struct Student
{
	char name[20];
	char sex[10];
	char num[30];
	char clas[20];
	char birthday[20];
	char tel[20];
	char address[30];
	float cyuyan;
	float gaoshu;
	float yingyu;
	float xiandai;
	float total;
}stu[100];

void add()
{
	system("cls");
	FILE *tp;
	char sign='y',s[30];
	int sjl;		//ѧ����
	int i,j,a;
	for(i=sjl=0;sign!='n'&&sign!='N';i++,sjl++)
	{
		printf("\n����ѧ��������");
		scanf("%s",stu[i].name);
		printf("\n����ѧ���Ա�");
		scanf("%s",stu[i].sex);
		printf("\n����ѧ��ѧ�ţ�");
		scanf("%s",stu[i].num);
		
		strcpy(s,stu[i].num);
		for(j=0;j<=i;j++)
		{
			a=strcmp(s,stu[j].num);
			getchar();
			if(a)
			{
				printf("\n��ѧ���Ѵ��ڣ�\n");
				system("pause");
				tp=fopen("studentdata.txt","a");		//׷�ӣ����ı��ļ�β�������,û���ļ����½�
				if(tp==NULL)
				{
					printf("\n�޷��򿪴��ļ�");
					return;
				}

				for(i=0;i<sjl;i++)
				{
					fprintf(tp,"%s %s %s %s %s %s %s %f %f %f %f %f\n",stu[i].name,stu[i].sex,stu[i].num,stu[i].clas,stu[i].birthday,stu[i].tel,stu[i].address,stu[i].cyuyan,stu[i].gaoshu,stu[i].yingyu,stu[i].xiandai,stu[i].total);
				}

				fclose(tp);
				system("pause");
				system("cls");
				login();
				select();
			}		//����ظ�ѧ��δ���
		}
		getchar();
		printf("\n����ѧ���༶��");
		scanf("%s",stu[i].clas);
		printf("\n����ѧ�����գ�");
		scanf("%s",stu[i].birthday);
		printf("\n����ѧ����ϵ���룺");
		scanf("%s",stu[i].tel);
		printf("\n����ѧ����ͥסַ��");
		scanf("%s",stu[i].address);
		printf("\n����ѧ��C���Գɼ���");
		scanf("%f",&stu[i].cyuyan);
		printf("\n����ѧ�������ɼ���");
		scanf("%f",&stu[i].gaoshu);
		printf("\n����ѧ��Ӣ��ɼ���");
		scanf("%f",&stu[i].yingyu);
		printf("\n����ѧ���ߴ��ɼ���");
		scanf("%f",&stu[i].xiandai);
		stu[i].total=stu[i].xiandai+stu[i].cyuyan+stu[i].gaoshu+stu[i].yingyu;
		getchar();
		printf("\n�Ƿ����¼����Ϣ����y/n��");
		scanf("%c",&sign);
		system("cls");			//��������
	}
	getchar();

	tp=fopen("studentdata.txt","a");		//׷�ӣ����ı��ļ�β�������,û���ļ����½�
	if(tp==NULL)
	{
		printf("\n�޷��򿪴��ļ�");
		return;
	}

	for(i=0;i<sjl;i++)
	{
		fprintf(tp,"%s %s %s %s %s %s %s %f %f %f %f %f\n",stu[i].name,stu[i].sex,stu[i].num,stu[i].clas,stu[i].birthday,stu[i].tel,stu[i].address,stu[i].cyuyan,stu[i].gaoshu,stu[i].yingyu,stu[i].xiandai,stu[i].total);
	}

	fclose(tp);

	if(sign=='n'||sign=='N')
	{
		system("cls");
		login();
		select();
	}

}