#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <ctime>
using namespace std;

const int MAXN = 100000;

int n, k;
int a[MAXN];

//堆排序中的最大堆方法
void max_heapify(int* a, int now, int size)
{
	int left = now * 2 + 1; //左子节点下标
	int right = now * 2 + 2; //右子节点下标
	int largest = now;
	if (left < size && a[left] > a[largest]) //如果左子节点大于当前节点
		largest = left; //更新最大值下标为左子节点
	if (right < size && a[right] > a[largest]) //如果右子节点大于当前节点和左子节点
		largest = right; //更新最大值下标为右子节点
	if (largest != now) //如果最大值不等于当前节点
	{
		swap(a[now], a[largest]); //交换最大值和当前节点
		max_heapify(a, largest, size); //递归调整子树
	}
}

//维护大小为k的最大堆
void maintain_heap(int* a, int size)
{
	for (int i = size / 2 - 1; i >= 0; i--) //从最后一个非叶子节点开始调整，直到根节点
		max_heapify(a, i, size);
}

//基于堆的选择算法
int heap_select(int* a, int size, int k)
{
	maintain_heap(a, k); //维护大小为k的最大堆
	for (int i = k; i < size; i++) //遍历后面n-k个元素
	{
		if (a[i] < a[0]) //如果当前元素小于最大堆的根节点
		{
			swap(a[i], a[0]); //替换根节点
			max_heapify(a, 0, k); //重新调整最大堆
		}
	}
	return a[0]; //最大堆的根节点即为第k小的元素
}

int main()
{
	srand(time(NULL)); //初始化随机数种子
	cout << "请输入元素个数n和第k小的元素位置k：" << endl;
	cin >> n >> k;
	cout << "请输入" << n << "个元素：" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "第" << k << "小的元素是：" << heap_select(a, n, k) << endl; //输出第k小的元素
	return 0;
}
