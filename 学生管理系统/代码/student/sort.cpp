#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
}st[100];

void sort()	
{
	FILE *tp;
	int i=0,sjl=0;

	if((tp=fopen("studentdata.txt","r"))==NULL)
	{
		printf("无法打开文件");
		return;
	}

	while(fscanf(tp,"%s %s %s %s %s %s %s %f %f %f %f %f\n",st[i].name,st[i].sex,st[i].num,st[i].clas,st[i].birthday,st[i].tel,st[i].address,&st[i].cyuyan,&st[i].gaoshu,&st[i].yingyu,&st[i].xiandai,&st[i].total)!=EOF)
	{
		i++;
		sjl++;
	}
	fclose(tp);

	int j,k,m;
	float t;
	char a[20],b[20];

	for(j=0;j<sjl-1;j++)
	{	
		for(k=0;k<sjl-j-1;k++)
		{
			if(st[k].total<st[k+1].total)
			{
				t=st[k].total;
				st[k].total=st[k+1].total;
				st[k+1].total=t;
				strcpy(a,st[k].name);
				strcpy(b,st[k+1].name);
				strcpy(st[k].name,b);
				strcpy(st[k+1].name,a);
			}
		}
	}
	printf("\n总分从高到低排序\n");
	for(m=0;m<sjl;m++)
		printf("第%d名：%s\t总分：%f\n",m+1,st[m].name,st[m].total);

	printf("\n前三名：\n");
	for(m=0;m<3;m++)
		printf("第%d名：%s\t总分：%f\n",m+1,st[m].name,st[m].total);

	int max=0;		//最高分
	for(i=1;i<sjl;i++)
	{
		if(st[max].total<st[i].total)
			max=i;
	}
	printf("\n最高分是:%s\t\t总分:%f\n",st[max].name,st[max].total);

	
}