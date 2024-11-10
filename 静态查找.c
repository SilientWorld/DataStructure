//#include <stdio.h>
//int SequentialSearch(int* a, int n, int key)//顺序查找(无哨兵，有序)
//{//a是数组，n是要查找的数组个数，key是要查找的元素
//    for (int i = 1; i <= n; i++)
//    {
//        if (a[i] == key)
//            return i;
//    }
//    return 0;
//}
//int SequentialSearch2(int* a, int n, int key)//顺序查找(有哨兵，有序)
//{
//    a[0] = key;
//    int i = n;
//    while (a[i] != key)
//        i--;
//    return i;
//}
//int BinarySearch(int* a, int n, int key)//折半查找（有序）
//{
//    int left, middle, right;
//    left = 1;/* 定义最低下标为记录首位 */
//    right = n;/* 定义最高下标为记录末位 */
//    while (left < right)
//    {
//        middle = (left + right) / 2;/* 折半 */
//        if (key < a[middle])/* 若查找值比中值小 */
//            right = middle - 1;/* 最高下标调整到中位下标小一位 */
//        else
//            if (key > a[middle])/* 若查找值比中值大 */
//                left = middle + 1;/* 最低下标调整到中位下标大一位 */
//            else
//                if (key == a[middle])/* 若相等则说明mid即为查找到的位置 */
//                    return middle;
//    }
//    return 0;
//}
//int InterSearch(int* a, int n, int key)//插值查找（适用于关键字分布比较均匀，有序）
//{
//    int left, middle, right;
//    left = 1;/* 定义最低下标为记录首位 */
//    right = n;/* 定义最高下标为记录末位 */
//    while (left <= right)
//    {
//        middle = left + (right - left) * (key - a[left]) / (a[right] - a[left]);/*插值*/
//        if (key < a[middle])/* 若查找值比中值小 */
//            right = middle - 1;/* 最高下标调整到中位下标小一位 */
//        else if (key > a[middle])/* 若查找值比中值大 */
//            left = middle + 1;/* 最低下标调整到中位下标大一位 */
//        else if (key == a[middle])
//            return middle;
//    }
//    return 0;
//}
//int main()
//{
//    int result, i;
//    int arr[11] = { 0,1,16,24,35,47,59,62,73,88,99 };
//    result = SequentialSearch(arr, 11, 35);
//    if (result)
//        printf("已查到该元素在第%d个\n", result + 1);
//    else printf("未找到该元素！\n");
//
//    result = SequentialSearch2(arr, 11, 62);
//    if (result)
//        printf("已查到该元素在第%d个\n", result + 1);
//    else printf("未找到该元素！\n");
//
//    result = BinarySearch(arr, 11, 1);
//    if (result)
//        printf("已查到该元素在第%d个\n", result + 1);
//    else printf("未找到该元素！\n");
//
//    result = InterSearch(arr, 12, 46);
//    if (result)
//        printf("已查到该元素在第%d个\n", result + 1);
//    else printf("未找到该元素！\n");
//
//    return 0;
////}