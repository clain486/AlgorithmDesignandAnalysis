#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

const int MAXN = 100000; //����������󳤶�

int n, k; //n��ʾ���鳤�ȣ�k��ʾҪ��ĵ�kС��Ԫ��
int a[MAXN]; //��������a

inline int rand_int(int l, int r) //����[l,r]�ڵ��������
{
	return l + rand() % (r - l + 1);
}

int partition(int l, int r, int p) //���������飬��������ŦԪ���±�
{
	swap(a[p], a[r]); //����ŦԪ�طŵ�����ĩβ
	int i = l - 1;
	for (int j = l; j < r; j++)
	{
		if (a[j] <= a[r])
		{
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[r]); //����ŦԪ�طŵ���ȷλ��
	return i + 1; //������ŦԪ���±�
}

int median(int l, int r) //�������������λ�������������±�
{
	if (l == r)
		return l;
	int i = l;
	for (; i + 4 <= r; i += 5)
	{
		sort(a + i, a + i + 5); //��ÿ������Ϊ5������������
		swap(a[l + (i - l) / 5], a[i + 2]); //��ÿ����������λ���ŵ�ǰ��
	}
	if (i <= r)
	{
		sort(a + i, a + r + 1); //�������5��Ԫ�ص�����������
		swap(a[l + (i - l) / 5], a[i + (r - i) / 2]); //�����һ�����������λ���ŵ�ǰ��
	}
	int mid = l + (r - l) / 10; //������λ���±�
	return mid;
}

int median_select(int l, int r, int k) //�ݹ�Ѱ�ҵ�kС��Ԫ��
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
	srand(time(NULL)); //��ʼ�����������
	cout << "������Ԫ�ظ���n��Ҫ��ĵ�kС��Ԫ��λ��k:" << endl;
	cin >> n >> k; //�������鳤��n��Ҫ��ĵ�kС��Ԫ��ֵk
	cout << "������" << n << "��Ԫ��:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i]; //��������Ԫ��
	}
	int ans = median_select(0, n - 1, k); //Ѱ�ҵ�kС��Ԫ��
	cout << "��" << k << "С��Ԫ����:" << ans << endl; //�����kС��Ԫ��
	return 0;
}


