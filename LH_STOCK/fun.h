#ifndef _FUN_H_
#define _FUN_H_


#define GOODSID 20
#define GOODSNAME 20
#define GOODSPRO 30


/*���������Ϣ�Ľṹ��*/
typedef struct goods{
	char goodsID[GOODSID];		//������
	char goodsName[GOODSNAME];  //��������
	int goodsNum;				//��������
	double goodsPrice;			//����۸�
	char goodsPro[GOODSPRO];	// ���ﳧ��
	struct goods *next;
}Goods;							

int judgeHead(Goods * head);//�ж�ͷ����Ƿ�Ϊ��
int menu(void);//�˵��������� 
Goods *chooseOr(int select,Goods *head);//�Բ˵����ѡ����в���
Goods *createList(void);//������¼����
int traverse(Goods *head);//�����¼
Goods *insertInfo(Goods *head);//����һ����¼
Goods *deleteInfo(Goods *head);//��������ɾ��һ��ָ���ļ�¼
Goods *findAndEdit(Goods *head);//�������š��������Ʋ��Ҳ��޸ļ�¼
int outputTp(Goods *head);//����ܼ�

#endif _FUN_H_