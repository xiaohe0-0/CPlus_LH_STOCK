#ifndef _FUN_H_
#define _FUN_H_


#define GOODSID 20
#define GOODSNAME 20
#define GOODSPRO 30


/*定义货物信息的结构体*/
typedef struct goods{
	char goodsID[GOODSID];		//货物编号
	char goodsName[GOODSNAME];  //货物名称
	int goodsNum;				//货物数量
	double goodsPrice;			//货物价格
	char goodsPro[GOODSPRO];	// 货物厂商
	struct goods *next;
}Goods;							

int judgeHead(Goods * head);//判断头结点是否为空
int menu(void);//菜单接受输入 
Goods *chooseOr(int select,Goods *head);//对菜单项的选择进行操作
Goods *createList(void);//创建记录链表
int traverse(Goods *head);//浏览纪录
Goods *insertInfo(Goods *head);//增加一条记录
Goods *deleteInfo(Goods *head);//按货物编号删除一条指定的记录
Goods *findAndEdit(Goods *head);//按货物编号、货物名称查找并修改记录
int outputTp(Goods *head);//输出总价

#endif _FUN_H_