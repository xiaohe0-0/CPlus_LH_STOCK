/************************************************************************/
/*���ߣ�����															*/
/*���ڣ�2010-07-16														*/
/*���ܣ�������													*/                                                    
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

