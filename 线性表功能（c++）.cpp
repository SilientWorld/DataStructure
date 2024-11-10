//#include <iostream>
//using namespace std;
//const int OK = 1;
//const int ERROR = 0;
//const int TRUE = 1;
//const int FALSE = 0;
//const int maxsize = 20;
//class SqList
//{
//public:
//	int length;
//	int data[maxsize];
//};
//typedef int Status;
//Status LengthList(SqList L)
//{
//	return L.length;
//}
//Status initLsit(SqList* L)//初始化操作，建立一个空线性表
//{
//	L->length = 0;
//	return OK;
//}
//Status ListEmpty(SqList L)//判断线性表是否为空
//{
//	if (L.length == 0)
//		return TRUE;
//	else return FALSE;
//}
//Status ClearList(SqList* L)//如果线性表不为空，则清空
//{
//	if (L->length != 0)
//		L->length = 0;
//	return OK;
//}
//Status GetElem(SqList L, int i, int* e)
//{
//	if (L.length == 0 || i<1 || i>maxsize)
//		return ERROR;
//	else *e = L.data[i - 1];//将线性表第i个元素返回给e,则下标为i-1
//	return OK;
//}
//Status LocateElem(SqList L, int e)
//{//将线性表L中想查找的数与e比较，
// //如果查找成功，返回该元素在表中的序号，反之返回0表示失败
//	int i;
//	if (L.length == 0 )
//		return FALSE;
//	for (i = 0; i < L.length; i++)
//	{
//		if (L.length == e)
//			break;
//	}
//	if (i >= L.length)
//		return FALSE;
//	return i + 1;
//}
//Status ListInsert(SqList* L, int i, int e)//在线性表第i个元素插入新元素e
//{
//	if (L->length == maxsize || i<1 || i>L->length+1)
//		return ERROR;
//	if(i <= L->length)
//	{
//		for(int k=L->length-1;k>=i-1;k--)
//			L->data[k+1]=L->data[k];
//	}
//	L->data[i - 1] = e;
//	L->length++;
//	return OK;
//}
//Status ListDelete(SqList* L, int i, int* e)//删除线性表第i个元素，用e返回其值
//{
//	if (L->length == 0 || i<1 || i>L->length + 1)
//		return ERROR;
//	*e = L->data[i - 1];
//	if (i <= L->length)
//	{
//		for (int k = i; k < L->length; k++)
//		{
//			L->data[k - 1] = L->data[k];
//		}
//	}
//	L->length--;
//	return OK;
//}
//void show(SqList L)
//{
//	for (int i = 0; i < L.length; i++)
//		cout <<" "<<L.data[i];
//	cout << endl;
//}
//int main()
//{
//	SqList L;
//	Status i;
//	int e, j;
//	i = initLsit(&L);
//	cout<<"初始化后，L.length="<< L.length<<endl;
//	for (j = 1; j <= 5; j++)
//		i = ListInsert(&L,1, j);
//	cout<<"在L的表头依次插入1～5后：L.data=";
//	show(L);
//	cout<<"插入后，L.length="<< L.length<<endl;
//	i = ClearList(&L);
//	if (i)
//		cout<<"L为空！L.length="<<L.length<<endl;
//	else cout<<"L不为空!"<<endl;
//	for (j = 1; j <= 10; j++)
//		ListInsert(&L, j, j);
//	cout<<"在L的表尾依次插入1～10后：L.data=";
//	show(L);
//	ListInsert(&L, 1, -1);
//	cout<<"在L的表头插入-1后：L.data=";
//	show(L);
//	ListInsert(&L, 3, 9);
//	cout<<"在L的第3个位置插入9后：L.data=";
//	show(L);
//	GetElem(L, 6, &e);
//	cout<<"第六个元素是:"<< e<<endl;
//	ListDelete(&L, 3, &e);
//	cout<<"删除第3个元素是:"<< e<<endl;
//	show(L);
//	return 0;
//}