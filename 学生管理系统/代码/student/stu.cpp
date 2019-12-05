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


int main()
{
	login();
	for(;;)
	{
		select();
	}
	return 0;
}
