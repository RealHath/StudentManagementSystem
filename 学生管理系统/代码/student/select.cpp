#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add.h"
#include "del.h"
#include "login.h"
#include "modify.h"
#include "scan.h"
#include "search.h"
#include "select.h"
#include "sort.h"

void select()
{
	int a;
	for(;;)
	{
		scanf("%d",&a);
		getchar();
		switch(a)
		{
			case 1:add();break;
			case 2:search();break;
			case 3:modify();break;
			case 4:scan();break;
			case 5:del();break;
			case 6:exit(0);break;
			default:printf("输入有误，请重新输入：");continue;
		}
	}
}