//#include <stdio.h>
//#include <stdlib.h>
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//#define maxsize 20
//typedef int Status;
////typedef struct StackNode
////{
////	SElemType data;
////	struct StackNode* next;
////}StackNode, * LinkStackPtr;//将StackNode该结构体起两个名字，
////                           分别是StackNode和*LinkStackPtr
////
////
////typedef struct
////{
////	LinkStackPtr top;
////	int count;
////}LinkStack;//将LinkStack起别名LinkStack
//
///* 链栈结构 */
//struct StackNode
//{
//	int data;
//	struct StackNode* next;
//};
//typedef struct StackNode StackNode;
//typedef struct StackNode* LinkStackPtr;
//struct LinkStack
//{
//	LinkStackPtr top;//结构体嵌套，使得top成为结点，
//	//有数据域和指针域
//	int count;
//};
//typedef struct LinkStack LinkStack;
//Status InitStack(LinkStack* s)//初始化链栈
//{
//	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
//	if (s->top == 0)
//		return ERROR;
//	s->top = NULL;
//	s->count = 0;
//	return OK;
//}
//Status ClearStack(LinkStack* s)//清空链栈
//{
//	LinkStackPtr p, q;
//	p = s->top;
//	while (p != NULL)
//	{
//		q = p;//把p赋给q
//		p = p->next;//p指向下一个结点
//		free(q);//删掉q结点
//	}
//	s->count = 0;
//	return OK;
//}
//Status StackEmpty(LinkStack* s)//判断链栈是否为空
//{
//	if (s->top == 0 || s->count == 0)
//		return TRUE;
//	else return FALSE;
//}
//Status ListLength(LinkStack s)//判断链栈长度
//{
//	return s.count;
//}
//Status GetPop(LinkStack s, int* e)//返回栈顶元素
//{
//	if (s.top == NULL)
//		return ERROR;
//	else *e = s.top->data;
//}
//Status Push(LinkStack* s, int e)//插入功能
//{/* 插入元素e为新的栈顶元素 */
//	LinkStackPtr p;
//	p = (LinkStackPtr)malloc(sizeof(StackNode));
//	p->data = e;
//	p->next = s->top;/* 把当前的栈顶元素赋值给新结点的直接后继*/
//	s->top=p; /* 将新的结点s赋值给栈顶指针*/
//	s->count++;
//	return OK;
//}
//Status Pop(LinkStack* s, int* e)//出栈操作
//{/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
//	LinkStackPtr p;
//	if (StackEmpty(&s)!=0)
//		return ERROR;
//	*e = s->top->data;
//	p = s->top;/* 将栈顶结点赋值给p*/
//	s->top = s->top->next;  /* 使得栈顶指针下移一位，指向后一结点*/
//	free(p);/* 释放结点p */ 
//	s->count--;
//	return OK;
//}
//void show(LinkStack s)
//{
//	LinkStackPtr p;
//	p = s.top;
//	while (p != 0)
//	{
//		printf("%d ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//	return OK;
//}
//int main()
//{
//	LinkStack s;
//	int i, e;
//	if (InitStack(&s) == OK)
//	{
//		for (i = 1; i <= 10; i++)
//			Push(&s, i);
//	}
//	printf("栈中元素依次为：");
//	show(s);
//	Pop(&s, &e);
//	printf("弹出的栈顶元素 e=%d\n", e);
//	GetPop(s, &e);
//	printf("栈顶元素 e=%d 栈的长度为%d\n", e, ListLength(s));
//	ClearStack(&s);
//	printf("清空栈后，栈空否：%d(1:空 0:否)\n", StackEmpty(&s));
//	return 0;
//}