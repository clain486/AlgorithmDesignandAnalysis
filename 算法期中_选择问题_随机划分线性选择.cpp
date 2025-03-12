#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <ctime>

using namespace std;

const int MAXN = 100000; //定义数组最大长度

int n, k;
int a[MAXN]; //定义数组

//生成[l,r]内的随机整数
inline int rand_int(int l, int r)
{
    return l + rand() % (r - l + 1);
}

//随机划分子数组，并返回枢纽元素下标
int partition(int l, int r)
{
    int p = rand_int(l, r); //在[l,r]中随机选取一个数作为枢纽元素
    swap(a[p], a[r]); //将枢纽元素和右端点交换
    int i = l - 1; //i表示小于等于枢纽元素的元素的最右边的位置
    for (int j = l; j < r; j++) //遍历区间[l,r-1]
    {
        if (a[j] <= a[r]) //如果当前元素小于等于枢纽元素
        {
            i++; //将小于枢纽元素的元素放到左边
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]); //把枢纽元素换到中间
    return i + 1; //返回枢纽元素的位置
}

//递归寻找第k小的元素
int randomized_select(int l, int r, int k)
{
    if (l == r) //如果区间长度为1
        return a[l]; //直接返回该元素
    int q = partition(l, r); //随机划分子数组
    int pos = q - l + 1; //计算枢纽元素的位置
    if (pos == k) //如果找到了第k小的元素
        return a[q]; //直接返回该元素
    else if (k < pos) //如果第k小的元素在左边
        return randomized_select(l, q - 1, k); //递归寻找左半部分
    else //否则第k小的元素在右边
        return randomized_select(q + 1, r, k - pos); //递归寻找右半部分
}

int main()
{
    srand(time(NULL)); //初始化随机数生成器
    cout << "请输入元素个数n和第k小的元素位置k：" << endl;
    cin >> n >> k; //输入n和k
    cout << "请输入" << n << "个元素：" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; //输入每个元素
    }
    cout << "第" << k << "小的元素是：" << randomized_select(0, n - 1, k) << endl; //输出第k小的元素
    return 0;
}