//#include <stdio.h>
//#include <string.h>
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//#define maxsize 40
//typedef int Status;
//typedef char String[maxsize + 1];
//Status AssignString(String T, char* chars)
//{/* 生成一个其值等于chars的串T */
//    if (strlen(chars) > maxsize)
//        return ERROR;
//    else
//    {
//        T[0] = strlen(chars);
//        for (int i = 1; i <= T[0]; i++)
//            T[i] = *(chars + i - 1);
//        return OK;
//    }
//}
//Status CopyString(String T, String S)//复制字符串
//{
//    for (int i = 0; i <= T[0]; i++)
//        T[i] = S[i];
//    return OK;
//}
//Status EmptyString(String S)//判断字符串为空
//{
//    if (S[0] == 0)
//        return TRUE;
//    else return FALSE;
//}
//Status StringLength(String s)//返回字符串长度
//{
//    return s[0];
//}
//Status ClearString(String s)//清空字符串
//{
//    s[0] = 0;
//    return OK;
//}
//Status StringCompare(String S, String T)
//{/*  初始条件: 串S和T存在 */
///*  操作结果: 若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0 */
//    for (int i = 1; i <= T[0] && i <= S[0]; i++)
//    {
//        if (S[i] != T[i])
//            return S[i] - T[i];
//    }
//    return S[0] - T[0];
//}
//Status StringCat(String S, String T1, String T2)
//{/* 用T返回S1和S2联接而成的新串。若未截断，则返回TRUE，否则FALSE */
//    if (T1[0] + T2[0] <= maxsize)
//    {//已截断
//        for (int i = 1; i <= T1[0]; i++)
//            S[i] = T1[i];
//        for (int i = 1; i <= T2[0]; i++)
//            S[i + T1[0]] = T2[i];
//        S[0] = T1[0] + T2[0];
//        return TRUE;
//    }
//    else
//    {//未截断
//        for (int i = 1; i <= T1[0]; i++)
//            S[i] = T1[i];
//        for (int i = 1; i <= maxsize - T1[0]; i++)
//            S[i + T1[0]] = T2[i];
//        S[0] = maxsize;
//        return FALSE;
//    }
//}
//Status SubString(String Sub, String S, int len, int pos)
//{/* 用Sub返回串S的第pos个字符起长度为len的子串。 */
//    if (pos<1 || pos>S[0] || len<0 || len>S[0] - pos + 1)
//        return ERROR;
//    else
//    {
//        for (int i = 1; i <= len; i++)
//            Sub[i] = S[pos - i + 1];
//        Sub[0] = len;
//        return OK;
//    }
//}
//Status Index(String S, String T, int pos)
//{/* 返回子串T在主串S中第pos个字符之后的位置。若不存在,则函数返回值为0。 */
///* 其中,T非空,1≤pos≤StrLength(S)。 */
//    int i = pos;
//    int j = 1;
//    while (i <= S[0] && j <= T[0])
//    {
//        if (S[i] == T[j])//如果两个字母相同
//        {
//            ++i;//指针向后移动一位
//            ++j;
//        }
//        else
//        {
//            i = i - j + 2;/* i退回到上次匹配首位的下一位 */
//            j = 1;/* j退回到子串T的首位 */
//        }
//    }
//    if (j > S[0])
//        return i - T[0];
//    else return 0;
//}
//Status StringInsert(String S, String T, int pos)
//{/*  初始条件: 串S和T存在,1≤pos≤StrLength(S)+1 */
///*  操作结果: 在串S的第pos个字符之前插入串T。完全插入返回TRUE,部分插入返回FALSE */
//    int i;
//    if (pos<1 || pos>S[0] + 1)
//        return ERROR;
//    if (S[0] + T[0] <= maxsize)
//    {//全部插入
//        for (i = S[0]; i >= pos; i--)
//            S[i + T[0]] = S[i];
//        for (i = pos; i < pos + T[0]; i++)
//            S[i] = T[i - pos + 1];
//        S[0] = S[0] + T[0];
//        return TRUE;
//    }
//    else
//    {//部分插入
//        for (i = maxsize; i <= pos; i--)
//            S[i] = S[i - T[0]];
//        for (i = pos; i < pos + T[0]; i++)
//            S[i] = T[i - pos + 1];
//        S[0] = maxsize;
//        return FALSE;
//    }
//}
//Status StringDelete(String S, int pos, int len)
//{/*  初始条件: 串S存在,1≤pos≤StrLength(S)-len+1 */
///*  操作结果: 从串S中删除第pos个字符起长度为len的子串 */
//    int i;
//    if (pos<1 || pos>S[0] + 1 - len || len < 0)
//        return FALSE;
//    for (i = pos + len; i <= S[0]; i++)
//        S[i - len] = S[i];
//    S[0] = S[0] - len;
//    return OK;
//}
//void show(String T)
//{
//    for (int i = 1; i <= T[0]; i++)
//        printf("%c", T[i]);
//    printf("\n");
//}
//int main()
//{
//    int i, j, k;
//    char s;
//    String t, s1, s2, s3;
//    printf("请输入串1：");
//    k = AssignString(s1, "abcd");
//    show(s1);
//    if (!k)
//        return ERROR;
//    printf("此时串长为%d\n", StringLength(s1));
//    CopyString(s2, s1);
//    printf("此时的串2为：");
//    show(s2);
//    k = AssignString(s3, "efghk");
//    printf("串3为：");
//    show(s3);
//    i = StringCompare(s1, s3);
//    if (i < 0)
//        s = '<';
//    else if (i == 0)
//        s = '=';
//    else if (i > 0)
//        s = '>';
//    printf("串1%c串2\n", s);
//    k = StringCat(t, s1, s3);
//    printf("两串链接后的新串为：");
//    show(t);
//    StringInsert(t, s2, 2);
//    printf("在串2的第2个字符之前插入串t,新串2为：");
//    show(t);
//    i = Index(s2, t, 1);
//    printf("s2的第%d个字母起和t第一次匹配\n", i);
//    SubString(t, s2, 1, 1);
//    printf("串t为：");
//    show(t);
//    StringDelete(t, 4, 3);
//    printf("删除后的串为：");
//    show(t);
//    ClearString(t);
//    if (EmptyString(t))
//        printf("清空后，t串的长度为：%d\n", StringLength(t));
//    return 0;
//}