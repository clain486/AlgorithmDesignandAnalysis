#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

const int MAXN = 100000; //定义数组最大长度

int n, k; //n表示数组长度，k表示要求的第k小的元素
int a[MAXN]; //定义数组a

inline int rand_int(int l, int r) //生成[l,r]内的随机整数
{
	return l + rand() % (r - l + 1);
}

int partition(int l, int r, int p) //划分子数组，并返回枢纽元素下标
{
	swap(a[p], a[r]); //将枢纽元素放到数组末尾
	int i = l - 1;
	for (int j = l; j < r; j++)
	{
		if (a[j] <= a[r])
		{
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[r]); //将枢纽元素放到正确位置
	return i + 1; //返回枢纽元素下标
}

int median(int l, int r) //计算子数组的中位数，并返回其下标
{
	if (l == r)
		return l;
	int i = l;
	for (; i + 4 <= r; i += 5)
	{
		sort(a + i, a + i + 5); //对每个长度为5的子数组排序
		swap(a[l + (i - l) / 5], a[i + 2]); //将每个子数组中位数放到前面
	}
	if (i <= r)
	{
		sort(a + i, a + r + 1); //对最后不足5个元素的子数组排序
		swap(a[l + (i - l) / 5], a[i + (r - i) / 2]); //将最后一个子数组的中位数放到前面
	}
	int mid = l + (r - l) / 10; //计算中位数下标
	return mid;
}

int median_select(int l, int r, int k) //递归寻找第k小的元素
{
	if (l == r)
		return a[l];
	int p = median(l, r);
	int q = partition(l, r, p);
	int pos = q - l + 1;
	if (pos == k)
		return a[q];
	else if (k < pos)
		return median_select(l, q - 1, k);
	else
		return median_select(q + 1, r, k - pos);
}

int main()
{
	srand(time(NULL)); //初始化随机数种子
	cout << "请输入元素个数n和要求的第k小的元素位置k:" << endl;
	cin >> n >> k; //输入数组长度n和要求的第k小的元素值k
	cout << "请输入" << n << "个元素:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i]; //输入数组元素
	}
	int ans = median_select(0, n - 1, k); //寻找第k小的元素
	cout << "第" << k << "小的元素是:" << ans << endl; //输出第k小的元素
	return 0;
}


