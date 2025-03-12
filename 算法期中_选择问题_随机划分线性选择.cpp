#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <ctime>

using namespace std;

const int MAXN = 100000; //����������󳤶�

int n, k;
int a[MAXN]; //��������

//����[l,r]�ڵ��������
inline int rand_int(int l, int r)
{
    return l + rand() % (r - l + 1);
}

//������������飬��������ŦԪ���±�
int partition(int l, int r)
{
    int p = rand_int(l, r); //��[l,r]�����ѡȡһ������Ϊ��ŦԪ��
    swap(a[p], a[r]); //����ŦԪ�غ��Ҷ˵㽻��
    int i = l - 1; //i��ʾС�ڵ�����ŦԪ�ص�Ԫ�ص����ұߵ�λ��
    for (int j = l; j < r; j++) //��������[l,r-1]
    {
        if (a[j] <= a[r]) //�����ǰԪ��С�ڵ�����ŦԪ��
        {
            i++; //��С����ŦԪ�ص�Ԫ�طŵ����
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]); //����ŦԪ�ػ����м�
    return i + 1; //������ŦԪ�ص�λ��
}

//�ݹ�Ѱ�ҵ�kС��Ԫ��
int randomized_select(int l, int r, int k)
{
    if (l == r) //������䳤��Ϊ1
        return a[l]; //ֱ�ӷ��ظ�Ԫ��
    int q = partition(l, r); //�������������
    int pos = q - l + 1; //������ŦԪ�ص�λ��
    if (pos == k) //����ҵ��˵�kС��Ԫ��
        return a[q]; //ֱ�ӷ��ظ�Ԫ��
    else if (k < pos) //�����kС��Ԫ�������
        return randomized_select(l, q - 1, k); //�ݹ�Ѱ����벿��
    else //�����kС��Ԫ�����ұ�
        return randomized_select(q + 1, r, k - pos); //�ݹ�Ѱ���Ұ벿��
}

int main()
{
    srand(time(NULL)); //��ʼ�������������
    cout << "������Ԫ�ظ���n�͵�kС��Ԫ��λ��k��" << endl;
    cin >> n >> k; //����n��k
    cout << "������" << n << "��Ԫ�أ�" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; //����ÿ��Ԫ��
    }
    cout << "��" << k << "С��Ԫ���ǣ�" << randomized_select(0, n - 1, k) << endl; //�����kС��Ԫ��
    return 0;
}