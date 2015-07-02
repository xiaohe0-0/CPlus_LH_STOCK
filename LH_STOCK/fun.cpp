#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun.h"

/************************************************************************/
/* �������ܣ��ж�ͷ����Ƿ�Ϊ��                                         */
/************************************************************************/
int judgeHead(Goods * head)
{
	if (head == NULL)
	{
		printf("\nû�����ݿɽ��в�����\n\n");
		return 0;
	}
	return 1;
}

/************************************************************************/
/* �������ܣ��˵���������                                               */
/************************************************************************/
int menu(void)
{
	int choice;

	do 
	{
		system("cls");
		fflush(stdin);
		printf("\n===========================================\n");
		printf("\t1. �������¼\n");
		printf("\t2. ɾ��һ����¼\n");
		printf("\t3. �����޸ļ�¼\n");
		printf("\t4. ������м�¼\n");
		printf("\t5. ���һ����¼\n");
		printf("\t6. �鿴ÿ�ֻ����ܼ�\n");
		printf("\t0. �˳�\n");
		printf("===========================================\n");
		printf("���������ѡ��");

		scanf("%d",&choice);

		if (choice >=0 && choice <=6)
		{
			return choice;
		}
		else 
		{
			printf("\nѡ�����������ѡ��\n\n");
			system("pause");
			continue;
		}

	} while (1);

}
/************************************************************************/
/* �������ܣ��Բ˵����ѡ����в���                                     */
/************************************************************************/
Goods *chooseOr(int select,Goods *head)
{
	if (0 != select)
	{
		switch (select)
		{
		case 1:                  //�������¼
			head = createList();
			break;
		case 2:					//ɾ��һ����¼
			deleteInfo(head);
			break;
		case 3:					//�����޸ļ�¼
			findAndEdit(head);
			break;
		case 4:					//������м�¼
			traverse(head);
			break;
		case 5:					//���һ����¼
			insertInfo(head);
			break;
		case 6:					//�鿴ÿ�ֻ����ܼ�
			outputTp(head);
			break;
		}
	}
	else
	{
		printf("\n�˳�ϵͳ��\n\n");
	}
	return head;

}
/************************************************************************/
/* �������� �� ��������                                                 */
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

		printf("\n���������ı�ţ�");
		scanf("%s",p->goodsID);
		printf("\n�������������ƣ�");
		scanf("%s",p->goodsName);
		printf("\n����������������");
		scanf("%d",&((*p).goodsNum));
		printf("\n���������ļ۸�");
		scanf("%lf",&(p->goodsPrice));
		printf("\n���������ĳ��ң�");
		scanf("%s",p->goodsPro);
		printf("\n����nֹͣ����,������������y��");
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
/* �������ܣ�����                                                       */
/************************************************************************/
int traverse(Goods *head)
{
	Goods *p;
	char * fileName = "info.txt";
	FILE *fp = fopen(fileName,"w+");

	if (!judgeHead(head)) return 0;	
	p = head ->next;	

	printf("\n������ �������� �������� ����۸� ���ﳧ��\n");
	fprintf(fp,"\n������ �������� �������� ����۸� ���ﳧ��\n");

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
/* �������ܣ�������                                                   */
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
	printf("\n������Ҫ����Ļ���ı�ţ�");
	scanf("%s",q->goodsID);
	printf("\n������Ҫ����Ļ�������ƣ�");
	scanf("%s",q->goodsName);
	printf("\n������Ҫ����Ļ����������");
	scanf("%d",&((*q).goodsNum));
	printf("\n������Ҫ����Ļ���ļ۸�");
	scanf("%lf",&(q->goodsPrice));
	printf("\n������Ҫ����Ļ���ĳ��ң�");
	scanf("%s",q->goodsPro);
	fflush(stdin);
	printf("\n");

	//pointer
	q ->next = NULL;
	p ->next = q;

	return head;

}


/************************************************************************/
/* �������ܣ�ɾ�����                                                   */
/************************************************************************/
Goods *deleteInfo(Goods *head)
{
	Goods *p,*q;
	char delID[GOODSID];

	if (!judgeHead(head)) return 0;	

	p = head ->next;
	q = head;

	printf("\n������Ҫɾ���Ļ����ţ�");
	scanf("%s",delID);
	while(p && strcmp(p ->goodsID,delID) != 0)
	{
		q = p;
		p = p ->next;
	}
	if(p == NULL)
	{
		printf("\nû�иû���~\n\n");
		return 0;
	}
	q ->next = p ->next;
	free(p);
	printf("\n");

	return head;
}

/************************************************************************/
/* �������ܣ����Ҳ������޸�                                             */
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

	printf("\n��ѡ������޸ķ�ʽ���������Ų���������1�����������Ʋ���������2��");
	scanf("%d",&choiceF);

	/*�Բ��ҷ�ʽ����ѡ��*/
	switch (choiceF)
	{
	case 1:
		printf("\n������Ҫ�����޸ĵĻ����ţ�");
		scanf("%s",changeID);
		while(p && strcmp(p->goodsID,changeID)!= 0)
		{
			p = p->next;
		}
		if (!p)
		{
			printf("\nû�иû���!\n\n");
			return 0;
		}
		printf("\n������Ҫ�޸ĵĻ������ơ���������������۸񡢻��ﳧ��(�ÿո����):\n");
		scanf("%s %d %lf %s",aName,&aNum,&aPrice,aPro);

		p->goodsNum = aNum;
		p->goodsPrice = aPrice;
		strcpy(p->goodsName,aName);
		strcpy(p->goodsPro,aPro);
		break;
	case 2:
		printf("\n������Ҫ�����޸ĵĻ������ƣ�");
		scanf("%s",changeName);
		while(p && strcmp(p->goodsName,changeName)!= 0)
		{
			p = p->next;
		}
		if (!p)
		{
			printf("\nû�иû���!\n\n");
			return 0;
		}
		printf("\n������Ҫ�޸ĵĻ����š���������������۸񡢻��ﳧ��(�ÿո����)\n");
		scanf("%s %d %lf %s",aID,&aNum,&aPrice,aPro);

		p->goodsNum = aNum;
		p->goodsPrice = aPrice;
		strcpy(p->goodsID,aID);
		strcpy(p->goodsPro,aPro);
		break;
	default:
		printf("\n��������\n\n");
		break;
	}
	return head;
}
/************************************************************************/
/* �������ܣ�����ܼ�                                                   */
/************************************************************************/
int outputTp(Goods *head)
{
	double totlePrice;
	Goods *p;

	if (!judgeHead(head)) return 0;	
	p = head ->next;	

	printf("\n������ �������� �������� ����۸� �����ܼ�\n");

	while(p)
	{
		totlePrice = (p->goodsNum) * (p->goodsPrice);
		printf("\n%-8s %-8s %-8d %-8g %-8f\n\n",p ->goodsID,p ->goodsName,p->goodsNum,p->goodsPrice,totlePrice);
		p = p->next;
	}
	printf("\n");
	return 1;
}