//#include <stdio.h>
//#include <stdlib.h>
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//typedef int Status;
//typedef struct queue
//{
//    int data;
//    struct queue* next;
//}Queue, * QueueLink;
//typedef struct QueueNode
//{
//    QueueLink front, rear;
//}QueueNode;
//Status InitQueue(QueueNode* q)//初始化链队列
//{
//    q->front = q->rear = (QueueLink)malloc(sizeof(Queue));
//    if (q->front == NULL)//判断是否生成头结点
//        return ERROR;
//    q->front->next = NULL;
//    return OK;
//}
//Status ClearQueue(QueueNode* q)//清空操作
//{
//    QueueLink p, r;
//    q->front = q->rear;
//    p = q->front->next;
//    while (p)
//    {
//        r = p;
//        p = p->next;
//        free(r);
//    }
//    q->front->next = NULL;
//    return OK;
//}
//Status EmptyQueue(QueueNode q)//判断是否为空
//{
//    if (q.front == q.rear)
//        return TRUE;
//    else return FALSE;
//}
//Status LengthQueue(QueueNode q)//返回队列长度
//{
//    int i=0;
//    QueueLink p=q.front;
//    while (q.rear != p)
//    {
//        i++;
//        p = p->next;
//   }
//    //for (p = q.front, i = 0; p < q.rear; i++, p = p->next);
//    return i;
//
//}
//Status InsertQueue(QueueNode* q, int e)//插入操作
//{
//    QueueLink p = malloc(sizeof(Queue));
//    if (p == NULL)
//        return ERROR;
//    else
//    {
//        p->data = e;
//        p->next = NULL;
//        q->rear->next = p;
//        q->rear = p;
//    }
//    return OK;
//}
//Status DeleteQueue(QueueNode* q, int* e)//删除操作
//{
//    QueueLink p;
//    if (q->front == q->rear)
//        return ERROR;
//    p = q->front->next;
//    *e = p->data;
//    q->front->next = p->next;
//    if (q->rear == p)
//        q->rear = q->front;
//    return OK;
//}
//void show(QueueNode q)//输出操作
//{
//    QueueLink p = q.front->next;
//    while (p)
//    {
//        printf("%d ", p->data);
//        p = p->next;
//    }
//    printf("\n");
//}
//int main()
//{
//    QueueNode q;
//    int i, e;
//    i = InitQueue(&q);
//    if (i)
//        printf("初始化后，链队列的长度为%d\n", LengthQueue(q));
//    for (i = 1; i < 10; i++)
//        InsertQueue(&q, i);
//    printf("插入后，链队列的元素为：");
//    show(q);
//    printf("插入后，链队列的长度为%d\n", LengthQueue(q));
//    DeleteQueue(&q, &e);
//    printf("删除的元素为：%d\n", e);
//    printf("删除后，链队列的元素为：");
//    show(q);
//    printf("删除后，链队列的长度为%d\n", LengthQueue(q));
//    ClearQueue(&q);
//    if (EmptyQueue(q))
//        printf("清空后，链队列的长度为%d\n", LengthQueue(q));
//    return 0;
//}