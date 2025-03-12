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

//�������е����ѷ���
void max_heapify(int* a, int now, int size)
{
	int left = now * 2 + 1; //���ӽڵ��±�
	int right = now * 2 + 2; //���ӽڵ��±�
	int largest = now;
	if (left < size && a[left] > a[largest]) //������ӽڵ���ڵ�ǰ�ڵ�
		largest = left; //�������ֵ�±�Ϊ���ӽڵ�
	if (right < size && a[right] > a[largest]) //������ӽڵ���ڵ�ǰ�ڵ�����ӽڵ�
		largest = right; //�������ֵ�±�Ϊ���ӽڵ�
	if (largest != now) //������ֵ�����ڵ�ǰ�ڵ�
	{
		swap(a[now], a[largest]); //�������ֵ�͵�ǰ�ڵ�
		max_heapify(a, largest, size); //�ݹ��������
	}
}

//ά����СΪk������
void maintain_heap(int* a, int size)
{
	for (int i = size / 2 - 1; i >= 0; i--) //�����һ����Ҷ�ӽڵ㿪ʼ������ֱ�����ڵ�
		max_heapify(a, i, size);
}

//���ڶѵ�ѡ���㷨
int heap_select(int* a, int size, int k)
{
	maintain_heap(a, k); //ά����СΪk������
	for (int i = k; i < size; i++) //��������n-k��Ԫ��
	{
		if (a[i] < a[0]) //�����ǰԪ��С�����ѵĸ��ڵ�
		{
			swap(a[i], a[0]); //�滻���ڵ�
			max_heapify(a, 0, k); //���µ�������
		}
	}
	return a[0]; //���ѵĸ��ڵ㼴Ϊ��kС��Ԫ��
}

int main()
{
	srand(time(NULL)); //��ʼ�����������
	cout << "������Ԫ�ظ���n�͵�kС��Ԫ��λ��k��" << endl;
	cin >> n >> k;
	cout << "������" << n << "��Ԫ�أ�" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "��" << k << "С��Ԫ���ǣ�" << heap_select(a, n, k) << endl; //�����kС��Ԫ��
	return 0;
}
