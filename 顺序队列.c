//#include <stdio.h>
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//#define maxsize 20
//typedef int Status;
//struct queue
//{
//	int data[maxsize];
//	int front;//定义头指针
//	int rear;//尾指针，若队列不空，指向队列尾元素的下一个位置
//};
//typedef struct queue queue;
//Status InitQueue(queue* q)//初始化一个空队列
//{
//	q->front = q->rear = 0;
//	return OK;
//}
//Status ClearQueue(queue* q)//清空队列
//{
//	q->front = q->rear = 0;
//	return OK;
//}
//Status EmptyQueue(queue q)//判断队列是否为空
//{
//	if (q.front == q.rear)
//		return TRUE;
//	else return FALSE;
//}
//Status QueueLength(queue* q)
//{//返回Q的元素个数，也就是队列的当前长度
//	return (q->rear - q->front + maxsize) % maxsize;
//}
//Status Gethead(queue q, int* e)
//{/* 若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR */
//	if (q.front == q.rear)
//		return ERROR;
//	*e = q.data[q.front];
//	return OK;
//}
///* 若队列未满，则插入元素e为Q新的队尾元素 */
//Status InsertQueue(queue* q, int e)
//{
//	if ((q->rear+1)%maxsize==q->front)//判断队列满
//		return FALSE;
//	else
//	{
//		q->data[q->rear] = e;
//		q->rear = (q->rear + 1) % maxsize;
///* rear指针向后移一位置，若到最后则转到数组头部  */
//	}
//	return OK;
//}
///* 若队列不空，则删除Q中队头元素，用e返回其值 */
//Status DeleteQueue(queue* q, int* e)
//{
//	if ((q->rear + 1) % maxsize == q->front)//判断队列满
//		return FALSE;
//	*e = q->data[q->front];//返回队头元素
//	q->front=(q->front + 1) % maxsize;
///* front指针向后移一位置，若到最后则转到数组头部 */
//	return OK;
//}
//void show(queue q)
//{/* 从队头到队尾依次对队列Q中每个元素输出 */
//	int i = q.front;
//	while ((i + q.front) != q.rear)
//	{
//		printf("%d ", q.data[i]);
//		i = (i + 1) % maxsize;
//	}
//	printf("\n");
//}
//int main()
//{
//	Status j;
//	queue q;
//	int e;
//	InitQueue(&q);
//	if (EmptyQueue(q) == 1)
//		printf("初始化队列后，队列为空!\n");
//	else printf("初始化队列后，队列不为空!\n");
//	for (int i = 0; i < 10; i++)
//		InsertQueue(&q, i);
//	show(q);
//	printf("队列长度为：%d\n", QueueLength(&q));
//	if (EmptyQueue(q) == 1)
//		printf("插入队列后，队列为空!\n");
//	else printf("插入队列后，队列不为空!\n");
//	DeleteQueue(&q, &e);
//	printf("删除的元素是%d\n",e);
//	show(q);
//	printf("队列长度为：%d\n", QueueLength(&q));
//	j = Gethead(q, &e);
//	if (j)
//		printf("现在队头元素为: %d\n", e);
//	ClearQueue(&q);
//	printf("队列长度为：%d\n", QueueLength(&q));
//	return 0;
//}