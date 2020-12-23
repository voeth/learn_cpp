# include <iostream>
using namespace std;
int main() {
	int list[5] = { 23,66,85,90 },num;
	cin >> num;
	for (int i = 4; i >= 0; i--) {
		// 判断是否符合按顺序，同时把元素往后移
		if (list[i-1]>num) list[i] = list[i-1];
		else { list[i] = num; break; }
	}
	for (int i = 0; i < 5; i++) cout << list[i] << " ";
	return 0;
}
