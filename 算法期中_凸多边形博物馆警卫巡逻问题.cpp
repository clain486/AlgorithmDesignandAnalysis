#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int N = 111;
int n;
double x[N], y[N]; // 各顶点坐标
double dp[N][N]; // 记录最优值
int s[N][N]; // 记录最优策略

// 计算两点之间的距离
double dist(int i, int j)
{
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

// DP算法求解多边形划分三角形周长之和最小的最优三角剖分
double convexPolygonTriangulation()
{
    for (int d = 2; d <= n - 1; d++) { // d 为问题规模，d = 2 实际有三个点
        for (int i = 1; i <= n - d; i++) { // 控制 i 值
            int j = i + d; // j 值
            dp[i][j] = -1; // 初始化为负值，用于判断是否已被计算过
            for (int k = i + 1; k < j; k++) { // 枚举断点
                double temp = dp[i][k] + dp[k][j] + dist(i, j) + dist(i, k) + dist(k, j);
                if (dp[i][j] < 0 || dp[i][j] > temp) {
                    dp[i][j] = temp;
                    s[i][j] = k;
                }
            }
        }
    }
    return dp[1][n]; // 返回最优值
}

// 根据最优策略输出所有子问题的弦
void print(int i, int j)
{
    if (i + 1 >= j) return; // 只有三个点以上才存在对角线
    cout << "{" << i << "," << j << "," << s[i][j] << "}" << endl;
    print(i, s[i][j]);
    print(s[i][j], j);
}

int main()
{
    int i, j;
    cout << "请输入凸多边形的顶点个数 n：" << endl;
    cin >> n;
    cout << "请依次输入各顶点的坐标(x,y)：" << endl;
    for (i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    // 计算DP数组中的最优值和最优策略
    double minSumLen = convexPolygonTriangulation();
    // 输出最优三角剖分中所有三角形的周长之和
    cout << "划分出的所有三角形周长之和最小值是：" << endl;
    cout << minSumLen << endl;
    // 输出所有对角线上的弦
    cout << "凸多边形的最优三角剖分方案为：" << endl;
    print(1, n);
    return 0;
}
