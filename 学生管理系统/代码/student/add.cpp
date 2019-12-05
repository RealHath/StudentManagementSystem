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
	int sjl;		//学生数
	int i,j,a;
	for(i=sjl=0;sign!='n'&&sign!='N';i++,sjl++)
	{
		printf("\n输入学生姓名：");
		scanf("%s",stu[i].name);
		printf("\n输入学生性别：");
		scanf("%s",stu[i].sex);
		printf("\n输入学生学号：");
		scanf("%s",stu[i].num);
		
		strcpy(s,stu[i].num);
		for(j=0;j<=i;j++)
		{
			a=strcmp(s,stu[j].num);
			getchar();
			if(a)
			{
				printf("\n该学号已存在！\n");
				system("pause");
				tp=fopen("studentdata.txt","a");		//追加；向文本文件尾添加数据,没有文件就新建
				if(tp==NULL)
				{
					printf("\n无法打开此文件");
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
			}		//检查重复学号未完成
		}
		getchar();
		printf("\n输入学生班级：");
		scanf("%s",stu[i].clas);
		printf("\n输入学生生日：");
		scanf("%s",stu[i].birthday);
		printf("\n输入学生联系号码：");
		scanf("%s",stu[i].tel);
		printf("\n输入学生家庭住址：");
		scanf("%s",stu[i].address);
		printf("\n输入学生C语言成绩：");
		scanf("%f",&stu[i].cyuyan);
		printf("\n输入学生高数成绩：");
		scanf("%f",&stu[i].gaoshu);
		printf("\n输入学生英语成绩：");
		scanf("%f",&stu[i].yingyu);
		printf("\n输入学生线代成绩：");
		scanf("%f",&stu[i].xiandai);
		stu[i].total=stu[i].xiandai+stu[i].cyuyan+stu[i].gaoshu+stu[i].yingyu;
		getchar();
		printf("\n是否继续录入信息？（y/n）");
		scanf("%c",&sign);
		system("cls");			//清屏函数
	}
	getchar();

	tp=fopen("studentdata.txt","a");		//追加；向文本文件尾添加数据,没有文件就新建
	if(tp==NULL)
	{
		printf("\n无法打开此文件");
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