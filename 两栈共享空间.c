//#include <stdio.h>
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//#define maxsize 20
//typedef int Status;
//typedef struct Stack
//{
//    int data[maxsize];
//    int top1;
//    int top2;
//}Stack;
//Status InitStack(Stack* s)//初始化
//{
//    s->top1 = -1;
//    s->top2 = maxsize;
//    return OK;
//}
//Status ClearStack(Stack* s)//清空
//{
//    s->top1 = -1;
//    s->top2 = maxsize;
//    return OK;
//}
//Status StackLength(Stack s)//栈长
//{
//    return s.top1 + 1 + maxsize - s.top2;
//}
//Status EmptyStack(Stack* s)//判断是否为空
//{
//    if (s->top1 == -1 && s->top2 == maxsize)
//        return TRUE;
//    else return FALSE;
//}
//Status StackInsert(Stack* s, int e, int StackNum)//插入操作
//{
//    if (s->top1 + 1 == s->top2)
//        return ERROR;
//    else
//    {
//        if (StackNum == 1)
//            s->data[++s->top1] = e;
//        else if (StackNum == 2)
//            s->data[--s->top2] = e;
//    }
//    return OK;
//}
//Status StackDelete(Stack* s, int* e, int StackNum)//删除操作
//{
//    if (s->top1 == -1 && s->top2 == maxsize)
//        return ERROR;
//    else
//    {
//        if (StackNum == 1)
//            *e = s->data[s->top1--];
//        if (StackNum == 2)
//            *e = s->data[s->top2++];
//    }
//    return OK;
//}
//Status GetTop(Stack s, int* e, int StackNum)//返回栈顶元素
//{
//    if (StackNum == 1)
//        *e = s.data[s.top1];
//    if (StackNum == 2)
//        *e = s.data[s.top2];
//    return OK;
//}
//void show(Stack s)//输出操作
//{
//    for (int i = 0; i <= s.top1; i++)
//        printf("%d ", s.data[i]);
//    for (int i = s.top2; i < maxsize; i++)
//        printf("%d ", s.data[i]);
//    printf("\n");
//}
//int main()
//{
//    Stack s;
//    int i, e;
//    i = InitStack(&s);
//    if (i)
//        printf("初始化后，栈长=%d\n", StackLength(s));
//    for (i = 0; i < 5; i++)
//        StackInsert(&s, i, 1);
//    printf("栈的元素为:");
//    show(s);
//    GetTop(s, &e, 1);
//    printf("栈1顶的元素为%d\n", e);
//    printf("栈1长=%d\n", StackLength(s));
//    for (i = maxsize; i >= maxsize - 2; i--)
//        StackInsert(&s, i, 2);
//    GetTop(s, &e, 2);
//    printf("栈2顶的元素为%d\n", e);
//    printf("此时栈的元素为:");
//    show(s);
//    printf("插入后，栈1+栈2=%d\n", StackLength(s));
//    StackDelete(&s, &e, 1);
//    printf("栈1删除的元素为：%d\n", e);
//    GetTop(s, &e, 1);
//    printf("此时栈1顶的元素为%d\n", e);
//    StackDelete(&s, &e, 2);
//    printf("栈2删除的元素为：%d\n", e);
//    printf("删除后的元素为：");
//    show(s);
//    GetTop(s, &e, 2);
//    printf("栈2顶的元素为%d\n", e);
//    printf("删除后，栈1+栈2=%d\n", StackLength(s));
//    ClearStack(&s);
//    if (EmptyStack(&s))
//        printf("清空后，栈长=%d\n", StackLength(s));
//    return 0;
//}