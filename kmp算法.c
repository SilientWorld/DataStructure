//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//#define maxsize 20
//typedef int Status;
//typedef char String[maxsize + 1];
//Status AssignString(String S, char* chars)/* 生成一个其值等于chars的串T */
//{
//    if (strlen(chars) > maxsize)
//        return ERROR;
//    else
//    {
//        S[0] = strlen(chars);
//        for (int i = 1; i <= S[0]; i++)
//            S[i] = *(chars + i - 1);
//        return OK;
//    }
//}
//Status ClearString(String S)//清空字符串
//{
//    S[0] = 0;
//    return OK;
//}
//Status StringLength(String S)//返回字符串长度
//{
//    return S[0];
//}
//void show(String S)//输出字符串
//{
//    for (int i = 1; i <= S[0]; i++)
//        printf("%c", S[i]);
//    printf("\n");
//}
//void GetNext(String S, int* next)//根据字串形成next数组
//{
//    int i = 1, j = 0;
//    next[1] = 0;
//    while (i < S[0])
//    {
//        if (j == 0 || S[i] == S[j])
//        {
//            ++i;
//            ++j;
//            next[i] = j;
//        }
//        else j = next[j];
//    }
//}
//Status IndexKmp(String S, String T, int pos)
//{
//    int i = pos;//i用于S的下标值，从pos开始查起
//    int j = 1;//j为T的下标值
//    int next[50];
//    GetNext(T, next);//得到next数组
//    while (i <= S[0] && j <= T[0])
//    {
//        if (j == 0 || S[i] == T[j])
//        {
//            ++i;
//            ++j;
//        }
//        else j = next[j];//j退回合适位置，i不变
//    }
//    if (j > T[0])
//        return i - T[0];
//    else return 0;
//}
//Status GetNextval(String S, int* nextval)
//{
//    int i = 1, j = 0;
//    nextval[1] = 0;
//    while (i < S[0])
//    {
//        if (j == 0 || S[i] == S[j])
//        {
//            ++i;
//            ++j;
//            if (S[i] != S[j])
//                nextval[i] = j;//j为此时nextval在i位置的值
//            else nextval[i] = nextval[j];//nextvval赋值给nextval在i位置的值
//        }
//        else j = nextval[j];//若字母不同，则k值回溯
//    }
//}
//Status IndexKmp1(String S, String T, int pos)
//{
//    int i = pos;
//    int j = 1;
//    int nextval[50];
//    GetNext(T, nextval);
//    while (i <= S[0] && j <= T[0])
//    {
//        if (j == 0 || S[i] == T[j])
//        {
//            ++i;
//            ++j;
//        }
//        else j = nextval[j];
//    }
//    if (j > T[0])
//        return i - T[0];
//    else return 0;
//}
//void NextPrint(int* next, int length)//输出next数组
//{
//    int i;
//    for (i = 1; i <= length; i++)
//        printf("%d", next[i]);
//    printf("\n");
//}
//int main()
//{
//    int i, * p;
//    String s1, s2;
//    AssignString(s1, "abcaex");
//    printf("s1=");
//    show(s1);
//    i = StringLength(s1);
//    if (i)
//        printf("s1串的长度为:%d\n", StringLength(s1));
//    p = (int*)malloc((sizeof(int)) * (i + 1));
//    GetNext(s1, p);
//    printf("next数组为：");
//    NextPrint(p, StringLength(s1));
//    GetNextval(s1, p);
//    printf("nextval数组为：");
//    NextPrint(p, StringLength(s1));
//    AssignString(s1, "aaaabdecaa");
//    printf("s1=");
//    show(s1);
//    i = StringLength(s1);
//    if (i)
//        printf("s1的长度为：%d\n", StringLength(s1));
//    p = (int*)malloc((sizeof(int)) * (i + 1));
//    GetNext(s1, p);
//    printf("next数组为：");
//    NextPrint(p, StringLength(s1));
//    GetNextval(s1, p);
//    printf("nextval数组为：");
//    NextPrint(p, StringLength(s1));
//    AssignString(s1, "aaaaaaaaaaaaaaaaaaab");
//    printf("s1=");
//    show(s1);
//    AssignString(s2, "aaaaaaaaab");
//    printf("s2=");
//    show(s2);
//    printf("主串和子串在第%d个字符处首次匹配（KMP算法）\n", IndexKmp(s1, s2, 1));
//    printf("主串和子串在第%d个字符处首次匹配（KMP改良算法）\n", IndexKmp1(s1, s2, 1));
//    return 0;
//}