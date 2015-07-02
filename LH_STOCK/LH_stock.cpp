/************************************************************************/
/*作者：刘荷															*/
/*日期：2010-07-16														*/
/*功能：库存管理													*/                                                    
/************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "fun.h"

int main(void)
{
	int select;
	Goods *head = NULL;

	do 
	{
		select = menu();
		head = chooseOr(select,head);
		system("pause");
	} while (0 != select);

	return 0;
}

