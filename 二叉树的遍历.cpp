//#include <iostream>
//#include <cmath>
//#include <queue>
//#include <stack>
//using namespace std;
//const int OK = 1;
//const int ERROR = 0;
//class BinaryTree
//{
//public:
//    char data;
//    BinaryTree* LChild;
//    BinaryTree* RChild;
//};
//typedef BinaryTree BiNode;
//typedef BinaryTree* BiTree;
//typedef int Status;
//Status InitTree(BiTree* T)//初始化二叉树
//{
//    *T = NULL;
//    return OK;
//}
//Status EmptyTree(BiTree T)//判断树是否为空
//{
//    if (T == NULL)
//        return OK;
//    else return ERROR;
//}
//Status TreeDepth(BiTree T)//计算树的深度(递归)
//{
//    int LeftChild, RightChild;
//    if (T == NULL)
//        return 0;
//    else
//    {
//        if (T->LChild)
//            LeftChild = TreeDepth(T->LChild);
//        else LeftChild = 0;
//        if (T->RChild)
//            RightChild = TreeDepth(T->RChild);
//        else RightChild = 0;
//        return LeftChild > RightChild ? LeftChild + 1 : RightChild + 1;
//    }
//}
//int TreeDepth2(BiTree T)//计算树的深度(非递归)
//{
//    queue<BiTree>q;
//    if (T != NULL)
//        q.push(T);
//    int depth = 0;
//    while (!q.empty())
//    {
//        depth++;
//        for (int i = q.size(); i > 0; i--)
//        {
//            BiTree p = q.front();
//            q.pop();
//            if (p->LChild != NULL)
//                q.push(p->LChild);
//            if (p->RChild != NULL)
//                q.push(p->RChild);
//        }
//    }
//    return depth;
//}
//Status CreateTree(BiTree* T)//前序创建树并赋值
//{
//    char ch;
//    cin >> ch;
//    if (ch == '#')
//        *T = NULL;
//    else
//    {
//        *T = new BiNode;
//        if (!*T)
//            exit(OVERFLOW);
//        (*T)->data = ch;
//        CreateTree(&(*T)->LChild);
//        CreateTree(&(*T)->RChild);
//    }
//    return OK;
//}
//void ClearTree(BiTree* T)//清空树
//{
//    if ((*T)->LChild)
//        ClearTree(&(*T)->LChild);
//    if ((*T)->RChild)
//        ClearTree(&(*T)->RChild);
//    free((*T));
//    *T = NULL;
//}
//char Root(BiTree T)//返回根节点
//{
//    if (T)
//        return T->data;
//    else return ' ';
//}
//void PreFind(BiTree T)//前序遍历(递归)
//{
//    if (T == NULL)
//        return;
//    cout << T->data;
//    PreFind(T->LChild);
//    PreFind(T->RChild);
//}
//void MidFind(BiTree T)//中序遍历(递归)
//{
//    if (T == NULL)
//        return;
//    MidFind(T->LChild);
//    cout << T->data;
//    MidFind(T->RChild);
//}
//void BackFind(BiTree T)//后序遍历(递归)
//{
//    if (T == NULL)
//        return;
//    BackFind(T->LChild);
//    BackFind(T->RChild);
//    cout << T->data;
//}
//void LayerFind(BiTree T)//层序遍历
//{
//    queue<BiTree>q;
//    if (T != NULL)
//        q.push(T);
//    while (!q.empty())
//    {
//        BiTree p = q.front();
//        q.pop();
//        cout << p->data;
//        if (p->LChild != NULL)
//            q.push(p->LChild);
//        if (p->RChild != NULL)
//            q.push(p->RChild);
//    }
//}
//void PreResearch(BiTree T)//前序遍历(非递归)
//{
//    stack<BiTree> st;
//    if (T != NULL)
//        st.push(T);
//    while (!st.empty())
//    {
//        BiTree node = st.top();
//        if (node != NULL)
//        {
//            st.pop();
//            if (node->RChild)
//                st.push(node->RChild); // 右
//            if (node->LChild)
//                st.push(node->LChild); // 左
//            st.push(node);             // 根
//            st.push(NULL);
//        }
//        else
//        {
//            st.pop();
//            node = st.top();
//            st.pop();
//            cout << node->data;
//        }
//    }
//}
//void MidResearch(BiTree T)//中序遍历(非递归)
//{//入栈和出栈的顺序相反，左根右->右根左
//    stack<BiTree> st;
//    if (T != NULL)
//        st.push(T);
//    while (!st.empty())
//    {
//        BiTree node = st.top();
//        if (node != NULL)
//        {
//            st.pop();//将该节点弹出，避免重复操作，下面再将右根左节点添加到栈中
//            if (node->RChild)
//                st.push(node->RChild);//添加右节点（空节点不入栈）
//            st.push(node);//添加根节点
//            st.push(NULL);//根节点访问过，但是还没有处理，加入空节点做为标记。
//            if (node->LChild)
//                st.push(node->LChild);//添加左节点（空节点不入栈）
//        }
//        else
//        { // 只有遇到空节点的时候，才将下一个节点放进结果集
//            st.pop();//将空节点弹出
//            node = st.top();//重新取出栈中元素
//            st.pop();
//            cout << node->data; //加入到结果集
//        }
//    }
//}
//void BackResearch(BiTree T)//后序遍历(非递归)
//{
//    stack<BiTree> st;
//    if (T != NULL)
//        st.push(T);
//    while (!st.empty())
//    {
//        BiTree node = st.top();
//        if (node != NULL)
//        {
//            st.pop();
//            st.push(node); // 根
//            st.push(NULL);
//            if (node->RChild)
//                st.push(node->RChild);// 右
//            if (node->LChild)
//                st.push(node->LChild);// 左
//
//        }
//        else
//        {
//            st.pop();
//            node = st.top();
//            st.pop();
//            cout << node->data;
//        }
//    }
//}
//int SpotNum(BiTree T)//计算二叉树的结点数
//{
//    if (T == NULL)
//        return 0;
//    else
//        return SpotNum(T->LChild) + SpotNum(T->RChild) + 1;
//}
//int LeafSpotNum(BiTree T)//计算二叉树叶结点数
//{
//    if (T == NULL)
//        return 0;
//    else
//    {
//        if (T->LChild == NULL && T->RChild == NULL)
//            return 1;
//        else
//            return LeafSpotNum(T->LChild) + LeafSpotNum(T->RChild);
//    }
//}
//void exchange(BiTree T)//交换二叉树的左右子树
//{
//    if (T == NULL)
//        return;
//    exchange(T->LChild);
//    exchange(T->RChild);
//    BiTree p = T->LChild;
//    T->LChild = T->RChild;
//    T->RChild = p;
//}
//int main()
//{
//    BiTree T;
//    int n,m;
//    char e;
//    InitTree(&T);
//    if (EmptyTree(T))
//        cout << "初始化后，树的深度为：" << TreeDepth(T) << endl;
//    cout << "请输入字符：";//ABC#DE##G##F###
//    CreateTree(&T);
//    n = SpotNum(T);
//    cout << "该二叉树的结点数：" << n << endl;
//    m = LeafSpotNum(T);
//    cout << "该二叉树的叶结点数：" << m << endl;
//    if (!EmptyTree(T))
//        cout << "赋值后，树的深度为：" << TreeDepth2(T) << endl;
//    e = Root(T);
//    cout << "左右子树交换前，根节点为" << e << endl;
//    cout << "左右子树交换前，前序遍历(递归)：";
//    PreFind(T);
//    cout << endl;
//    cout << "左右子树交换前，中序遍历(递归)：";
//    MidFind(T);
//    cout << endl;
//    cout << "左右子树交换前，后序遍历(递归)：";
//    BackFind(T);
//    cout << endl;
//    cout << "左右子树交换前，层序遍历：";
//    LayerFind(T);
//    cout << endl;
//    cout << "左右子树交换前，前序遍历(非递归)：";
//    PreResearch(T);
//    cout << endl;
//    cout << "左右子树交换前，中序遍历(非递归)：";
//    MidResearch(T);
//    cout << endl;
//    cout << "左右子树交换前，后序遍历(非递归)：";
//    BackResearch(T);
//    cout << endl;
//    cout << endl;
//    exchange(T);
//    cout << "左右子树交换后，根节点为" << e << endl;
//    cout << "左右子树交换后，前序遍历(递归)：";
//    PreFind(T);
//    cout << endl;
//    cout << "左右子树交换后，中序遍历(递归)：";
//    MidFind(T);
//    cout << endl;
//    cout << "左右子树交换后，后序遍历(递归)：";
//    BackFind(T);
//    cout << endl;
//    cout << "左右子树交换后，层序遍历：";
//    LayerFind(T);
//    cout << endl;
//    cout << "左右子树交换后，前序遍历(非递归)：";
//    PreResearch(T);
//    cout << endl;
//    cout << "左右子树交换后，中序遍历(非递归)：";
//    MidResearch(T);
//    cout << endl;
//    cout << "左右子树交换前，后序遍历(非递归)：";
//    BackResearch(T);
//    cout << endl;
//    if (!EmptyTree(T))
//        cout << "遍历后，树的深度为：" << TreeDepth2(T) << endl;
//    ClearTree(&T);
//    if (EmptyTree(T))
//        cout << "清空后，树的深度为：" << TreeDepth(T) << endl;
//    return 0
#include <iostream>
using namespace std;
int* SearchMaxAndMin(int left, int right, int* a)
{
    int max = 0, min = 0;
    int* result=new int;
    if (left == right)
    {
        max = a[left];
        result[0] = max;
        min = a[left];
        result[1] = min;
    }
    if (abs(left - right) <= 1)
    {
        if (a[left] <= a[right])
        {
            max = a[right];
            result[0] = max;
            min = a[left];
            result[1] = min;
        }
        else
        {
            max = a[left];
            result[0] = max;
            min = a[right];
            result[1] = min;
        }
    }
    else
    {
        int mid = left + (right - left) / 2;
        int* result1 = SearchMaxAndMin(0, mid, a);
        int* result2 = SearchMaxAndMin(mid + 1, right, a);
        int LMax = result1[0];
        int LMin = result1[1];
        int RMax = result2[0];
        int RMin = result2[1];
        if (LMax < RMax)
        {
            max = RMax;
            result[0] = max;
        }
        else
        {
            max = LMax;
            result[0] = max;
        }
        if (LMin < RMin)
        {
            min = LMin;
            result[1] = min;
        }
        else
        {
            min = RMin;
            result[1] = min;
        }
    }
    return result;
}
int main()
{
    int a[5] = { 34, 54, 12, 65, 21 };
    int* b = SearchMaxAndMin(0, 4, a);
    cout << "最大值：" << *b << " "
        << "最小值：" << *(b + 1);
    return 0;
}