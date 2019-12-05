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
	int sjl=0;		//学生数

	if((tp=fopen("studentdata.txt","r"))==NULL)
	{
		printf("无法打开文件");
		return;
	}

	while(fscanf(tp,"%s %s %s %s %s %s %s %f %f %f %f %f\n",s1[i].name,s1[i].sex,s1[i].num,s1[i].clas,s1[i].birthday,s1[i].tel,s1[i].address,&s1[i].cyuyan,&s1[i].gaoshu,&s1[i].yingyu,&s1[i].xiandai,&s1[i].total)!=EOF)
	{
		i++;
		sjl++;
	}
	fclose(tp);

	printf("请选择查询方式：\n");
	printf("1、按照姓名搜索\n");
	printf("2、按照学号查询\n");
	printf("3、返回菜单\n");
	scanf("%d",&a);
	getchar();


	if(a==1)
	{
		printf("请输入名字：");
		scanf("\t%s",s);
		getchar();

		for(i=0;i<sjl;i++)
		{
			if(strcmp(s,s1[i].name)==0)
			{
				printf("\n学生姓名：%s",s1[i].name);
				printf("\n学生性别：%s",s1[i].sex);
				printf("\n学生学号：%s",s1[i].num);
				printf("\n学生班级：%s",s1[i].clas);
				printf("\n学生生日：%s",s1[i].birthday);
				printf("\n学生联系号码：%s",s1[i].tel);
				printf("\n学生家庭住址：%s",s1[i].address);
				printf("\n学生C语言成绩：%f",s1[i].cyuyan);
				printf("\n学生高数成绩：%f",s1[i].gaoshu);
				printf("\n学生英语成绩：%f",s1[i].yingyu);
				printf("\n学生线代成绩：%f",s1[i].xiandai);
				printf("\n总分：%f\t平均分：%f\n",s1[i].total,s1[i].total/4.0);
				break;
			}
		}
		if(i==sjl)
		{
			printf("查无此人\n\n");
			system("pause");
			system("cls");
			login();
			select();
		}
		printf("\n是否需要修改？（y/n）");
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
				default:printf("输入有误，请重新输入：");continue;
			}
		}
	}

	if(a==2)
	{
		printf("请输入学号：");
		scanf("\t%s",s);
		getchar();

		for(i=0;i<sjl;i++)
		{
			if(strcmp(s,s1[i].num)==0)
			{
				printf("\n学生姓名：%s",s1[i].name);
				printf("\n学生性别：%s",s1[i].sex);
				printf("\n学生学号：%s",s1[i].num);
				printf("\n学生班级：%s",s1[i].clas);
				printf("\n学生生日：%s",s1[i].birthday);
				printf("\n学生联系号码：%s",s1[i].tel);
				printf("\n学生家庭住址：%s",s1[i].address);
				printf("\n学生C语言成绩：%f",s1[i].cyuyan);
				printf("\n学生高数成绩：%f",s1[i].gaoshu);
				printf("\n学生英语成绩：%f",s1[i].yingyu);
				printf("\n学生线代成绩：%f",s1[i].xiandai);
				printf("\n总分：%f\t平均分：%f\n",s1[i].total,s1[i].total/4.0);
				break;
			}
		}
		if(i==sjl)
		{
			printf("查无此人\n\n");
			login();
			select();
		}
		printf("\n是否需要修改？（y/n）");
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
				default:printf("输入有误，请重新输入：");continue;
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