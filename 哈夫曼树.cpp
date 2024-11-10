//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
///*其实由于哈夫曼树结点的度要么为0，要么为2，并且输入的编码的元素必为
//叶节点，所以n个元素也就是n个叶节点的哈夫曼树必为2n-1个总结点。知道了
//结点个数，我们肯定更喜欢用数组来存储哈夫曼树，而孩子和双亲则类似于静态
//链表，用下标代替地址*/
//
//typedef struct HaFumTree
//{
//	char data;//输入元素
//	int weigh;//元素对应的权重
//	int parent;//根节点
//	int LChild;//左孩子
//	int RChild;//右孩子
//}HaFuManNode, * HaFuManTreeNode;
//typedef char** HaFuManTreeCode;//这个其实就是把char** 这个二维数组换成这个名字 
//void SearchMinNum(HaFuManTreeNode& T, int length, int& MinNumber1, int& MinNumber2)
//{
//	int i;
//	int num = 200;//这里的num就是用来找到最小元素的 
//	for (i = 1; i <= length; i++)//记录最小的那一个
//	{
//		//只能选择没有双亲的，即没被选过的 
//		if (T[i].weigh < num && T[i].parent == 0)
//		{
//			num = T[i].weigh;
//			MinNumber1 = i;
//		}
//	}
//	num = 200;
//	for (i = 1; i <= length; i++)//记录第二小的那一个
//	{
//		//i不等于于min1代表把第一遍选出的最小元素剔除了 
//		if (T[i].weigh < num && T[i].parent == 0 && i != MinNumber1)
//		{
//			num = T[i].weigh;
//			MinNumber2 = i;
//		}
//	}
//}
//void InitHaFuManTreeNode(HaFuManTreeNode& T, char* Datas, int* Weighs, int n)
//{
//	int i;//用来记录下标 
//	int min1, min2;
//	T = new HaFuManNode[2 * n];
//	/*为了方便，我们不用数组的第0个元素，所以申请2n个空间*/
//	for (i = 1; i <= n; i++)
//	{/*对于叶节点，我们将其全部放在数组前n个里面，后面n-1个用来放合成的结点*/
//		T[i].data = Datas[i - 1];
//		T[i].weigh = Weighs[i - 1];
//	}
//	for (i = 0; i < 2 * n; i++)
//	{//由于数组0号我们没有用，所以将他们全部初始化为0，代表没有 
//		T[i].LChild = 0;
//		T[i].RChild = 0;
//		T[i].parent = 0;
//	}
//	for (i = n + 1; i < 2 * n; i++)
//	{//这里是开始给后面n-1个合成的元素找双亲和孩子 
//		SearchMinNum(T, i - 1, min1, min2);
//		T[i].weigh = T[min1].weigh + T[min2].weigh;
//		T[i].LChild = min1;
//		T[i].RChild = min2;
//		T[min1].parent = i;
//		T[min2].parent = i;
//	}
//}
//void InitHaFuManCode(HaFuManTreeNode& T, HaFuManTreeCode& HfmTreecode, int n)
//{
//	string str;
//	char* Temp = new char[n];//先用一个临时数组记录我们每一个元素的编码，记录好之后copy过去就行 
//	HfmTreecode = new char*[n+1];//先给外层malloc
//	int temp;//temp用来记录双亲结点
//	int j;//j用来给临时数组记录当前下标
//	int k;//k是用来记录当前元素的下标
//	Temp[n - 1] = '\0';//最后一个位置先弄上结束符 
//	for (int i = 1; i <= n; i++)
//	{
//		j = n - 1;//每次都要先指向结束符位置 
//		temp = T[i].parent;
//		k = i;
//		while (temp != 0)//以双亲为0作为结束标志 
//		{
//			if (T[temp].LChild == k)
//				Temp[--j] = '0';
//			else
//				Temp[--j] = '1';
//			k = temp;//往上走，走到当前元素的双亲 
//			temp = T[temp].parent;//temp也往上走 
//		}
//		HfmTreecode[i] = new char[n-j];//实际1上我们申请空间就只需要这个大小，从n减到当前的j 
//		strcpy(HfmTreecode[i], &Temp[j]);
//		/*注意这里copy的细节，我们tempArray在j下标前面的下标是没有任何东西的
//		我们只要从j到n这一截字符串，所以加地址加j的下标，表示只要从j地址开始的后面的字符串*/
//	}
//	delete []Temp;//释放临时空间1 
//}
//void ShowHfmTree(HaFuManTreeNode& T, HaFuManTreeCode HfmTreeCode, int n)//输出哈夫曼树
//{
//	for (int i = 1; i <= n; i++)
//		cout << "元素" << T[i].data << "的编码是:" << HfmTreeCode[i] << endl;
//	cout << "元素解码为：";
//	for (int i = 1; i <= n; i++)
//		cout <<  HfmTreeCode[i];
//	cout << endl;
//}
//int main()
//{
//	int n = 0;
//	cout<<"请输入元素个数：";
//	cin >> n;
//	/*由于我们下面要先输入的是一个个字符，空格换行等也是字符
//	所以说每一个getchar（）都是很有必要的，不然这些都会进入字符数组里面*/
//	getchar();//吸收换行符 
//	char ch;
//	char* Data = new char[n];//用来记录元素的临时数组 
//	int* Weigh = new int [n];//用来记录元素权重的临时数组
//	cout<<"请输入这"<<n<<"个元素：";
//	for (int i = 0; i < n; i++)//A  B  C  D  E F
//	{                          //27 8 15 15 30 5
//		ch = getchar();
//		getchar();//吸收空格符 
//		Data[i] = ch;
//	}
//	cout<<"请输入这"<<n<<"个元素对应的权重：";
//	for (int i = 0; i < n; i++)
//		cin>>Weigh[i];
//	HaFuManTreeNode T;
//	InitHaFuManTreeNode(T, Data, Weigh, n);
//	HaFuManTreeCode code;
//	InitHaFuManCode(T, code, n);
//	ShowHfmTree(T, code, n);
//	delete[]Data;
//	delete[]Weigh;
//	return 0;
//}