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
		printf("无法打开文件");
		return;
	}

	while(fscanf(tp,"%s %s %s %s %s %s %s %f %f %f %f %f\n",stud[i].name,stud[i].sex,stud[i].num,stud[i].clas,stud[i].birthday,stud[i].tel,stud[i].address,&stud[i].cyuyan,&stud[i].gaoshu,&stud[i].yingyu,&stud[i].xiandai,&stud[i].total)!=EOF)
	{
		i++;
		sjl++;
	}
	fclose(tp);

	printf("输入姓名查找学生：");
	scanf("\n%s",s);
	getchar();
	for(i=0;i<sjl;i++)
	{
		if(strcmp(stud[i].name,s)==0)
		{
			printf("\n学生姓名：%s",stud[i].name);
			printf("\n学生性别：%s",stud[i].sex);
			printf("\n学生学号：%s",stud[i].num);
			printf("\n学生班级：%s",stud[i].clas);
			printf("\n学生生日：%s",stud[i].birthday);
			printf("\n学生联系号码：%s",stud[i].tel);
			printf("\n学生家庭住址：%s",stud[i].address);
			printf("\n学生C语言成绩：%f",stud[i].cyuyan);
			printf("\n学生高数成绩：%f",stud[i].gaoshu);
			printf("\n学生英语成绩：%f",stud[i].yingyu);
			printf("\n学生线代成绩：%f",stud[i].xiandai);
			break;
		}
	}

	if(i==sjl)
	{
		printf("查无此人\n");
		login();
		select();
	}

	FILE *ftp=fopen("studentdata.txt","r"),*fp=fopen("temp.txt","w");			//需要读写权限，否则无法删除和重命名
	printf("\n是否删除？（y/n）");
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
			printf("打开文件失败");
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
		printf("删除成功!\n");
	else
		 perror("remove");		//返回错误报告
	rename("temp.txt","studentdata.txt");
	
	system("pause");
	login();
	select();
}