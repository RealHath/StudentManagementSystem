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
}stu2[100];

void modify()
{
	int i=0,sjl=0;
	char sign=' ',s[30];
	FILE *tp=fopen("studentdata.txt","r");

	if(tp==NULL)
	{
		printf("�޷����ļ�");
		return;
	}

	while(fscanf(tp,"%s %s %s %s %s %s %s %f %f %f %f %f\n",stu2[i].name,stu2[i].sex,stu2[i].num,stu2[i].clas,stu2[i].birthday,stu2[i].tel,stu2[i].address,&stu2[i].cyuyan,&stu2[i].gaoshu,&stu2[i].yingyu,&stu2[i].xiandai,&stu2[i].total)!=EOF)
	{
		i++;
		sjl++;
	}
	fclose(tp);

	printf("������������ѧ����");
	scanf("\n%s",s);
	getchar();
	system("cls");
	for(i=0;i<sjl;i++)
	{
		if(strcmp(stu2[i].name,s)==0)
		{
			printf("\nѧ��������%s",stu2[i].name);
			printf("\nѧ���Ա�%s",stu2[i].sex);
			printf("\nѧ��ѧ�ţ�%s",stu2[i].num);
			printf("\nѧ���༶��%s",stu2[i].clas);
			printf("\nѧ�����գ�%s",stu2[i].birthday);
			printf("\nѧ����ϵ���룺%s",stu2[i].tel);
			printf("\nѧ����ͥסַ��%s",stu2[i].address);
			printf("\nѧ��C���Գɼ���%f",stu2[i].cyuyan);
			printf("\nѧ�������ɼ���%f",stu2[i].gaoshu);
			printf("\nѧ��Ӣ��ɼ���%f",stu2[i].yingyu);
			printf("\nѧ���ߴ��ɼ���%f",stu2[i].xiandai);
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
	printf("\n�Ƿ��޸ģ���y/n��");
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

		else
		{
			for(;;)
			{
				printf("�޸���һ�\n");
				printf("1������\n");
				printf("2��ѧ��\n");
				printf("3����ϵ����\n");
				printf("4���޸�ȫ��\n");
				printf("5�����ز˵�\n");
				scanf("%c",&sign);
				getchar();
				if(sign=='1')
				{
					printf("\n����ѧ��������");
					scanf("%s",stu2[i].name);
					break;
				}
				else if(sign=='2')
				{
					printf("\n����ѧ��ѧ�ţ�");
					scanf("%s",stu2[i].num);
					break;
				}
				else if(sign=='3')
				{
					printf("\n����ѧ����ϵ���룺");
					scanf("%s",stu2[i].tel);
					break;
				}
				else if(sign=='4')
				{
					printf("\n����ѧ��������");
					scanf("%s",stu2[i].name);
					printf("\n����ѧ���Ա�");
					scanf("%s",stu2[i].sex);
					printf("\n����ѧ��ѧ�ţ�");
					scanf("%s",stu2[i].num);
					printf("\n����ѧ���༶��");
					scanf("%s",stu2[i].clas);
					printf("\n����ѧ�����գ�");
					scanf("%s",stu2[i].birthday);
					printf("\n����ѧ����ϵ���룺");
					scanf("%s",stu2[i].tel);
					printf("\n����ѧ����ͥסַ��");
					scanf("%s",stu2[i].address);
					printf("\n����ѧ��C���Գɼ���");
					scanf("%f",&stu2[i].cyuyan);
					printf("\n����ѧ�������ɼ���");
					scanf("%f",&stu2[i].gaoshu);
					printf("\n����ѧ��Ӣ��ɼ���");
					scanf("%f",&stu2[i].yingyu);
					printf("\n����ѧ���ߴ��ɼ���");
					scanf("%f",&stu2[i].xiandai);
					break;
				}
				else if(sign=='5')
				{
					system("cls");
					login();
					select();
					break;
				}
				else
				{
					printf("�����������������");
					continue;
				}
			}
		}
	}
	for(i=0;i<sjl;i++)
	{
			fprintf(fp,"%s %s %s %s %s %s %s %f %f %f %f %f\n",stu2[i].name,stu2[i].sex,stu2[i].num,stu2[i].clas,stu2[i].birthday,stu2[i].tel,stu2[i].address,stu2[i].cyuyan,stu2[i].gaoshu,stu2[i].yingyu,stu2[i].xiandai,stu2[i].total);
	}

	fclose(ftp);
	fclose(fp);
	if(!remove("studentdata.txt"))
		printf("\n�޸ĳɹ�\n");
	else
		 perror("remove");
	rename("temp.txt","studentdata.txt");
	getchar();
	system("pause");
	login();
	select();
}
