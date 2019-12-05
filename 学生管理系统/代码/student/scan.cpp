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
		printf("无法打开文件\n");
		return;
	}
	while(fscanf(tp,"%s %s %s %s %s %s %s %f %f %f %f %f\n",stu1[i].name,stu1[i].sex,stu1[i].num,stu1[i].clas,stu1[i].birthday,stu1[i].tel,stu1[i].address,&stu1[i].cyuyan,&stu1[i].gaoshu,&stu1[i].yingyu,&stu1[i].xiandai,&stu1[i].total)!=EOF)
	{
		i++;
		sjl++;
	}
	fclose(tp);
	system("cls");

	printf("选择浏览方式：\n");
	printf("1、按照班级浏览\n");
	printf("2、浏览全部信息\n");
	printf("3、返回菜单\n");
	scanf("%d",&a);
	getchar();
	if(a==1)
	{
		char s[30];
		printf("请输入班级：");
		scanf("%s",s);
		getchar();
		for(i=0;i<sjl;i++)
		{
			if(strcmp(s,stu1[i].clas)==0)
			{
				printf("\n*************************");
				printf("\n学生姓名：%s",stu1[i].name);
				printf("\n学生性别：%s",stu1[i].sex);
				printf("\n学生学号：%s",stu1[i].num);
				printf("\n学生班级：%s",stu1[i].clas);
				printf("\n学生生日：%s",stu1[i].birthday);
				printf("\n学生联系号码：%s",stu1[i].tel);
				printf("\n学生家庭住址：%s",stu1[i].address);
				printf("\n学生C语言成绩：%f",stu1[i].cyuyan);
				printf("\n学生高数成绩：%f",stu1[i].gaoshu);
				printf("\n学生英语成绩：%f",stu1[i].yingyu);
				printf("\n学生线代成绩：%f",stu1[i].xiandai);
				printf("\n总分：%f\t平均分：%f\n",stu1[i].total,stu1[i].total/4.0);
			}
			if(i==sjl)
			{
				printf("无信息\n\n");
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
			printf("\n学生姓名：%s",stu1[i].name);
			printf("\n学生性别：%s",stu1[i].sex);
			printf("\n学生学号：%s",stu1[i].num);
			printf("\n学生班级：%s",stu1[i].clas);
			printf("\n学生生日：%s",stu1[i].birthday);
			printf("\n学生联系号码：%s",stu1[i].tel);
			printf("\n学生家庭住址：%s",stu1[i].address);
			printf("\n学生C语言成绩：%f",stu1[i].cyuyan);
			printf("\n学生高数成绩：%f",stu1[i].gaoshu);
			printf("\n学生英语成绩：%f",stu1[i].yingyu);
			printf("\n学生线代成绩：%f",stu1[i].xiandai);
			printf("\n总分：%f\t平均分：%f\n",stu1[i].total,stu1[i].total/4.0);
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
		printf("请重新输入：\n");
		scan();
	}
	system("pause");
	printf("是否需要修改？（y/n）");
	for(;;)
	{
		scanf("%c",&sign);
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