////#define _CRT_SECURE_NO_WARNINGS
////#include <stdio.h>
////#define MaxNum 20
////#define EndNum 65535
////typedef struct
////{
////	int vex[MaxNum];
////	int arr[MaxNum][MaxNum];
////	int NumNode, NumEdge;
////}MGraph;
////typedef int MinArr[MaxNum];    /* 用于存储最短路径下标的数组 */
////typedef int WeighSum[MaxNum];/* 用于存储到各点最短路径的权值和 */
////
/////* 构件图 */
////void InitMgraph(MGraph* G)
////{
////	int i, j, k, w;
////	printf("请输入边数和顶点数:");
////	scanf("%d%d", &G->NumEdge, &G->NumNode);
////	//	G->NumEdge = 16;
////	//	G->NumNode = 9;
////	for (i = 0; i < G->NumNode; i++)/* 初始化图 */
////		G->vex[i] = i;
////	for (i = 0; i < G->NumNode; i++)/* 初始化图 */
////	{
////		for (j = 0; j < G->NumNode; j++)
////		{
////			if (i == j)
////				G->arr[i][j] = 0;
////			else
////				G->arr[i][j] = G->arr[j][i] = EndNum;
////		}
////	}
////
////	for (k = 0; k < G->NumEdge; k++)
////	{
////		printf("请输入路的起点，终点以及两点之间的距离：");
////		scanf("%d%d%d", &i, &j, &w);
////		G->arr[i][j] = 1;
////	}
////	//	G->arr[0][1] = 1;
////	//	G->arr[0][2] = 5;
////	//	G->arr[1][2] = 3;
////	//	G->arr[1][3] = 7;
////	//	G->arr[1][4] = 5;
////	//
////	//	G->arr[2][4] = 1;
////	//	G->arr[2][5] = 7;
////	//	G->arr[3][4] = 2;
////	//	G->arr[3][6] = 3;
////	//	G->arr[4][5] = 3;
////	//
////	//	G->arr[4][6] = 6;
////	//	G->arr[4][7] = 9;
////	//	G->arr[5][7] = 5;
////	//	G->arr[6][7] = 2;
////	//	G->arr[6][8] = 7;
////	//
////	//	G->arr[7][8] = 4;
////	for (i = 0; i < G->NumNode; i++)
////	{
////		for (j = i; j < G->NumNode; j++)
////		{
////			G->arr[j][i] = G->arr[i][j];
////		}
////	}
////
////}
////
/////*  Dijkstra算法，求有向网G的v0顶点到其余顶点v的最短路径P[v]及带权长度D[v] */
/////*  P[v]的值为前驱顶点下标,D[v]表示v0到v的最短路径长度和 */
////void ShortestPath(MGraph G, int v0, MinArr* P, WeighSum* D)
////{
////	int v, w, k, min;
////	int ShortestRoad[MaxNum];/* ShortestRoad[w]=1表示求得顶点v0至vw的最短路径 */
////	for (v = 0; v < G.NumNode; v++)    /* 初始化数据 */
////	{
////		ShortestRoad[v] = 0;			/* 全部顶点初始化为未知最短路径状态 */
////		(*D)[v] = G.arr[v0][v];/* 将与v0点有连线的顶点加上权值 */
////		(*P)[v] = -1;				/* 初始化路径数组P为-1  */
////	}
////
////	(*D)[v0] = 0;  /* v0至v0路径为0 */
////	ShortestRoad[v0] = 1;    /* v0至v0不需要求路径 */
////	/* 开始主循环，每次求得v0到某个v顶点的最短路径 */
////	for (v = 1; v < G.NumNode; v++)
////	{
////		min = EndNum;    /* 当前所知离v0顶点的最近距离 */
////		for (w = 0; w < G.NumNode; w++) /* 寻找离v0最近的顶点 */
////		{
////			if (!ShortestRoad[w] && (*D)[w] < min)
////			{
////				k = w;
////				min = (*D)[w];    /* w顶点离v0顶点更近 */
////			}
////		}
////		ShortestRoad[k] = 1;    /* 将目前找到的最近的顶点置为1 */
////		for (w = 0; w < G.NumNode; w++) /* 修正当前最短路径及距离 */
////		{
////			/* 如果经过v顶点的路径比现在这条路径的长度短的话 */
////			if (!ShortestRoad[w] && (min + G.arr[k][w] < (*D)[w]))
////			{ /*  说明找到了更短的路径，修改D[w]和P[w] */
////				(*D)[w] = min + G.arr[k][w];  /* 修改当前路径长度 */
////				(*P)[w] = k;
////			}
////		}
////	}
////}
////
////int main()
////{
////	int i, j, v0;
////	MGraph G;
////	MinArr P;
////	WeighSum D; /* 求某点到其余各点的最短路径 */
////	v0 = 0;
////	InitMgraph(&G);
////	ShortestPath(G, v0, &P, &D);
////	printf("最短路径倒序如下:\n");
////	for (i = 1; i < G.NumNode; ++i)
////	{
////		printf("v%d - v%d : ", v0, i);
////		j = i;
////		while (P[j] != -1)
////		{
////			printf("%d ", P[j]);
////			j = P[j];
////		}
////		printf("\n");
////	}
////	printf("\n源点到各顶点的最短路径长度为:\n");
////	for (i = 1; i < G.NumNode; ++i)
////		printf("v%d - v%d : %d \n", G.vex[0], G.vex[i], D[i]);
////	return 0;
////}
//
//#include <stdio.h>
//#define MaxNum 20
//#define EndNum 65535
//typedef struct
//{
//    int vex[MaxNum];
//    int arr[MaxNum][MaxNum];
//    int NumNode, NumEdge;
//}MainGraph;
//typedef int MinArr[MaxNum];    //用于存储最少换乘次数下标的数组 
//typedef int WeighNum[MaxNum]; //用于存储到各点最少换乘次数的权值和
//void InitGraph(MainGraph* G)//初始化图
//{
//    int i, j, k, w;
//    printf("请输入顶点数和边数:");
//    scanf("%d%d", &G->NumNode, &G->NumEdge);
//    for (i = 0; i < G->NumNode; i++)
//        G->vex[i] = i;
//    for (i = 0; i < G->NumNode; i++)
//    {
//        for (j = 0; j < G->NumNode; j++)
//        {
//            if (i == j)
//                G->arr[i][j] = 0;
//            else
//                G->arr[i][j] = G->arr[j][i] = EndNum;
//        }
//    }
//    for (k = 0; k < G->NumEdge; k++)
//    {
//        printf("请输入航班的两个站点以及两点之间的距离（均设为1）：");
//        scanf("%d%d%d", &i, &j, &w);
//        G->arr[i][j] = w;
//    }
//    for (i = 0; i < G->NumNode; i++)
//    {
//        for (j = i; j < G->NumNode; j++)
//        {
//            G->arr[j][i] = G->arr[i][j];
//        }
//    }
//
//}
//void LeastTimes(MainGraph G, int v0, MinArr* t, WeighNum* Dot)
//{
//    int v, w, k, min;
//    int ShortestTimes[MaxNum];
//    for (v = 0; v < G.NumNode; v++)    
//    {
//        ShortestTimes[v] = 0;			
//        (*Dot)[v] = G.arr[v0][v];
//        (*t)[v] = -1;	//初始化换乘次数的数组t为-1  
//    }
//
//    (*Dot)[v0] = 0;  
//    ShortestTimes[v0] = 1;   
//    for (v = 1; v < G.NumNode; v++)//求v0到某个v顶点的最少换乘次数 
//    {
//        min = EndNum;   
//        for (w = 0; w < G.NumNode; w++) 
//        {
//            if (!ShortestTimes[w] && (*Dot)[w] < min)
//            {
//                k = w;
//                min = (*Dot)[w];   
//            }
//        }
//        ShortestTimes[k] = 1;    //将目前找到的最近的顶点置为1
//        for (w = 0; w < G.NumNode; w++) 
//        {
//            if (!ShortestTimes[w] && (min + G.arr[k][w] < (*Dot)[w]))
//            { 
//                (*Dot)[w] = min + G.arr[k][w];  
//                (*t)[w] = k;
//            }
//        }
//    }
//}
//int main()
//{
//    int i, j, v0;
//    MainGraph G;
//    MinArr P;
//    WeighNum D; 
//    v0 = 0;
//    InitGraph(&G);
//    LeastTimes(G, v0, &P, &D);
//    printf("\n起点到各地点的最少换乘次数为:\n");
//    for (i = 1; i < G.NumNode; ++i)
//        printf("v%d - v%d : %d \n", G.vex[0], G.vex[i], D[i]);
//    return 0;
//}
