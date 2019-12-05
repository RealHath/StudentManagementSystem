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
		printf("无法打开文件");
		return;
	}

	while(fscanf(tp,"%s %s %s %s %s %s %s %f %f %f %f %f\n",stu2[i].name,stu2[i].sex,stu2[i].num,stu2[i].clas,stu2[i].birthday,stu2[i].tel,stu2[i].address,&stu2[i].cyuyan,&stu2[i].gaoshu,&stu2[i].yingyu,&stu2[i].xiandai,&stu2[i].total)!=EOF)
	{
		i++;
		sjl++;
	}
	fclose(tp);

	printf("输入姓名查找学生：");
	scanf("\n%s",s);
	getchar();
	system("cls");
	for(i=0;i<sjl;i++)
	{
		if(strcmp(stu2[i].name,s)==0)
		{
			printf("\n学生姓名：%s",stu2[i].name);
			printf("\n学生性别：%s",stu2[i].sex);
			printf("\n学生学号：%s",stu2[i].num);
			printf("\n学生班级：%s",stu2[i].clas);
			printf("\n学生生日：%s",stu2[i].birthday);
			printf("\n学生联系号码：%s",stu2[i].tel);
			printf("\n学生家庭住址：%s",stu2[i].address);
			printf("\n学生C语言成绩：%f",stu2[i].cyuyan);
			printf("\n学生高数成绩：%f",stu2[i].gaoshu);
			printf("\n学生英语成绩：%f",stu2[i].yingyu);
			printf("\n学生线代成绩：%f",stu2[i].xiandai);
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
	printf("\n是否修改？（y/n）");
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

		else
		{
			for(;;)
			{
				printf("修改哪一项：\n");
				printf("1、姓名\n");
				printf("2、学号\n");
				printf("3、联系号码\n");
				printf("4、修改全部\n");
				printf("5、返回菜单\n");
				scanf("%c",&sign);
				getchar();
				if(sign=='1')
				{
					printf("\n输入学生姓名：");
					scanf("%s",stu2[i].name);
					break;
				}
				else if(sign=='2')
				{
					printf("\n输入学生学号：");
					scanf("%s",stu2[i].num);
					break;
				}
				else if(sign=='3')
				{
					printf("\n输入学生联系号码：");
					scanf("%s",stu2[i].tel);
					break;
				}
				else if(sign=='4')
				{
					printf("\n输入学生姓名：");
					scanf("%s",stu2[i].name);
					printf("\n输入学生性别：");
					scanf("%s",stu2[i].sex);
					printf("\n输入学生学号：");
					scanf("%s",stu2[i].num);
					printf("\n输入学生班级：");
					scanf("%s",stu2[i].clas);
					printf("\n输入学生生日：");
					scanf("%s",stu2[i].birthday);
					printf("\n输入学生联系号码：");
					scanf("%s",stu2[i].tel);
					printf("\n输入学生家庭住址：");
					scanf("%s",stu2[i].address);
					printf("\n输入学生C语言成绩：");
					scanf("%f",&stu2[i].cyuyan);
					printf("\n输入学生高数成绩：");
					scanf("%f",&stu2[i].gaoshu);
					printf("\n输入学生英语成绩：");
					scanf("%f",&stu2[i].yingyu);
					printf("\n输入学生线代成绩：");
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
					printf("输入错误请重新输入");
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
		printf("\n修改成功\n");
	else
		 perror("remove");
	rename("temp.txt","studentdata.txt");
	getchar();
	system("pause");
	login();
	select();
}
