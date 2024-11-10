//#include <stdio.h>
//#include <stdlib.h>
//#define maxsize 12
//#define OK 1
//#define SUCCESS 1
//#define UNSUCCESS 0
//#define NULLKEY -32768
//typedef int Status;
//typedef struct HashTable//散列表
//{
//    int* elem;//存储元素地址
//    int count;//元素个数
//}HashTable;
//int m = 0;
//Status InitHashTable(HashTable* H)//初始化散列表
//{
//    m = maxsize;
//    H->count = m;
//    H->elem = (int*)malloc(sizeof(HashTable) * m);
//    for (int i = 0; i < m; i++)
//        H->elem[i] = NULLKEY;
//    return OK;
//}
//int Hash(int key)//散列函数
//{
//    return key % m;
//}
//Status InsertHash(HashTable* H, int key)//在散列表中插入元素
//{
//    int address = Hash(key);
//    while (H->elem[address] != NULLKEY)//如果该位置已经插入元素
//        address = (address + 1) % m;//寻找下一个空位置
//    H->elem[address] = key;
//}
//Status FindHash(HashTable* H, int key)//在散列表中查找元素
//{
//    int address = Hash(key);
//    while (H->elem[address] != key)
//    {
//        address = (address + 1) % m;
//        if (H->elem[address] == NULLKEY || H->elem[address] != key)
//            return UNSUCCESS;
//    }
//    return SUCCESS;
//}
//int main()
//{
//    HashTable H;
//    int result;
//    int a[maxsize] = { 12,67,56,16,25,37,22,29,15,47,48,34 };
//    InitHashTable(&H);
//    for (int i = 0; i < m; i++)
//        InsertHash(&H, a[i]);
//    result = FindHash(&H, 16);
//    if (result != 0)
//        printf("已经查找到该元素！\n");
//    else printf("未查找到该元素！\n");
//    return 0;
//}