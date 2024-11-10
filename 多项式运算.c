//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct pNode
//{
//    int coef;
//    int exp;
//    struct pNode* link;
//} pNode;
//typedef struct
//{
//    struct pNode* head;
//} polynominal;
//typedef struct pNode
//{
//    int coef;//系数
//    int exp;//指数
//    struct pNode* next;
//}PNode, * Polynomial;
//Polynomial InitPoly()//初始化
//{
//    int coe, exp;
//    Polynomial head = NULL;//设置头结点
//    Polynomial tail = NULL;//设置尾结点，且两个结点都指向空
//    printf("请分别输入系数和指数：（输入0 0结束运行）\n");
//    while (scanf("%d%d", &coe, &exp) && coe != 0 && exp != 0 && exp > 0)
//    {
//        Polynomial p = malloc(sizeof(PNode));
//        p->coef = coe;
//        p->exp = exp;
//        p->next = NULL;
//        if (head == NULL) //如果头结点为空，将p结点插入头/尾结点中
//            head = tail = p;
//        else if (head != NULL)
//        {//如果头结点不为空，尾结点后移
//            tail->next = p;
//            tail = p;
//        }
//    }
//    return head;
//}
//void show(Polynomial p)//输出操作
//{
//    printf("F（x）=");
//    while (p)
//    {
//        printf("%dx^%d +", p->coef, p->exp);
//        p = p->next;
//    }
//    printf("0\n");
//}
//void DeletePoly(Polynomial* p)//销毁操作
//{
//    Polynomial q = malloc(sizeof(PNode));
//    while ((*p))
//    {
//        q = *p;
//        (*p) = (*p)->next;
//        free(q);
//    }
//}
//Polynomial AddPoly(Polynomial* poly1, Polynomial* poly2)//加法操作
//{
//    Polynomial p1, p2, sum = NULL, tail = NULL;
//    p1 = *poly1;
//    p2 = *poly2;
//    while (p1 && p2)
//    {
//        if (p1->exp < p2->exp)
//        {
//            Polynomial p = malloc(sizeof(PNode));
//            p->coef = p2->coef;
//            p->exp = p2->exp;
//            p->next = NULL;
//            if (sum == 0)
//                sum = tail = p;
//            else if (sum != 0)
//            {
//                tail->next = p;
//                tail = p;
//            }
//            p2 = p2->next;
//        }
//        else if (p1->exp > p2->exp)
//        {
//            Polynomial p = malloc(sizeof(PNode));
//            p->coef = p1->coef;
//            p->exp = p1->exp;
//            p->next = NULL;
//            if (sum == 0)
//                sum = tail = p;
//            else if (sum != 0)
//            {
//                tail->next = p;
//                tail = p;
//            }
//            p1 = p1->next;
//        }
//        else if (p1->exp == p2->exp)
//        {
//            Polynomial p = malloc(sizeof(PNode));
//            p->coef = p1->coef + p2->coef;
//            p->exp = p1->exp;
//            p->next = NULL;
//            if (sum == 0)
//                sum = tail = p;
//            else if (sum != 0) {
//                tail->next = p;
//                tail = p;
//            }
//            p1 = p1->next;
//            p2 = p2->next;
//        }
//    }
//    while (p1)//将p1剩余结点放到sum链表中
//    {
//        Polynomial p = malloc(sizeof(PNode));
//        p->coef = p1->coef;
//        p->exp = p1->exp;
//        p->next = NULL;
//        tail->next = p;
//        tail = p;
//        p1 = p1->next;
//    }
//    while (p2)//将p2剩余结点放到sum链表中
//    {
//        Polynomial p = malloc(sizeof(PNode));
//        p->coef = p2->coef;
//        p->exp = p2->exp;
//        p->next = NULL;
//        tail->next = p;
//        tail = p;
//        p2 = p2->next;
//    }
//    return sum;
//}
//Polynomial MultiplePoly(Polynomial* poly1, Polynomial* poly2)//乘法操作
//{
//    Polynomial p1, p2, muti = NULL, tail = NULL;
//    p1 = *poly1;
//    p2 = *poly2;
//    while (p1)
//    {
//        p2 = *poly2;
//        while (p2)
//        {
//            Polynomial p = malloc(sizeof(PNode));
//            p->coef = p1->coef * p2->coef;
//            p->exp = p1->exp + p2->exp;
//            p->next = NULL;
//            if (muti == 0)
//                muti = tail = p;
//            else if (muti != 0)
//            {
//                tail->next = p;
//                tail = p;
//            }
//            p2 = p2->next;
//        }
//        p1 = p1->next;
//    }
//    return muti;
//}
//int PolyLength(Polynomial poly)//返回链表长度，方便冒泡排序
//{
//    Polynomial p = poly;
//    int length = 0;
//    while (p)
//    {
//        p = p->next;
//        length++;
//    }
//    return length;
//}
//void BubbleSort(Polynomial* poly)//冒泡排序，降序排列
//{
//    Polynomial p1, p2;
//    struct pNode temp;
//    int i, j;
//    for (p1 = *poly, i = 0; i < PolyLength((*poly)) - 1; i++, p1 = p1->next)
//    {
//        for (p2 = p1->next, j = 0; j < PolyLength((*poly)) - i - 1; j++, p2 = p2->next)
//        {
//            if (p1->exp < p2->exp)
//            {//将系数和指数交换
//                temp.coef = p2->coef;
//                p2->coef = p1->coef;
//                p1->coef = temp.coef;
//                temp.exp = p2->exp;
//                p2->exp = p1->exp;
//                p1->exp = temp.exp;
//            }
//        }
//    }
//}
//int main()
//{
//    Polynomial p1, p2, ret, total;
//    int i;
//    p1 = InitPoly();
//    printf("降序前，第一个多项式为：");
//    show(p1);
//    BubbleSort(&p1);
//    printf("降序后，第一个多项式为：");
//    show(p1);
//    i = PolyLength(p1);
//    printf("p1的长度=%d\n", i);
//    p2 = InitPoly();
//    printf("降序前，第二个多项式为：");
//    show(p2);
//    BubbleSort(&p2);
//    printf("降序后，第二个多项式为：");
//    show(p2);
//    i = PolyLength(p2);
//    printf("p2的长度=%d\n", i);
//    ret = AddPoly(&p1, &p2);
//    printf("降序前，两个多项式之和=");
//    show(ret);
//    i = PolyLength(ret);
//    printf("ret的长度=%d\n", i);
//    total = MultiplePoly(&p1, &p2);
//    printf("降序前，两个多项式之积=");
//    show(total);
//    i = PolyLength(total);
//    printf("total的长度=%d\n", i);
//    DeletePoly(&p1);//撤销各个链表操作
//    DeletePoly(&p2);
//    DeletePoly(&ret);
//    DeletePoly(&total);
//    return 0;
//}