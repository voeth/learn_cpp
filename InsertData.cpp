/*
输入一个升序数组，再输入一个数字，要求按照原来的排序规律插入数组中
*/

#include <iostream>
using namespace std;
int main() {
	int list[9],num;
	cout << "Enter the order list:" << endl;
	for (int i = 0; i < 7; i++) cin >> list[i];
	cout << "Enter the inserting number: " << endl;
	cin >> num;
	// 升序排列，降序只需改if条件即可
	if (num >= list[6]) list[7] = num; // 如果所插入的数是最大的，直接插入尾部即可。
	else {
		// 从尾部开始逐个比较大小，同时也向后移动元素位置
		for (int i = 6; i >= 0; i--) {
			// 找到了合适的插入位置后，在元素后面插入并逐个向后移动元素
			if (num >= list[i]) {
				// 根据判断条件，不该挪动第i个元素
				for (int ii = 7; ii-1>i; ii--) {
					list[ii] = list[ii - 1];
				}
				// 根据判断条件，在后面插入元素
				list[i+1] = num;
				break;
			}
		}
	}

	for (int i = 0; i < 8; i++) cout << list[i]<<endl;
	return 0;
}

