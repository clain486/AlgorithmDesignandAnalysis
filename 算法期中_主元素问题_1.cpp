#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �ж��������Ƿ������ҪԪ��
int findMajorityElement(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return -1;
    }
    sort(nums.begin(), nums.end()); // ����
    int count = 1, candidate = nums[0];
    for (int i = 1; i < n; ++i) {
        if (nums[i] == candidate) {  // ���������ͬԪ�أ�������� +1
            count++;
        }
        else {
            if (count > n / 2) {     // �����ǰԪ�ز�ͬ�����ж�֮ǰ�ĺ�ѡԪ���Ƿ�Ϊ��ҪԪ��
                return candidate;
            }
            count = 1;              // ������º�ѡԪ�غͼ�����
            candidate = nums[i];
        }
    }
    return (count > n / 2) ? candidate : -1;
}

int main() {
    cout << "�����������С��";     // ��ʾ�û����������С
    int size;
    cin >> size;
    vector<int> nums(size);
    cout << "����������Ԫ�أ�" << endl;   // ��ʾ�û���������Ԫ��
    for (int i = 0; i < size; ++i) {
        cin >> nums[i];
    }

    int majorityElement = findMajorityElement(nums);   // ������ҪԪ��

    if (majorityElement != -1) {    // �����ҪԪ�ش��ڣ��������Ԫ��
        cout << "��ҪԪ��Ϊ��" << majorityElement << endl;
    }
    else {  // ������ʾ��������ҪԪ��
        cout << "��������ҪԪ�أ�" << endl;
    }

    return 0;
}
//����ΪO(nlogn)
