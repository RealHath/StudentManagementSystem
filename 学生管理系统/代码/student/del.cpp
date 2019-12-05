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
}stud[100];


void del()
{
	int i=0,sjl=0;
	char sign=' ',s[30];
	FILE *tp=fopen("studentdata.txt","r");

	if(tp==NULL)
	{
		printf("�޷����ļ�");
		return;
	}

	while(fscanf(tp,"%s %s %s %s %s %s %s %f %f %f %f %f\n",stud[i].name,stud[i].sex,stud[i].num,stud[i].clas,stud[i].birthday,stud[i].tel,stud[i].address,&stud[i].cyuyan,&stud[i].gaoshu,&stud[i].yingyu,&stud[i].xiandai,&stud[i].total)!=EOF)
	{
		i++;
		sjl++;
	}
	fclose(tp);

	printf("������������ѧ����");
	scanf("\n%s",s);
	getchar();
	for(i=0;i<sjl;i++)
	{
		if(strcmp(stud[i].name,s)==0)
		{
			printf("\nѧ��������%s",stud[i].name);
			printf("\nѧ���Ա�%s",stud[i].sex);
			printf("\nѧ��ѧ�ţ�%s",stud[i].num);
			printf("\nѧ���༶��%s",stud[i].clas);
			printf("\nѧ�����գ�%s",stud[i].birthday);
			printf("\nѧ����ϵ���룺%s",stud[i].tel);
			printf("\nѧ����ͥסַ��%s",stud[i].address);
			printf("\nѧ��C���Գɼ���%f",stud[i].cyuyan);
			printf("\nѧ�������ɼ���%f",stud[i].gaoshu);
			printf("\nѧ��Ӣ��ɼ���%f",stud[i].yingyu);
			printf("\nѧ���ߴ��ɼ���%f",stud[i].xiandai);
			break;
		}
	}

	if(i==sjl)
	{
		printf("���޴���\n");
		login();
		select();
	}

	FILE *ftp=fopen("studentdata.txt","r"),*fp=fopen("temp.txt","w");			//��Ҫ��дȨ�ޣ������޷�ɾ����������
	printf("\n�Ƿ�ɾ������y/n��");
	scanf("%c",&sign);
	getchar();

	if(sign=='n'||sign=='N')
	{
		login();
		select();
	}
	if(sign=='y'||sign=='Y')
	{
	
		if(ftp==NULL||fp==NULL)
		{
			printf("���ļ�ʧ��");
			return;
		}

		for(i=0;i<sjl;i++)
		{
			if(strcmp(s,stud[i].name)!=0)
			{
				fprintf(fp,"%s %s %s %s %s %s %s %f %f %f %f %f\n",stud[i].name,stud[i].sex,stud[i].num,stud[i].clas,stud[i].birthday,stud[i].tel,stud[i].address,stud[i].cyuyan,stud[i].gaoshu,stud[i].yingyu,stud[i].xiandai,stud[i].total);
			}
		}
	}

	fclose(ftp);
	fclose(fp);
	if(!remove("studentdata.txt"))
		printf("ɾ���ɹ�!\n");
	else
		 perror("remove");		//���ش��󱨸�
	rename("temp.txt","studentdata.txt");
	
	system("pause");
	login();
	select();
}