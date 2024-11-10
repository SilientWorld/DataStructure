//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define maxsize 10
//#define N 7
//typedef struct Sort
//{
//    int elem[maxsize + 1];//提供存储数组的空间
//    int length;//记录实际数组的长度
//}Sort;
//void DirectSort1(Sort* s)//直接插入排序(无哨兵)
//{
//    int i, j, x;
//    for (i = 1; i <= s->length; i++)
//    {
//        s->elem[0] = 0;//s->elem[0]不是哨兵，只是为了方便和后续元素比较
//        x = s->elem[i];//复制插入的元素，防止元素后移后覆盖此元素
//        for (j = i - 1; j >= 0; j--)
//        {
//            if (x > s->elem[j])
//                break;
//            else
//            {
//                if (x < s->elem[j])
//                    s->elem[j + 1] = s->elem[j];//元素后移
//            }
//            s->elem[j] = x;
//        }
//    }
//}
//void DirectSort2(Sort* s)//直接插入排序(有哨兵)
//{
//    int i, j;
//    for (i = 2; i <= s->length; i++)
//    {
//        if (s->elem[i] < s->elem[i - 1])
//        {
//            s->elem[0] = s->elem[i];//此处为哨兵
//            for (j = i - 1; j >= 0; j--)
//                s->elem[j + 1] = s->elem[j];//元素后移
//            s->elem[j + 1] = s->elem[0];
//        }
//    }
//}
//void BubbleSort1(Sort* s)//冒泡排序
//{
//    int i, j;
//    int flag = 1;
//    for (i = 1; i < s->length && flag; i++)
//    {
//        flag = 0;
//        for (j = s->length - 1; j >= i; j--)
//        {
//            if (s->elem[j] > s->elem[j + 1])//元素交换
//            {
//                int temp = s->elem[j];
//                s->elem[j] = s->elem[j + 1];
//                s->elem[j + 1] = temp;
//                flag = 1;
//            }
//        }
//    }
//}
//void BubbleSort2(Sort* s)//冒泡排序
//{
//    int i, j, flag;
//    for (i = s->length - 1; i > 0; i--)
//    {
//        flag = 0;
//        for (j = 0; j < i; j++)
//        {
//            if (s->elem[j] > s->elem[j + 1])
//            {
//                int temp = s->elem[j];
//                s->elem[j] = s->elem[j + 1];
//                s->elem[j + 1] = temp;
//            }
//            flag = 1;
//        }
//        if (flag == 0)
//            break;
//    }
//}
//void SimpleSort(Sort* s)//选择法排序
//{
//    int i, j;
//    for (i = 1; i < s->length; i++)
//    {
//        for (j = i + 1; j < s->length; j++)//前一个元素与该元素比较
//        {
//            if (s->elem[j] < s->elem[i])//元素交换
//            {
//                int temp = s->elem[i];
//                s->elem[i] = s->elem[j];
//                s->elem[j] = temp;
//            }
//        }
//    }
//}
//void SimpleSort1(Sort* s)//简单选择排序
//{
//    int i, j, min;
//    for (i = 0; i < s->length - 1; i++)
//    {
//        min = i;
//        for (j = i + 1; j < s->length - 1; j++)
//        {
//            if (s->elem[j] < s->elem[min])
//                min = j;
//        }
//    }
//    if (i != min)
//    {
//        int temp = s->elem[i];
//        s->elem[i] = s->elem[min];
//        s->elem[min] = temp;
//    }
//}
//void BinarySort(Sort* s)//折半查找排序
//{
//    int i, j;
//    for (i = 2; i <= s->length; i++)
//    {
//        s->elem[0] = s->elem[i];
//        int low = 1, high = i - 1, mid;
//        while (low <= high)
//        {
//            mid = (low + high) / 2;
//            if (s->elem[0] < s->elem[mid])
//                high = mid - 1;
//            if (s->elem[0] >= s->elem[mid])
//                low = mid + 1;
//        }
//        for (j = i - 1; j >= high + 1; j--)
//            s->elem[j + 1] = s->elem[j];
//        s->elem[high + 1] = s->elem[0];
//    }
//}
//void ShellSort(Sort* s)//希尔排序
//{
//    int i, j, add;
//    add = s->length;
//    do
//    {
//        add = add / 3 + 1;//提供增量，且增量递减，最后递减为1
//        for (i = add + 1; i <= s->length; i++)
//        {
//            if (s->elem[i] < s->elem[i - add])
//            {
//                s->elem[0] = s->elem[i];
//                for (j = i - add; j > 0 && s->elem[0] < s->elem[j]; j -= add)
//                    s->elem[j + add] = s->elem[j];
//                s->elem[j + add] = s->elem[0];
//            }
//        }
//    } while (add > 1);
//}
//int SearchKey(Sort* s, int low, int high)//找到枢轴值并进行排序
//{
//    int pivotkey;
//    int keyElement = (low + high) / 2;//枢轴值
//    if (s->elem[keyElement] > s->elem[high])//保证枢轴值在大致有序的元素的位置
//    {
//        int temp = s->elem[high];
//        s->elem[high] = s->elem[keyElement];
//        s->elem[keyElement] = temp;
//    }
//    if (s->elem[keyElement] > s->elem[low])//保证枢轴值在大致有序的元素的位置
//    {
//        int temp = s->elem[keyElement];
//        s->elem[keyElement] = s->elem[low];
//        s->elem[low] = temp;
//    }
//    if (s->elem[high] < s->elem[low])//保证枢轴值在大致有序的元素的位置
//    {
//        int temp = s->elem[low];
//        s->elem[low] = s->elem[high];
//        s->elem[high] = temp;
//    }
//    pivotkey = s->elem[low];
//    s->elem[0] = pivotkey;
//    while (low < high)
//    {
//        while (low < high && s->elem[high] >= pivotkey)
//            high--;
//        s->elem[low] = s->elem[high];
//        while (low < high && s->elem[low] <= pivotkey)
//            low++;
//        s->elem[high] = s->elem[low];
//    }
//    s->elem[low] = s->elem[0];
//    return low;
//}
//void QuickSort(Sort* s, int low, int high)//快速排序
//{
//    int key;//枢轴
//    if (low < high)
//    {
//        key = SearchKey(s, low, high);//求出枢轴值
//        QuickSort(s, low, key - 1);//对枢轴值前面的元素进行排序
//        QuickSort(s, key + 1, high);//对枢轴值后面的元素进行排序
//    }
//}
//void UpAdjustment(Sort* s, int n, int m)//向上进行堆调整
//{
//    int temp = s->elem[n];
//    for (int j = 2 * n; j <= m; j *= 2)//j*=2表示j的左右孩子
//    {
//        if (j < m && s->elem[j] < s->elem[j + 1])//左右孩子比较
//            j++;
//        if (temp < s->elem[j])//双亲与左右孩子比较
//        {
//            s->elem[n] = s->elem[j];
//            n = j;
//        }
//    }
//    s->elem[n] = temp;
//}
//void PortionSort(Sort* s)//堆排序
//{
//    for (int i = s->length / 2; i > 0; i--)//二叉树的性质，s->length/2代表有孩子的双亲
//        UpAdjustment(s, i, s->length);
//    for (int i = s->length; i > 1; i--)
//    {
//        int temp = s->elem[1];
//        s->elem[1] = s->elem[i];
//        s->elem[i] = temp;
//        UpAdjustment(s, 1, i - 1);
//    }
//}
//void Merge(int* a, int* b, int i, int m, int n)
//{
//    int j, k, l;
//    for (j = m + 1, k = i; i <= m && j <= n; k++)//将a中记录由小到大并入b
//    {
//        if (a[i] < a[j])
//            b[k] = a[i++];
//        else b[k] = a[j++];
//    }
//    if (i <= m)//将剩余的a[i--m]复制到b
//    {
//        for (l = 0; l <= m - i; l++)
//            b[k + l] = a[i + l];
//    }
//    if (j <= n)//将剩余的a[j--n]复制到b
//    {
//        for (l = 0; l <= n - j; l++)
//            b[k + l] = a[j + l];
//    }
//}
//void MergePass(int* a, int* b, int m, int n)
//{
//    int i = 1, j;
//    while (i <= n - 2 * m + 1)//两两归并
//    {
//        Merge(a, b, i, i + m - 1, i + 2 * m - 1);
//        i = i + 2 * m;
//    }
//    if (i < n - m + 1)//归并最后两个序列
//        Merge(a, b, i, i + m - 1, n);
//    else//若剩下单个子序列，直接放到数组后面
//    {
//        for (j = i; j <= n; j++)
//            b[j] = a[j];
//    }
//}
//void MergeSort2(Sort* s)//归并排序(无递归)
//{
//    int* b = malloc(s->length * sizeof(int));
//    int k = 1;
//    while (k < s->length)
//    {
//        MergePass(s->elem, b, k, s->length);
//        k *= 2;//子序列长度加倍
//        MergePass(b, s->elem, k, s->length);
//        k *= 2;
//    }
//}
//void MergeSort1(int* a, int* b, int m, int n)//归并排序(有递归)
//{
//    int i;
//    int c[maxsize + 1];
//    if (m == n)
//        b[m] = a[m];
//    else
//    {
//        i = (m + n) / 2;
//        MergeSort1(a, c, m, i);
//        MergeSort1(a, c, i + 1, n);
//        Merge(c, b, m, i, n);
//    }
//}
//void print(Sort s)
//{
//    int i;
//    for (i = 1; i < s.length; i++)
//        printf("%d,", s.elem[i]);
//    printf("%d", s.elem[i]);
//    printf("\n");
//}
//int main()
//{
//    int i;
//      srand(time(NULL));
//    int d[N] = { 49,38,66,82,13,53,3 };
//    printf("排序前：");
//     for (i = 0; i < N; i++)
//         d[i] = rand() % 100 + 1;
//    for (i = 0; i < N; i++)
//        printf("%d ", d[i]);
//    printf("\n");
//    Sort s;
//    for (i = 0; i < N; i++)
//        s.elem[i + 1] = d[i];
//    s.length = N;
//     printf("直接插入排序（无哨兵）：");
//     DirectSort1(&s);
//     print(s);
//     printf("直接插入排序（有哨兵）：");
//     DirectSort2(&s);
//     print(s);
//     printf("冒泡排序1：");
//     BubbleSort1(&s);
//     print(s);
//     printf("冒泡排序2：");
//     BubbleSort2(&s);
//     print(s);
//     printf("选择法排序：");
//     SimpleSort(&s);
//     print(s);
//     printf("简单选择排序：");
//     SimpleSort1(&s);
//     print(s);
//     printf("折半查找排序：");
//     BinarySort(&s);
//     print(s);
//     printf("希尔排序：");
//     ShellSort(&s);
//     print(s);
//    printf("快速排序：");
//    QuickSort(&s, 1, N);
//    print(s);
//     printf("堆排序：");
//     PortionSort(&s);
//     print(s);
//     printf("归并排序(有递归)：");
//     MergeSort1(&(s.elem), &(s.elem), 1, s.length);
//     print(s);
//     printf("归并排序(无递归)：");
//     MergeSort2(&s);
//     print(s);
//    return 0;
//}
