#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern void login();
extern void select();
extern void modify();
extern void sort();

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
}stu1[100];

void scan()
{
	FILE *tp;
	int i=0,a,sjl=0;
	char sign='y';

	tp=fopen("studentdata.txt","r");
	if(tp==NULL)
	{
		printf("�޷����ļ�\n");
		return;
	}
	while(fscanf(tp,"%s %s %s %s %s %s %s %f %f %f %f %f\n",stu1[i].name,stu1[i].sex,stu1[i].num,stu1[i].clas,stu1[i].birthday,stu1[i].tel,stu1[i].address,&stu1[i].cyuyan,&stu1[i].gaoshu,&stu1[i].yingyu,&stu1[i].xiandai,&stu1[i].total)!=EOF)
	{
		i++;
		sjl++;
	}
	fclose(tp);
	system("cls");

	printf("ѡ�������ʽ��\n");
	printf("1�����հ༶���\n");
	printf("2�����ȫ����Ϣ\n");
	printf("3�����ز˵�\n");
	scanf("%d",&a);
	getchar();
	if(a==1)
	{
		char s[30];
		printf("������༶��");
		scanf("%s",s);
		getchar();
		for(i=0;i<sjl;i++)
		{
			if(strcmp(s,stu1[i].clas)==0)
			{
				printf("\n*************************");
				printf("\nѧ��������%s",stu1[i].name);
				printf("\nѧ���Ա�%s",stu1[i].sex);
				printf("\nѧ��ѧ�ţ�%s",stu1[i].num);
				printf("\nѧ���༶��%s",stu1[i].clas);
				printf("\nѧ�����գ�%s",stu1[i].birthday);
				printf("\nѧ����ϵ���룺%s",stu1[i].tel);
				printf("\nѧ����ͥסַ��%s",stu1[i].address);
				printf("\nѧ��C���Գɼ���%f",stu1[i].cyuyan);
				printf("\nѧ�������ɼ���%f",stu1[i].gaoshu);
				printf("\nѧ��Ӣ��ɼ���%f",stu1[i].yingyu);
				printf("\nѧ���ߴ��ɼ���%f",stu1[i].xiandai);
				printf("\n�ܷ֣�%f\tƽ���֣�%f\n",stu1[i].total,stu1[i].total/4.0);
			}
			if(i==sjl)
			{
				printf("����Ϣ\n\n");
				system("pause");
				system("cls");
				login();
				select();
			}
			
		}
	}
	else if(a==2)
	{
		for(i=0;i<sjl;i++)
		{
			printf("\n*************************");
			printf("\nѧ��������%s",stu1[i].name);
			printf("\nѧ���Ա�%s",stu1[i].sex);
			printf("\nѧ��ѧ�ţ�%s",stu1[i].num);
			printf("\nѧ���༶��%s",stu1[i].clas);
			printf("\nѧ�����գ�%s",stu1[i].birthday);
			printf("\nѧ����ϵ���룺%s",stu1[i].tel);
			printf("\nѧ����ͥסַ��%s",stu1[i].address);
			printf("\nѧ��C���Գɼ���%f",stu1[i].cyuyan);
			printf("\nѧ�������ɼ���%f",stu1[i].gaoshu);
			printf("\nѧ��Ӣ��ɼ���%f",stu1[i].yingyu);
			printf("\nѧ���ߴ��ɼ���%f",stu1[i].xiandai);
			printf("\n�ܷ֣�%f\tƽ���֣�%f\n",stu1[i].total,stu1[i].total/4.0);
		}
		sort();
	}
	else if(a==3)
	{
		system("pause");
		system("cls");
		login();
		select();
	}
	else
	{
		printf("���������룺\n");
		scan();
	}
	system("pause");
	printf("�Ƿ���Ҫ�޸ģ���y/n��");
	for(;;)
	{
		scanf("%c",&sign);
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