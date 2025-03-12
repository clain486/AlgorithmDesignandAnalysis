#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 判断数组中是否存在主要元素
int findMajorityElement(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return -1;
    }
    sort(nums.begin(), nums.end()); // 排序
    int count = 1, candidate = nums[0];
    for (int i = 1; i < n; ++i) {
        if (nums[i] == candidate) {  // 如果遇到相同元素，则计数器 +1
            count++;
        }
        else {
            if (count > n / 2) {     // 如果当前元素不同，则判断之前的候选元素是否为主要元素
                return candidate;
            }
            count = 1;              // 否则更新候选元素和计数器
            candidate = nums[i];
        }
    }
    return (count > n / 2) ? candidate : -1;
}

int main() {
    cout << "请输入数组大小：";     // 提示用户输入数组大小
    int size;
    cin >> size;
    vector<int> nums(size);
    cout << "请输入数组元素：" << endl;   // 提示用户输入数组元素
    for (int i = 0; i < size; ++i) {
        cin >> nums[i];
    }

    int majorityElement = findMajorityElement(nums);   // 查找主要元素

    if (majorityElement != -1) {    // 如果主要元素存在，则输出该元素
        cout << "主要元素为：" << majorityElement << endl;
    }
    else {  // 否则提示不存在主要元素
        cout << "不存在主要元素！" << endl;
    }

    return 0;
}
//以上为O(nlogn)
