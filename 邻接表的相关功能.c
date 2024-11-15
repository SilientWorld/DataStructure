//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include <windows.h>
//#define ERROR 0
//#define OK 1
//#define Overflow 2     //表示上溢
//#define Underflow 3    //表示下溢
//#define NotPresent 4   //表示元素不存在
//#define Duplicate 5    //表示有重复元素
//typedef int ElemType;
//typedef int Status;
//
//
////邻接表的结构体定义
//typedef struct ENode 
//{
//    int adjVex;             //任意顶点u相邻的顶点
//    ElemType w;             //边的权值
//    struct ENode* nextArc;  //指向下一个边结点
//}ENode;
//
//typedef struct 
//{
//    int n;             //图的当前顶点数
//    int e;             //图的当前边数
//    ENode** a;         //指向一维指针数组
//}LGraph;
//
//
////邻接表的初始化
//Status Init(LGraph* lg, int nSize) 
//{
//    int  i;
//    lg->n = nSize;
//    lg->e = 0;
//    lg->a = (ENode**)malloc(nSize * sizeof(ENode*));  //动态生成长度为n的一维指针数组
//    if (!lg->a) return ERROR;
//    else 
//    {
//        for (i = 0; i < lg->n; i++) 
//        {
//            lg->a[i] = NULL;                        //将指针数组a置空
//        }
//        return OK;
//    }
//}
//
//
////邻接表的撤销(改成了int型，有返回值)
//int Destory(LGraph* lg) 
//{
//    int i;
//    ENode* p, * q;
//    for (i = 0; i < lg->n; i++) 
//    {
//        p = lg->a[i];                 //指针p指向顶点i的单链表的第一个边结点
//        q = p;
//        while (p) 
//        {                     //释放顶点i的单链表中所有边结点
//            p = p->nextArc;
//            free(q);
//            q = p;
//        }
//    }
//    free(lg->a);                     //释放一维指针数组a的存储空间
//    return 1;                        //改为int型函数,有返回值
//}
//
//
////邻接表的搜索边
//Status Exist(LGraph* lg, int u, int v)
//{
//    ENode* p;
//    if (u < 0 || v < 0 || u > lg->n - 1 || v > lg->n - 1 || u == v) return ERROR;
//    p = lg->a[u];                   //指针p指向顶点u的单链表的第一个边结点
//    while (p != NULL && p->adjVex != v) 
//        p = p->nextArc;
//    if (!p) 
//        return ERROR;            //若未找到此边,则返回ERROR
//    else return OK;
//}
//
//
////邻接表的插入边
//Status Insert(LGraph* lg, int u, int v, ElemType w) 
//{
//    ENode* p;
//    if (u < 0 || v < 0 || u > lg->n - 1 || v > lg->n - 1 || u == v) 
//        return ERROR;
//    if (Exist(lg, u, v)) 
//        return Duplicate;  //此边已存在,返回错误
//    p = (ENode*)malloc(sizeof(ENode));   //为新的边结点分配存储空间
//    p->adjVex = v;
//    p->w = w;
//    p->nextArc = lg->a[u];             //将新的边结点插入单链表的最前面
//    lg->a[u] = p;
//    lg->e++;                            //边加1
//    return OK;
//}
//
//
////邻接表的删除边
//Status Remove(LGraph* lg, int u, int v) 
//{
//    ENode* p, * q;
//    if (u < 0 || v < 0 || u > lg->n - 1 || v > lg->n - 1 || u == v) 
//        return ERROR;
//    p = lg->a[u];
//    q = NULL;
//    while (p && p->adjVex != v) 
//    {         //查找待删除边是否存在
//        q = p;
//        p = p->nextArc;
//    }
//    if (!p) 
//        return NotPresent;          //p为空,待删除边不存在
//    if (q)
//        q->nextArc = p->nextArc;     //从单链表删除此边
//    else lg->a[u] = p->nextArc;
//    free(p);
//    lg->e--;
//    return OK;
//}
//
//
//
//int main() 
//{
//    LGraph g;
//    int i, u, v, enode, edge;
//    ElemType w;
//    printf("请输入顶点个数:");
//    scanf("%d", &enode);
//    Init(&g, enode);
//    printf("请输入边的个数:");
//    scanf("%d", &edge);
//    for (i = 0; i < edge; i++) 
//    {
//        printf("请输入边的左右顶点和对应权值:");
//        scanf("%d%d%d", &u, &v, &w);
//        Insert(&g, u, v, w);
//    }
//    printf("\n请输入想要删除的左顶点:");
//    scanf("%d", &u);
//    printf("请输入想要删除的右顶点:");
//    scanf("%d", &v);
//    printf("查找想要删除的边:");
//    if (Exist(&g, u, v)) 
//        printf("已找到！");
//    else printf("未找到！");
//    printf("\n删除该条边:");
//    if (Remove(&g, u, v)) 
//        printf("已删除！");
//    else printf("未删除！");
//    printf("\n销毁邻接表:");
//    if (Destory(&g)) 
//        printf("已销毁！");
//    else printf("未销毁！");
//    return 0;
//}
//
