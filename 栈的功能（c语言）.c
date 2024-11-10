//#include <stdio.h>
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//typedef int Status;
//#define maxsize 20
//typedef struct Stack
//{
//    int top;
//    int data[maxsize];
//}Stack;
//Status InitStack(Stack* s)//初始化栈
//{
//    s->top = -1;
//    return OK;
//}
//Status ClearStack(Stack* s)//清空栈
//{
//    s->top = -1;
//    return OK;
//}
//Status EmptyStack(Stack s)//判断栈是否为空
//{
//    if (s.top = -1)
//        return TRUE;
//    else return FALSE;
//}
//Status GetTop(Stack s, int* e)
//{//判断栈是否为空，不为空返回栈顶元素
//    if (s.top == -1)
//        return ERROR;
//    else *e = s.data[s.top];
//    return TRUE;
//}
//Status StackLength(Stack s)//返回栈长
//{
//    return s.top + 1;
//}
//Status Push(Stack* s, int e)//插入操作
//{
//    if (s->top == maxsize - 1)//判断插入前栈是否满
//        return ERROR;
//    else
//    {
//        s->top++;
//        s->data[s->top] = e;
//    }
//    return OK;
//}
//Status Pop(Stack* s, int* e)//删除操作
//{
//    if (s->top == -1)//判断栈是否为空
//        return ERROR;
//    else
//    {
//        *e = s->data[s->top];
//        s->top--;
//    }
//    return OK;
//}
//void show(Stack s)//输出操作
//{
//    for (int i = 0; i <= s.top; i++)
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
//    for (i = 0; i < 10; i++)
//        Push(&s, i);
//    printf("栈中的元素：");
//    show(s);
//    printf("插入后，栈长=%d\n", StackLength(s));
//    GetTop(s, &e);
//    printf("此时栈顶元素为：%d\n", e);
//    Pop(&s, &e);
//    printf("删去栈顶的元素是：%d\n", e);
//    printf("此时栈中的元素：");
//    show(s);
//    GetTop(s, &e);
//    printf("此时栈顶元素为：%d\n", e);
//    printf("删除元素后，栈长=%d\n", StackLength(s));
//    ClearStack(&s);
//    if (EmptyStack(s))
//        printf("清空后，栈长=%d\n", StackLength(s));
//    return 0;
//}