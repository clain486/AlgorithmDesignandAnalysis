//����ΪO(n)
#include <iostream>
#include <vector>

using namespace std;

// ���Ҹ����������ҪԪ�أ����ִ�������һ���Ԫ�أ�
int findMajorityElement(vector<int>& nums) {
    int candidate = 0, count = 0;  // ��ʼ����ѡԪ�غͼ�����

    // ������������
    for (int num : nums) {
        if (count == 0) {          // ���������Ϊ 0���򽫵�ǰԪ����Ϊ��ѡԪ��
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;  // �����ǰԪ�ص��ں�ѡԪ�أ�������� +1������ -1
    }

    count = 0;      // ���³�ʼ��������
    // �ٴα�����������
    for (int num : nums) {
        if (num == candidate) {     // ͳ�ƺ�ѡԪ���������г��ֵĴ���
            count++;
        }
    }

    // �����ѡԪ�س��ִ������� n/2���򷵻ظ�Ԫ�أ����򷵻� -1
    return (count > nums.size() / 2) ? candidate : -1;
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
