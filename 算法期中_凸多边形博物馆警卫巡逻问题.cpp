#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int N = 111;
int n;
double x[N], y[N]; // ����������
double dp[N][N]; // ��¼����ֵ
int s[N][N]; // ��¼���Ų���

// ��������֮��ľ���
double dist(int i, int j)
{
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

// DP�㷨������λ����������ܳ�֮����С�����������ʷ�
double convexPolygonTriangulation()
{
    for (int d = 2; d <= n - 1; d++) { // d Ϊ�����ģ��d = 2 ʵ����������
        for (int i = 1; i <= n - d; i++) { // ���� i ֵ
            int j = i + d; // j ֵ
            dp[i][j] = -1; // ��ʼ��Ϊ��ֵ�������ж��Ƿ��ѱ������
            for (int k = i + 1; k < j; k++) { // ö�ٶϵ�
                double temp = dp[i][k] + dp[k][j] + dist(i, j) + dist(i, k) + dist(k, j);
                if (dp[i][j] < 0 || dp[i][j] > temp) {
                    dp[i][j] = temp;
                    s[i][j] = k;
                }
            }
        }
    }
    return dp[1][n]; // ��������ֵ
}

// �������Ų�������������������
void print(int i, int j)
{
    if (i + 1 >= j) return; // ֻ�����������ϲŴ��ڶԽ���
    cout << "{" << i << "," << j << "," << s[i][j] << "}" << endl;
    print(i, s[i][j]);
    print(s[i][j], j);
}

int main()
{
    int i, j;
    cout << "������͹����εĶ������ n��" << endl;
    cin >> n;
    cout << "��������������������(x,y)��" << endl;
    for (i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    // ����DP�����е�����ֵ�����Ų���
    double minSumLen = convexPolygonTriangulation();
    // ������������ʷ������������ε��ܳ�֮��
    cout << "���ֳ��������������ܳ�֮����Сֵ�ǣ�" << endl;
    cout << minSumLen << endl;
    // ������жԽ����ϵ���
    cout << "͹����ε����������ʷַ���Ϊ��" << endl;
    print(1, n);
    return 0;
}
