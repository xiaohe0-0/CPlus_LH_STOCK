#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun.h"

/************************************************************************/
/* 函数功能：判断头结点是否为空                                         */
/************************************************************************/
int judgeHead(Goods * head)
{
	if (head == NULL)
	{
		printf("\n没有数据可进行操作！\n\n");
		return 0;
	}
	return 1;
}

/************************************************************************/
/* 函数功能：菜单接受输入                                               */
/************************************************************************/
int menu(void)
{
	int choice;

	do 
	{
		system("cls");
		fflush(stdin);
		printf("\n===========================================\n");
		printf("\t1. 输入库存记录\n");
		printf("\t2. 删除一条记录\n");
		printf("\t3. 查找修改记录\n");
		printf("\t4. 浏览所有记录\n");
		printf("\t5. 添加一条记录\n");
		printf("\t6. 查看每种货物总价\n");
		printf("\t0. 退出\n");
		printf("===========================================\n");
		printf("请输入你的选择：");

		scanf("%d",&choice);

		if (choice >=0 && choice <=6)
		{
			return choice;
		}
		else 
		{
			printf("\n选择错误，请重新选择！\n\n");
			system("pause");
			continue;
		}

	} while (1);

}
/************************************************************************/
/* 函数功能：对菜单项的选择进行操作                                     */
/************************************************************************/
Goods *chooseOr(int select,Goods *head)
{
	if (0 != select)
	{
		switch (select)
		{
		case 1:                  //输入库存记录
			head = createList();
			break;
		case 2:					//删除一条记录
			deleteInfo(head);
			break;
		case 3:					//查找修改记录
			findAndEdit(head);
			break;
		case 4:					//浏览所有记录
			traverse(head);
			break;
		case 5:					//添加一条记录
			insertInfo(head);
			break;
		case 6:					//查看每种货物总价
			outputTp(head);
			break;
		}
	}
	else
	{
		printf("\n退出系统！\n\n");
	}
	return head;

}
/************************************************************************/
/* 函数功能 ： 创建链表                                                 */
/************************************************************************/
Goods *createList(void)
{
	Goods *p,*head,*q;
	char agree[2] = {0};

	p = (Goods *)malloc(sizeof(Goods));

	if(!p)
	{
		exit(0);
	}

	p ->next = NULL;
	head = p;
	q = p;

	do
	{
		p = (Goods *)malloc(sizeof(Goods));

		if(!p)
		{
			exit(0);
		}

		printf("\n请输入货物的编号：");
		scanf("%s",p->goodsID);
		printf("\n请输入货物的名称：");
		scanf("%s",p->goodsName);
		printf("\n请输入货物的数量：");
		scanf("%d",&((*p).goodsNum));
		printf("\n请输入货物的价格：");
		scanf("%lf",&(p->goodsPrice));
		printf("\n请输入货物的厂家：");
		scanf("%s",p->goodsPro);
		printf("\n输入n停止输入,继续输入输入y：");
		scanf("%s",&agree[0]);
		fflush(stdin);


		p ->next = q ->next;
		q ->next = p;
		q = p;
	}while(agree[0] != 'n');

	printf("\n");

	return head;
}

/************************************************************************/
/* 函数功能：遍历                                                       */
/************************************************************************/
int traverse(Goods *head)
{
	Goods *p;
	char * fileName = "info.txt";
	FILE *fp = fopen(fileName,"w+");

	if (!judgeHead(head)) return 0;	
	p = head ->next;	

	printf("\n货物编号 货物名称 货物数量 货物价格 货物厂家\n");
	fprintf(fp,"\n货物编号 货物名称 货物数量 货物价格 货物厂家\n");

	while(p)
	{
		printf("\n%-8s %-8s %-8d %-8g %-8s\n\n",p ->goodsID,p ->goodsName,p->goodsNum,p->goodsPrice,p->goodsPro);
		fprintf(fp,"\n%-8s %-8s %-8d %-8g %-8s\n\n",p ->goodsID,p ->goodsName,p->goodsNum,p->goodsPrice,p->goodsPro);
		p = p->next;
	}
	fclose(fp);
	printf("\n");
	return 1;
}

/************************************************************************/
/* 函数功能：插入结点                                                   */
/************************************************************************/
Goods * insertInfo(Goods *head)
{
	Goods *p = head;
	Goods *q;

	if (!judgeHead(head)) return 0;	

	while (p ->next)
	{
		p = p->next;
	}

	q = (Goods *)malloc(sizeof(Goods));
	if(!q)
	{
		exit(0);
	}

	//data
	printf("\n请输入要插入的货物的编号：");
	scanf("%s",q->goodsID);
	printf("\n请输入要插入的货物的名称：");
	scanf("%s",q->goodsName);
	printf("\n请输入要插入的货物的数量：");
	scanf("%d",&((*q).goodsNum));
	printf("\n请输入要插入的货物的价格：");
	scanf("%lf",&(q->goodsPrice));
	printf("\n请输入要插入的货物的厂家：");
	scanf("%s",q->goodsPro);
	fflush(stdin);
	printf("\n");

	//pointer
	q ->next = NULL;
	p ->next = q;

	return head;

}


/************************************************************************/
/* 函数功能：删除结点                                                   */
/************************************************************************/
Goods *deleteInfo(Goods *head)
{
	Goods *p,*q;
	char delID[GOODSID];

	if (!judgeHead(head)) return 0;	

	p = head ->next;
	q = head;

	printf("\n请输入要删除的货物编号：");
	scanf("%s",delID);
	while(p && strcmp(p ->goodsID,delID) != 0)
	{
		q = p;
		p = p ->next;
	}
	if(p == NULL)
	{
		printf("\n没有该货物~\n\n");
		return 0;
	}
	q ->next = p ->next;
	free(p);
	printf("\n");

	return head;
}

/************************************************************************/
/* 函数功能：查找并进行修改                                             */
/************************************************************************/
Goods *findAndEdit(Goods *head)
{
	Goods * p;
	int choiceF;
	char changeID[GOODSID];
	char changeName[GOODSNAME];
	char aID[GOODSID];
	char aName[GOODSNAME];
	char aPro[GOODSPRO];
	int aNum;
	double aPrice;

	if (!judgeHead(head)) return 0;	

	p = head ->next;

	printf("\n请选择查找修改方式：按货物编号查找请输入1，按货物名称查找请输入2：");
	scanf("%d",&choiceF);

	/*对查找方式进行选择*/
	switch (choiceF)
	{
	case 1:
		printf("\n请输入要查找修改的货物编号：");
		scanf("%s",changeID);
		while(p && strcmp(p->goodsID,changeID)!= 0)
		{
			p = p->next;
		}
		if (!p)
		{
			printf("\n没有该货物!\n\n");
			return 0;
		}
		printf("\n请输入要修改的货物名称、货物数量、货物价格、货物厂家(用空格隔开):\n");
		scanf("%s %d %lf %s",aName,&aNum,&aPrice,aPro);

		p->goodsNum = aNum;
		p->goodsPrice = aPrice;
		strcpy(p->goodsName,aName);
		strcpy(p->goodsPro,aPro);
		break;
	case 2:
		printf("\n请输入要查找修改的货物名称：");
		scanf("%s",changeName);
		while(p && strcmp(p->goodsName,changeName)!= 0)
		{
			p = p->next;
		}
		if (!p)
		{
			printf("\n没有该货物!\n\n");
			return 0;
		}
		printf("\n请输入要修改的货物编号、货物数量、货物价格、货物厂家(用空格隔开)\n");
		scanf("%s %d %lf %s",aID,&aNum,&aPrice,aPro);

		p->goodsNum = aNum;
		p->goodsPrice = aPrice;
		strcpy(p->goodsID,aID);
		strcpy(p->goodsPro,aPro);
		break;
	default:
		printf("\n输入有误！\n\n");
		break;
	}
	return head;
}
/************************************************************************/
/* 函数功能：输出总价                                                   */
/************************************************************************/
int outputTp(Goods *head)
{
	double totlePrice;
	Goods *p;

	if (!judgeHead(head)) return 0;	
	p = head ->next;	

	printf("\n货物编号 货物名称 货物数量 货物价格 货物总价\n");

	while(p)
	{
		totlePrice = (p->goodsNum) * (p->goodsPrice);
		printf("\n%-8s %-8s %-8d %-8g %-8f\n\n",p ->goodsID,p ->goodsName,p->goodsNum,p->goodsPrice,totlePrice);
		p = p->next;
	}
	printf("\n");
	return 1;
}