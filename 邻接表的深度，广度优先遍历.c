//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#define ERROR 0
//#define OK 1
//typedef struct ENode 
//{
//    int adjVex;              //顶点
//    int weigh;              //边的权值
//    struct ENode* nextArc;   //指向下一个边结点
//}ENode;
//typedef struct 
//{
//    int NodeNum;           //图的当前顶点数
//    int EdgeNum;           //图的当前边数
//    ENode** arr;       //指向一维指针数组
//}LGraph;
//
//typedef struct 
//{
//    int front;
//    int rear;
//    int maxSize;    
//    int* element;
//}Queue;
//void InitQueue(Queue* Q, int mSize) //创建队列
//{
//    Q->maxSize = mSize;
//    Q->element = (int*)malloc(sizeof(int) * mSize);
//    Q->front = Q->rear = 0;
//}
//int EmptyQueue(Queue* Q)//判断队列是否为空
//{
//    return Q->front == Q->rear;
//}
//int FullQueue(Queue* Q) //判断队列是否满
//{
//    return (Q->rear + 1) % Q->maxSize == Q->front;
//}
//int Front(Queue* Q, int* x) //获取队头元素
//{
//    if (EmptyQueue(Q))      //空队列处理
//        return ERROR;
//    *x = Q->element[(Q->front + 1) % Q->maxSize];
//    return OK;
//}
//int EnQueue(Queue* Q, int x) 
//{
//    if (FullQueue(Q))      
//        return ERROR;
//    Q->rear = (Q->rear + 1) % Q->maxSize;
//    Q->element[Q->rear] = x;
//    return OK;
//}
//int DeQueue(Queue* Q) 
//{
//    if (EmptyQueue(Q))  
//        return ERROR;
//    Q->front = (Q->front + 1) % Q->maxSize;
//    return OK;
//}
//int InitGraph(LGraph* lg, int nSize) //邻接表的初始化
//{
//    int  i;
//    lg->NodeNum = nSize;
//    lg->EdgeNum = 0;
//    lg->arr = (ENode**)malloc(nSize * sizeof(ENode*)); 
//    if (!lg->arr) 
//        return ERROR;
//    else 
//    {
//        for (i = 0; i < lg->NodeNum; i++) 
//            lg->arr[i] = NULL;                       
//        return OK;
//    }
//}
//int FindArr(LGraph* lg, int u, int v) //邻接表的搜索边
//{
//    ENode* p;
//    if (u < 0 || v < 0 || u > lg->NodeNum - 1 || v > lg->NodeNum - 1 || u == v) 
//        return ERROR;
//    p = lg->arr[u];                 
//    while (p && p->adjVex != v) 
//        p = p->nextArc;
//    if (!p) 
//        return ERROR;          
//    else return OK;
//}
//int InsertArr(LGraph* lg, int u, int v, int w) //邻接表的插入边
//{
//    ENode* p;
//    if (u < 0 || v < 0 || u > lg->NodeNum - 1 || v > lg->NodeNum - 1 || u == v)
//        return ERROR;
//    if (FindArr(lg, u, v)) 
//        return ERROR;       
//    p = (ENode*)malloc(sizeof(ENode));        
//    p->adjVex = v;
//    p->weigh = w;
//    p->nextArc = lg->arr[u];                 
//    lg->arr[u] = p;
//    lg->EdgeNum++;                                 
//    return OK;
//}
//void DepthFind(int v, int *visited, LGraph g) //深度优先遍历算法
//{
//    ENode* w;
//    printf("%d ", v);                           
//    visited[v] = 1;                            //为顶点v打上访问标记
//    for (w = g.arr[v]; w; w = w->nextArc)
//    {          
//        if (!visited[w->adjVex]) 
//            DepthFind(w->adjVex, visited, g);    
//    }
//}
//void DepthSearch(LGraph g) //深度优先遍历
//{
//    int i;
//    int* visited = (int*)malloc(g.NodeNum * sizeof(int)); 
//    for (i = 0; i < g.NodeNum; i++) 
//        visited[i] = 0;                           
//    for (i = 0; i < g.NodeNum; i++) 
//    {                        
//        if (!visited[i]) 
//            DepthFind(i, visited, g);
//    }
//    free(visited);                                
//}
//void WidenFind(int v, int *visited, LGraph g) //宽度优先遍历算法
//{
//    ENode* w;
//    Queue q;
//    InitQueue(&q, g.NodeNum);//初始化队列
//    visited[v] = 1; //为顶点v打上访问标记
//    printf("%d ", v);                       
//    EnQueue(&q, v);                        
//    while (!EmptyQueue(&q)) 
//    {
//        Front(&q, &v);
//        DeQueue(&q);                       
//        for (w = g.arr[v]; w; w = w->nextArc) 
//        {  
//            if (!visited[w->adjVex]) 
//            {       
//                visited[w->adjVex] = 1;
//                printf("%d ", w->adjVex);
//                EnQueue(&q, w->adjVex);
//            }
//        }
//    }
//}
//
//void WidenDepth(LGraph g) //宽度优先遍历
//{
//    int i;
//    int* visited = (int*)malloc(g.NodeNum * sizeof(int));  
//    for (i = 0; i < g.NodeNum; i++)                       
//        visited[i] = 0;
//    for (i = 0; i < g.NodeNum; i++) 
//    {                       
//        if (!visited[i]) 
//            WidenFind(i, visited, g);
//    }
//    free(visited);
//}
//int main() 
//{
//    LGraph g;
//    int i, u, v, enode, edge;
//    int w;
//    printf("请输入顶点个数:");
//    scanf("%d", &enode);
//    InitGraph(&g, enode);
//    printf("请输入边的个数:");
//    scanf("%d", &edge);
//    for (i = 0; i < edge; i++) 
//    {
//        printf("请输入边的左右顶点和对应权值:");
//        scanf("%d%d%d", &u, &v, &w);
//        InsertArr(&g, u, v, w);
//    }
//    printf("深度优先遍历:\n");
//    DepthSearch(g);
//    printf("\n");
//    printf("宽度优先遍历:\n");
//    WidenDepth(g);
//    return 0;
//}