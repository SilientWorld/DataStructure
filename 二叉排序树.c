//#include <stdio.h>
//#include <stdlib.h>
//#define TRUE 1
//#define FALSE 0
//typedef struct BinaryTree
//{
//    int data;
//    struct BinaryTree* LChild;
//    struct BinaryTree* RChild;
//}BiNode, * BiTree;
//typedef int Status;
//Status SearchTree(BiTree T, int key, BiTree f, BiTree* p)
//{
//    if (T == NULL)
//    {
//        *p = f;/* 指针f指向T的双亲，其初始调用值为NULL */
//        return FALSE;/* 否则指针p指向查找路径上访问的最后一个结点并返回FALSE */
//    }
//    else if (key == T->data)/*若查找成功，则指针p指向该数据元素结点，并返回TRUE */
//    {
//        *p = T;
//        return TRUE;
//    }
//    else if (key < T->data)/* 递归查找二叉排序树T中是否存在key, */
//        return SearchTree(T->LChild, key, T, p);
//    else if (key >= T->data)
//        return SearchTree(T->RChild, key, T, p);
//}
//Status InsertTree(BiTree* T, int key)//二叉排序树插入操作
//{/*  当二叉排序树T中不存在关键字等于key的数据元素时， */
///*  插入key并返回TRUE，否则返回FALSE */
//    BiTree p, s;
//    if (!SearchTree(*T, key, NULL, &p))
//    {
//        s = malloc(sizeof(BiNode));
//        s->data = key;
//        s->LChild = s->RChild = NULL;
//        if (p == NULL)
//            *T = s;
//        else if (key < p->data)
//            p->LChild = s;
//        else if (key > p->data)
//            p->RChild = s;
//        return TRUE;
//    }
//    else return FALSE;
//}
//Status Delete(BiTree* p)//删除操作
//{/* 从二叉排序树中删除结点p，并重接它的左或右子树。 */
//    BiTree q, s;
//    if ((*p)->LChild == NULL) /* 只需重接它的右子树 */
//    {
//        q = *p;
//        *p = (*p)->RChild;
//        free(q);
//    }
//    else if ((*p)->RChild == NULL)/* 右子树空则只需重接它的左子树（待删结点是叶子也走此分支) */
//    {
//        q = *p;
//        *p = (*p)->LChild;
//        free(q);
//    }
//    else if ((*p)->LChild != NULL && (*p)->RChild != NULL)/* 左右子树均不空 */
//    {
//        q = *p;
//        s = (*p)->LChild;
//        while (s->RChild != NULL)/* 转左，然后向右到尽头（找待删结点的前驱） */
//        {
//            q = s;
//            s = s->RChild;
//        }
//        (*p)->data = s->data; /*  s指向被删结点的直接前驱（将被删结点前驱的值取代被删结点的值） */
//        if (q != *p)
//            q->RChild = s->LChild;/*  重接q的右子树 */
//        else q->LChild = s->LChild;/*  重接q的左子树 */
//        free(s);
//    }
//    return TRUE;
//}
//Status SearchDeleteTree(BiTree* T, int key)
//{/* 若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素结点, */
//    if (*T == NULL)
//        return FALSE;
//    else
//    {
//        if (key < (*T)->data)
//            return SearchDeleteTree(&(*T)->LChild, key);
//        else if (key > (*T)->data)
//            return SearchDeleteTree(&(*T)->RChild, key);
//        else if (key == (*T)->data)
//            return Delete(T);
//    }
//}
//void MidSearch(BiTree T)//中序遍历，使其二叉排序树的输出是个有序数列
//{
//    if (T == NULL)
//        return;
//    else
//    {
//        MidSearch(T->LChild);
//        printf("%d ", T->data);
//        MidSearch(T->RChild);
//    }
//}
//int main()
//{
//    int i;
//    int a[10] = { 62,88,58,47,35,73,51,99,37,93 };
//    printf("插入前的数字排序：");
//    for (i = 0; i < 10; i++)
//        printf("%d ", a[i]);
//    printf("\n");
//    BiTree T = NULL;
//    for (i = 0; i < 10; i++)
//        InsertTree(&T, a[i]);
//    printf("插入后的数字排序为：");
//    MidSearch(T);
//    printf("\n");
//    SearchDeleteTree(&T, 93);
//    printf("删除93后的数字排序为：");
//    MidSearch(T);
//    printf("\n");
//    SearchDeleteTree(&T, 47);
//    printf("删除47后的数字排序为：");
//    MidSearch(T);
//    printf("\n");
//    return 0;
//}