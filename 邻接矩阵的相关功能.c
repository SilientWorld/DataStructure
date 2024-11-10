//#include <stdio.h>
//#include <stdlib.h>
//#define OK 1
//#define false 0
//typedef struct VGraph
//{
//    int NumNode;//点数
//    int NumEdge;//边数
//    int weigh;//权重
//    int** arr;//邻接矩阵
//}VGraph;
//void InitArr(VGraph* p, int NumNodes, int weight)//初始化
//{
//    int i, j;
//    p->NumNode = NumNodes;
//    p->weigh = weight;
//    p->NumEdge = 0;
//    p->arr = (int**)malloc(sizeof(int*) * NumNodes);
//    for (i = 0; i < p->NumNode; i++)
//    {
//        p->arr[i] = (int*)malloc(sizeof(int) * NumNodes);
//        for (j = 0; j < p->NumNode; j++)
//        {
//            p->arr[i][j] = p->weigh;
//            p->arr[i][i] = 0;
//        }
//    }
//}
//void DestroyArr(VGraph* p)//撤销数组
//{
//    for (int i = 0; i < p->NumNode; i++)
//        free(p->arr[i]);
//    free(p->arr);
//}
//int InsertArr(VGraph* p, int i, int j, int w)//插入边的元素
//{
//    if (i<0 || j<0 || i>p->NumNode || j>p->NumNode || i == j)
//        return false;
//    if (p->arr[i][j] != p->weigh)//插入的边已经存在
//        return false;
//    p->arr[i][j] = w;
//    p->NumEdge++;
//    return OK;
//}
//int FindArr(VGraph p, int i, int j)//查找功能
//{
//    if (p.arr[i][j] == 0)
//        return false;
//    return OK;
//}
//int DeleteArr(VGraph* p, int i, int j)//删除边的元素
//{
//    if (i<0 || j<0 || i>p->NumNode || j>p->NumNode || i == j)
//        return false;
//    if (p->arr[i][j] == p->weigh)//删除的边不存在
//        return false;
//    p->arr[i][j] = 0;
//    p->NumEdge--;
//    return OK;
//}
//void show(VGraph p)
//{
//    int i, j;
//    printf("邻接矩阵：\n");
//    for (i = 0; i < p.NumNode; i++)
//    {
//        for (j = 0; j < p.NumNode; j++)
//            printf("%d  ", p.arr[i][j]);
//        printf("\n");
//    }
//}
//int main()
//{
//    int i, j, k = 10;
//    VGraph p;
//    InitArr(&p, 4, 0);//4个结点，0权值
//    InsertArr(&p, 1, 2, 3);
//    InsertArr(&p, 2, 3, 4);
//    InsertArr(&p, 3, 2, 5);
//    InsertArr(&p, 2, 1, 1);
//    InsertArr(&p, 3, 1, 5);
//    InsertArr(&p, 1, 4, 2);
//    InsertArr(&p, 1, 0, 3);
//    InsertArr(&p, 0, 1, 6);
//    show(p);
//    if (FindArr(p, 1, 2) == 1)
//        printf("已找到（1，2）元素！\n");
//    else printf("未找到（1，2）元素！\n");
//    DeleteArr(&p, 2, 3);
//    if (FindArr(p, 2, 3) == 1)
//        printf("已找到（2，3）元素！\n");
//    if (FindArr(p, 2, 3) == 0)
//        printf("未找到（2，3）元素！\n");
//    DestroyArr(&p);
//    return 0;
//}