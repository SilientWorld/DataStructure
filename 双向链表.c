//#include <stdio.h>
//#include <stdlib.h>
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//typedef int Status;
//struct DoubleList
//{
//	int data;
//	struct DoubleList* prior;//直接前驱指针
//	struct DoubleList* next;//直接后驱指针
//}node;
//typedef struct DoubleList *DoubleList;
//Status InitDoubleList(DoubleList *d)//初始化双向链表
//{
//	*d = (DoubleList)malloc(sizeof(node));
//	if (!(*d))
//		return ERROR;
//	(*d)->prior = NULL;
//	(*d)->next = NULL;
//	return OK;
//}
//Status DoubleListLength(DoubleList d)//双向链表长度
//{
//	DoubleList p=d->next;
//	int i=0;
//	while (p)
//	{
//		i++;
//		p = p->next;
//	}
//	return i;
//}
//Status GetElem(DoubleList d, int i, int *e)//查找元素
//{
//	DoubleList p=d->next;
//	int j=1;
//	while (p && j < i)
//	{
//		p = p->next;
//		j++;
//	}
//	if (!p || j > i)
//		return FALSE;
//	*e = p->data;
//	return OK;
//}
//Status InsertDoubleList(DoubleList *d, int i, int e)
//{
//	DoubleList s,p;
//	p = *d;
//	int j = 1;
//	while (p && j < i)
//	{
//		p = p->next;
//		j++;
//	}
//	if (!p || j > i)
//		return ERROR;
//	s = (DoubleList)malloc(sizeof(node));
//	s->data = e;
//	if (!p->next) //插入到最后
//	{ 
//		p->next = s;
//		s->prior = p;
//		s->next = NULL;
//		return OK;
//	}
//	else 
//	{
//		s->prior = p;
//		s->next = p->next;
//		p->next->prior = s;
//		p->next = s;
//	}
//	return OK;
//}
//Status DeleteDoubleList(DoubleList* d, int i, int* e)
//{
//	DoubleList p = malloc(sizeof(node));
//	p = (*d)->next;
//	int j = 1;
//	while (p && j < i)
//	{
//		p = p->next;
//		j++;
//	}
//	if (!p || j > i)
//		return ERROR;
//	if (p->next!=NULL)
//	{	
//		*e = p->data;
//		p->prior->next = p->next;
//		p->next->prior = p->prior;
//		free(p);
//	}
//	else
//	{
//		p->prior->next = NULL;
//		free(p);
//	}
//	return OK;
//}
//Status ClearDoubleList(DoubleList* d)
//{
//	DoubleList p, q;
//	p = (*d)->next;
//	while (p)
//	{
//		q = p->next;
//		free(p);
//		p = q;
//	}
//	(*d)->next = NULL;
//	return OK;
//}
//void show(DoubleList d)
//{
//	DoubleList p = d->next;
//	while (p)
//	{
//		printf("%d ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//int main()
//{
//	DoubleList d ;
//	int e;
//	Status i = InitDoubleList(&d);
//	printf("初始化后，length=%d\n", DoubleListLength(d));
//	for (int j = 1; j <= 5; j++)
//		i = InsertDoubleList(&d, j, j);
//	show(d);
//	DeleteDoubleList(&d, 2, &e);
//	show(d);
//	ClearDoubleList(&d);
//	printf("清空后，length=%d\n", DoubleListLength(d));
//	return 0;
//}