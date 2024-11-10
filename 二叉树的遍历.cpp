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
//Status InitTree(BiTree* T)//��ʼ��������
//{
//    *T = NULL;
//    return OK;
//}
//Status EmptyTree(BiTree T)//�ж����Ƿ�Ϊ��
//{
//    if (T == NULL)
//        return OK;
//    else return ERROR;
//}
//Status TreeDepth(BiTree T)//�����������(�ݹ�)
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
//int TreeDepth2(BiTree T)//�����������(�ǵݹ�)
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
//Status CreateTree(BiTree* T)//ǰ�򴴽�������ֵ
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
//void ClearTree(BiTree* T)//�����
//{
//    if ((*T)->LChild)
//        ClearTree(&(*T)->LChild);
//    if ((*T)->RChild)
//        ClearTree(&(*T)->RChild);
//    free((*T));
//    *T = NULL;
//}
//char Root(BiTree T)//���ظ��ڵ�
//{
//    if (T)
//        return T->data;
//    else return ' ';
//}
//void PreFind(BiTree T)//ǰ�����(�ݹ�)
//{
//    if (T == NULL)
//        return;
//    cout << T->data;
//    PreFind(T->LChild);
//    PreFind(T->RChild);
//}
//void MidFind(BiTree T)//�������(�ݹ�)
//{
//    if (T == NULL)
//        return;
//    MidFind(T->LChild);
//    cout << T->data;
//    MidFind(T->RChild);
//}
//void BackFind(BiTree T)//�������(�ݹ�)
//{
//    if (T == NULL)
//        return;
//    BackFind(T->LChild);
//    BackFind(T->RChild);
//    cout << T->data;
//}
//void LayerFind(BiTree T)//�������
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
//void PreResearch(BiTree T)//ǰ�����(�ǵݹ�)
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
//                st.push(node->RChild); // ��
//            if (node->LChild)
//                st.push(node->LChild); // ��
//            st.push(node);             // ��
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
//void MidResearch(BiTree T)//�������(�ǵݹ�)
//{//��ջ�ͳ�ջ��˳���෴�������->�Ҹ���
//    stack<BiTree> st;
//    if (T != NULL)
//        st.push(T);
//    while (!st.empty())
//    {
//        BiTree node = st.top();
//        if (node != NULL)
//        {
//            st.pop();//���ýڵ㵯���������ظ������������ٽ��Ҹ���ڵ���ӵ�ջ��
//            if (node->RChild)
//                st.push(node->RChild);//����ҽڵ㣨�սڵ㲻��ջ��
//            st.push(node);//��Ӹ��ڵ�
//            st.push(NULL);//���ڵ���ʹ������ǻ�û�д�������սڵ���Ϊ��ǡ�
//            if (node->LChild)
//                st.push(node->LChild);//�����ڵ㣨�սڵ㲻��ջ��
//        }
//        else
//        { // ֻ�������սڵ��ʱ�򣬲Ž���һ���ڵ�Ž������
//            st.pop();//���սڵ㵯��
//            node = st.top();//����ȡ��ջ��Ԫ��
//            st.pop();
//            cout << node->data; //���뵽�����
//        }
//    }
//}
//void BackResearch(BiTree T)//�������(�ǵݹ�)
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
//            st.push(node); // ��
//            st.push(NULL);
//            if (node->RChild)
//                st.push(node->RChild);// ��
//            if (node->LChild)
//                st.push(node->LChild);// ��
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
//int SpotNum(BiTree T)//����������Ľ����
//{
//    if (T == NULL)
//        return 0;
//    else
//        return SpotNum(T->LChild) + SpotNum(T->RChild) + 1;
//}
//int LeafSpotNum(BiTree T)//���������Ҷ�����
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
//void exchange(BiTree T)//��������������������
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
//        cout << "��ʼ�����������Ϊ��" << TreeDepth(T) << endl;
//    cout << "�������ַ���";//ABC#DE##G##F###
//    CreateTree(&T);
//    n = SpotNum(T);
//    cout << "�ö������Ľ������" << n << endl;
//    m = LeafSpotNum(T);
//    cout << "�ö�������Ҷ�������" << m << endl;
//    if (!EmptyTree(T))
//        cout << "��ֵ���������Ϊ��" << TreeDepth2(T) << endl;
//    e = Root(T);
//    cout << "������������ǰ�����ڵ�Ϊ" << e << endl;
//    cout << "������������ǰ��ǰ�����(�ݹ�)��";
//    PreFind(T);
//    cout << endl;
//    cout << "������������ǰ���������(�ݹ�)��";
//    MidFind(T);
//    cout << endl;
//    cout << "������������ǰ���������(�ݹ�)��";
//    BackFind(T);
//    cout << endl;
//    cout << "������������ǰ�����������";
//    LayerFind(T);
//    cout << endl;
//    cout << "������������ǰ��ǰ�����(�ǵݹ�)��";
//    PreResearch(T);
//    cout << endl;
//    cout << "������������ǰ���������(�ǵݹ�)��";
//    MidResearch(T);
//    cout << endl;
//    cout << "������������ǰ���������(�ǵݹ�)��";
//    BackResearch(T);
//    cout << endl;
//    cout << endl;
//    exchange(T);
//    cout << "�������������󣬸��ڵ�Ϊ" << e << endl;
//    cout << "��������������ǰ�����(�ݹ�)��";
//    PreFind(T);
//    cout << endl;
//    cout << "���������������������(�ݹ�)��";
//    MidFind(T);
//    cout << endl;
//    cout << "�������������󣬺������(�ݹ�)��";
//    BackFind(T);
//    cout << endl;
//    cout << "�������������󣬲��������";
//    LayerFind(T);
//    cout << endl;
//    cout << "��������������ǰ�����(�ǵݹ�)��";
//    PreResearch(T);
//    cout << endl;
//    cout << "���������������������(�ǵݹ�)��";
//    MidResearch(T);
//    cout << endl;
//    cout << "������������ǰ���������(�ǵݹ�)��";
//    BackResearch(T);
//    cout << endl;
//    if (!EmptyTree(T))
//        cout << "�������������Ϊ��" << TreeDepth2(T) << endl;
//    ClearTree(&T);
//    if (EmptyTree(T))
//        cout << "��պ��������Ϊ��" << TreeDepth(T) << endl;
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
    cout << "���ֵ��" << *b << " "
        << "��Сֵ��" << *(b + 1);
    return 0;
}