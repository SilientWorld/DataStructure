//#include <stdio.h>
//#include <stdlib.h>
////定义结点结构
//typedef struct Node
//{
//    char data;
//    int Ltag, Rtag;//Ltag/Rtag=0表示有左右孩子，Ltag/Rtag=1表示有前驱后继
//    struct Node* LChild;//左孩子
//    struct Node* RChild;//右孩子
//}BiTreeNode, * BiThrTree;
//void Establish(BiThrTree* root)//建立二叉链表
//{
//    char demo;
//    demo = getchar();
//    if (demo == '#')
//        *root = NULL;
//    else
//    {
//        *root = (BiThrTree)malloc(sizeof(BiTreeNode));
//        if (*root == NULL)
//            return;
//        (*root)->data = demo;
//        (*root)->Ltag = 0;
//        (*root)->Rtag = 0;
//        Establish(&((*root)->LChild));
//        Establish(&((*root)->RChild));
//    }
//}
////线索化，建立线索链表
//void Inthread(BiThrTree* root)
//{
//    static BiThrTree pre = NULL;//在递归调用中，初始化pre，
//    // 且保存每次pre的信息，用static静态局部变量解决
//    if ((*root) != NULL)
//    {
//        Inthread(&((*root)->LChild));
//        if ((*root)->LChild == NULL)
//        {
//            (*root)->LChild = pre;
//            (*root)->Ltag = 1;
//        }
//        if (pre != NULL && pre->RChild == NULL)
//        {
//            pre->RChild = (*root);
//            pre->Rtag = 1;
//        }
//        pre = (*root);
//        Inthread(&((*root)->RChild));
//    }
//}
////查找遍历的首结点
//BiThrTree InFirst(BiThrTree root)
//{
//    BiThrTree p = root;
//    if (p == NULL)
//        return NULL;
//    while (p->Ltag == 0)
//        p = p->LChild;
//    return p;
//}
////查找遍历过程中结点的直接后继
//BiThrTree InNext(BiThrTree p)
//{
//    BiThrTree next = NULL;
//    if (p->Rtag == 1)
//        next = p->RChild;
//    else
//    {
//        next = p->RChild;
//        while (next != NULL && next->Ltag == 0) //next!=NULL,解决局部变量next为空指针时，不能访问data等数据
//            next = next->LChild;
//    }
//    return next;
//}
////中序遍历线索二叉树
//void TinOrder(BiThrTree root)
//{
//    BiThrTree p;
//    if (root == NULL)
//        return;
//    p = InFirst(root);
//    while (p != NULL)
//    {
//        printf("%c ", p->data);
//        p = InNext(p);
//    }
//}
//int main()
//{
//    BiThrTree root;
//    printf("------根据二叉链表的格式输入结点数据------\n");
//    Establish(&root);
//    Inthread(&root);
//    printf("-------遍历打印线索二叉树-------\n");
//    TinOrder(root);
//    return 0;
//}