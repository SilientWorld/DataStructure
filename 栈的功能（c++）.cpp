//#include <iostream>
//using namespace std;
//const int OK = 1;
//const int ERROR = 0;
//const int TRUE = 1;
//const int FALSE = 0;
//const int maxsize = 20;
//class stack
//{
//public:
//	int data[maxsize];
//	int top;
//};
//typedef int Status;
//Status InitStack(stack*s)//初始化栈
//{
//	s->top = -1;//空栈记作-1，栈存在一个元素记为0
//	return OK;   
//}
//Status ClearStack(stack* s)//清空栈
//{
//		s->top = -1;
//	return OK;
//}
//Status StackEmpty(stack s)//判断栈是否为空
//{
//	if (s.top == -1)
//		return TRUE;
//	else return FALSE;
//}
//Status GetTop(stack s, int* e)
//{
//	if (s.top == 0)
//		*e = s.data[s.top];
//	else return ERROR;
//}
//Status Push(stack* s, int e)//入栈操作
//{
//	if (s->top == maxsize - 1)//判断栈满
//		return ERROR;
//	else
//	{
//		s->top++;// 栈顶指针加一 
//		s->data[s->top]=e;//将新插入元素赋值给栈顶空间
//	}
//	return OK;
//}
//Status Pop(stack* s, int *e)//出栈操作
//{
//	if (s->top == -1)
//		return ERROR;
//	else
//	{
//		*e = s->data[s->top];//将要删除的栈顶元素赋值给e
//		s->top--;//栈顶指针减一
//	}
//	return OK;
//}
//void show(stack s)
//{
//	int i=0;
//	while (i <= s.top)
//		cout<< s.data[i++]<<" ";
//	cout << endl;
//}
//int StackLength(stack s)
//{
//	return s.top + 1;
//}
//int main()
//{
//	int i, e;
//	stack s;
//	if (InitStack(&s) == OK)
//	{
//		for (i = 0; i < 10; i++)
//			Push(&s, i);
//	}
//	cout<<"栈中的元素为：";
//	show(s);
//	Pop(&s, &e);
//	cout<<"弹出的栈顶元素为e="<< e<<endl;
//	cout<<"剩下的栈元素为：";
//	show(s);
//	GetTop(s, &e);
//	cout<<"栈顶元素 e="<<e<<"," << "栈的长度为" << StackLength(s) << endl;
//	if (StackEmpty(s) != 0)
//		cout<<"栈为空！";
//	else cout<<"栈不为空！StackLength="<< StackLength(s)<<endl;
//	ClearStack(&s);
//	cout<<"清空栈后，stackLength="<<StackLength(s)<<endl;
//	if (StackEmpty(s) != 0)
//		printf("栈为空！");
//	return 0;
//}