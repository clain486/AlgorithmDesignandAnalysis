//以下为O(n)
#include <iostream>
#include <vector>

using namespace std;

// 查找给定数组的主要元素（出现次数超过一半的元素）
int findMajorityElement(vector<int>& nums) {
    int candidate = 0, count = 0;  // 初始化候选元素和计数器

    // 遍历整个数组
    for (int num : nums) {
        if (count == 0) {          // 如果计数器为 0，则将当前元素设为候选元素
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;  // 如果当前元素等于候选元素，则计数器 +1，否则 -1
    }

    count = 0;      // 重新初始化计数器
    // 再次遍历整个数组
    for (int num : nums) {
        if (num == candidate) {     // 统计候选元素在数组中出现的次数
            count++;
        }
    }

    // 如果候选元素出现次数大于 n/2，则返回该元素，否则返回 -1
    return (count > nums.size() / 2) ? candidate : -1;
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
