//#include <iostream>//clion能运行，vs不能运行
//using namespace std;
//const int maxsize = 10;
//const int OK = 1;
//const int False = 0;
//typedef struct VGraph
//{
//    char vex[maxsize];//顶点的集合
//    int arr[maxsize][maxsize];//邻接矩阵
//    int *visited; //标注已经访问的结点，其大小等于结点数,其实是一个数组，只是写成指针形式，便于操作
//    int NumNode;//记录图中结点的数目
//    int NumEdge;//记录图中边的数目
//}VGraph;
//typedef struct Queue
//{
//    int* data;//数组，存储元素
//    int front;//前端
//    int rear;//后端
//}Queue;
//void InitQueue(Queue* q)//初始化队列
//{
//    q->front = 0;
//    q->rear = 0;
//}
//int EmptyQueue(Queue q)//判断队列是否为空
//{
//    if (q.front == q.rear)
//        return OK;
//    else return False;
//}
//int InsertQueue(Queue* q, int e)//插入操作
//{
//    if ((q->rear + 1) % maxsize == q->front)
//        return False;
//    else
//    {
//        q->data[q->rear] = e;
//        q->rear = (q->rear + 1) % maxsize;
//    }
//    return OK;
//}
//int DeleteQueue(Queue* q, int* e)//删除操作
//{
//    if (q->rear == q->front)
//        return False;
//    else
//    {
//        *e = q->data[q->front];
//        q->front = (q->front + 1) % maxsize;
//    }
//    return OK;
//}
//void CreateGraph(VGraph* p)//创建邻接矩阵
//{
//    int i, j, k;
//    cout << "输入结点数和边数：";//4 5
//    cin >> p->NumNode >> p->NumEdge;
//    cout << "请输入结点：";
//    for (i = 0; i < p->NumNode; i++)
//        cin >> p->vex[i];//ABCD
//    for (i = 0; i < p->NumNode; i++)
//    {
//        for (j = 0; j < p->NumNode; j++)
//            p->arr[i][j] = 0;//初始化邻接矩阵
//    }
//    for (k = 0; k < p->NumEdge; k++)
//    {
//        cout << "输入邻接边(Vi,Vj)的两个结点：" << endl;
//        cin >> i >> j;//01 02 03 13 23
//        p->arr[i][j] = 1;
//    }
//    for (i = 0; i < p->NumNode; i++)
//    {
//        for (j = i; j < p->NumNode; j++)
//            p->arr[j][i] = p->arr[i][j];//无向图的邻接矩阵关于主对角线对称
//    }
//    cout << "邻接矩阵为：" << endl;
//    for (i = 0; i < p->NumNode; i++)
//    {
//        for (j = 0; j < p->NumNode; j++)
//            cout << p->arr[i][j] << " ";
//        cout << endl;
//    }
//}
//void DepthFind(VGraph p, int i)//深度优先遍历算法
//{
//    int j;
//    p.visited[i] = 1;//访问该节点设为1
//    cout << p.vex[i] << " ";
//    for (j = 0; j < p.NumNode; j++)
//    {
//        if (p.arr[i][j] == 1 && p.visited[j] == 0)
//            DepthFind(p, j);
//    }
//}
//void DepthSearch(VGraph p)//深度优先遍历
//{
//    int i;
//    for (i = 0; i < p.NumNode; i++)
//        p.visited[i] = 0;//将未访问的结点设为0
//    for (i = 0; i < p.NumNode; i++)
//    {
//        if (p.visited[i] == 0)
//            DepthFind(p, i);
//    }
//}
//void WidenSearch(VGraph p)//广度优先遍历
//{
//    Queue q;
//    InitQueue(&q);//初始化队列
//    int i, j;
//    for (i = 0; i < p.NumNode; i++)
//        p.visited[i] = 0;//未处理的结点记作0
//    for (i = 0; i < p.NumNode; i++)
//    {
//        if (p.visited[i] == 0)//如果该节点未访问，则访问该节点
//        {
//            p.visited[i] = 1;//已经访问了该节点
//            cout << p.vex[i] << " ";
//            InsertQueue(&q, i);
//            while (EmptyQueue(q) == 0)
//            {
//                DeleteQueue(&q, &i);
//                for (j = 0; j < p.NumNode; j++)
//                {
//                    if (p.arr[i][j] == 1 && p.visited[j] == 0)
//                    {//判断该节点的其他结点，即邻接矩阵的行，如果该节点存在，且未访问过
//                        p.visited[j] = 1;//则访问该节点
//                        cout << p.vex[j] << " ";
//                        InsertQueue(&q, j);
//                    }
//                }
//            }
//        }
//    }
//}
//int main()
//{
//    VGraph p;
//    CreateGraph(&p);
//    cout << "邻接矩阵的深度优先遍历：";
//    DepthSearch(p);
//    cout << endl;
//    cout << "邻接矩阵的广度优先遍历：";
//    WidenSearch(p);
//    return 0;
//}