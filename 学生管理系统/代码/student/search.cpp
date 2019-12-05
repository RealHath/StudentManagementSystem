#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern void login();
extern void select();
extern void modify();

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
}s1[100];

void search()
{
	int a,i=0;
	FILE *tp;
	char s[30],sign=' ';
	int sjl=0;		//ѧ����

	if((tp=fopen("studentdata.txt","r"))==NULL)
	{
		printf("�޷����ļ�");
		return;
	}

	while(fscanf(tp,"%s %s %s %s %s %s %s %f %f %f %f %f\n",s1[i].name,s1[i].sex,s1[i].num,s1[i].clas,s1[i].birthday,s1[i].tel,s1[i].address,&s1[i].cyuyan,&s1[i].gaoshu,&s1[i].yingyu,&s1[i].xiandai,&s1[i].total)!=EOF)
	{
		i++;
		sjl++;
	}
	fclose(tp);

	printf("��ѡ���ѯ��ʽ��\n");
	printf("1��������������\n");
	printf("2������ѧ�Ų�ѯ\n");
	printf("3�����ز˵�\n");
	scanf("%d",&a);
	getchar();


	if(a==1)
	{
		printf("���������֣�");
		scanf("\t%s",s);
		getchar();

		for(i=0;i<sjl;i++)
		{
			if(strcmp(s,s1[i].name)==0)
			{
				printf("\nѧ��������%s",s1[i].name);
				printf("\nѧ���Ա�%s",s1[i].sex);
				printf("\nѧ��ѧ�ţ�%s",s1[i].num);
				printf("\nѧ���༶��%s",s1[i].clas);
				printf("\nѧ�����գ�%s",s1[i].birthday);
				printf("\nѧ����ϵ���룺%s",s1[i].tel);
				printf("\nѧ����ͥסַ��%s",s1[i].address);
				printf("\nѧ��C���Գɼ���%f",s1[i].cyuyan);
				printf("\nѧ�������ɼ���%f",s1[i].gaoshu);
				printf("\nѧ��Ӣ��ɼ���%f",s1[i].yingyu);
				printf("\nѧ���ߴ��ɼ���%f",s1[i].xiandai);
				printf("\n�ܷ֣�%f\tƽ���֣�%f\n",s1[i].total,s1[i].total/4.0);
				break;
			}
		}
		if(i==sjl)
		{
			printf("���޴���\n\n");
			system("pause");
			system("cls");
			login();
			select();
		}
		printf("\n�Ƿ���Ҫ�޸ģ���y/n��");
		for(;;)
		{
			sign=getchar();
			getchar();
			switch(sign)
			{
				case 'n':
				case 'N':system("cls");login();select();break;
				case 'y':
				case 'Y':modify();break;
				default:printf("�����������������룺");continue;
			}
		}
	}

	if(a==2)
	{
		printf("������ѧ�ţ�");
		scanf("\t%s",s);
		getchar();

		for(i=0;i<sjl;i++)
		{
			if(strcmp(s,s1[i].num)==0)
			{
				printf("\nѧ��������%s",s1[i].name);
				printf("\nѧ���Ա�%s",s1[i].sex);
				printf("\nѧ��ѧ�ţ�%s",s1[i].num);
				printf("\nѧ���༶��%s",s1[i].clas);
				printf("\nѧ�����գ�%s",s1[i].birthday);
				printf("\nѧ����ϵ���룺%s",s1[i].tel);
				printf("\nѧ����ͥסַ��%s",s1[i].address);
				printf("\nѧ��C���Գɼ���%f",s1[i].cyuyan);
				printf("\nѧ�������ɼ���%f",s1[i].gaoshu);
				printf("\nѧ��Ӣ��ɼ���%f",s1[i].yingyu);
				printf("\nѧ���ߴ��ɼ���%f",s1[i].xiandai);
				printf("\n�ܷ֣�%f\tƽ���֣�%f\n",s1[i].total,s1[i].total/4.0);
				break;
			}
		}
		if(i==sjl)
		{
			printf("���޴���\n\n");
			login();
			select();
		}
		printf("\n�Ƿ���Ҫ�޸ģ���y/n��");
		for(;;)
		{
			sign=getchar();
			getchar();
			switch(sign)
			{
				case 'n':
				case 'N':system("cls");login();select();break;
				case 'y':
				case 'Y':modify();break;
				default:printf("�����������������룺");continue;
			}
		}
	}
	if(a==3)
	{
		system("pause");
		login();
		select();
	}
}