#include <iostream>							
using namespace std;
// 一定要从1开始计数，因为人类所说的晚几天都是从1开始数的，但是计算机从0开始计数，否则计算差值时会出现偏差，导致无法满足相应条件判断失误。
// 以后遇到计数、差值时最好从1开始
//enum nightShift { Sunday=1, Monday, Tuesday, Wednesday, Thurday, Friday, Saturday }; // 修改首元素数值，可改变整个枚举的偏移量
enum nightShift { Sunday, Monday, Tuesday, Wednesday, Thurday, Friday, Saturday }; // 修改首元素数值，可改变整个枚举的偏移量
nightShift layout[7];// 容器、元素数据类型最好完全一致，不然容易出错。
int a, b, c, d, e, f, g;
int main() {
	bool repeat(nightShift[]);
	bool meet(nightShift[]);
	void print(nightShift[]);

	// 不加括号就执行最近的语句，就没有嵌套了
	for (a = Sunday; a <= Saturday; a++) {
		layout[0] = (nightShift)a;
		for (b = Sunday; b <= Saturday; b++) {
			layout[1] = (nightShift)b;
			for (c = Sunday; c <= Saturday; c++) {
				layout[2] = (nightShift)c;
				for (d = Sunday; d <= Saturday; d++) {
					layout[3] = (nightShift)d;
					for (e = Sunday; e <= Saturday; e++) {
						layout[4] = (nightShift)e;
						for (f = Sunday; f <= Saturday; f++) {
							layout[5] = (nightShift)f;
							for (g = Sunday; g <= Saturday; g++) {
								layout[6] = (nightShift)g;
								// 将条件检测封装成函数，虽然效率降低了，但是逻辑模块更加清晰有条理。
								if (meet(layout) && repeat(layout))
								{
									print(layout);
									cout << endl;
								}

							}
						}


					}

				}

			}

		}
	}


}

bool repeat(nightShift list[]) {
	for (int i = 0; i < 7; i++) {
		for (int ii = i + 1; ii < 7; ii++) {
			if (list[i] == list[ii]) return false;
		}
	}
	return true;
}

// 数值下标对应着医生名字，数组值代表星期
bool meet(nightShift list[]) {
	if (list[0] - list[2] == 1)
		if (list[3] - list[4] == 2)
			if (list[6] - list[1] == 3)
				if (list[5] - list[1] == list[2] - list[5])
					//if (list[5] == 4)
					if(list[5]==3)// list[5]==Thurday 不成立！枚举元素本质上就是整型
						return true;
	return false;
}

void print(nightShift list[]) {
	for (int i = 0; i < 7; i++) {
		// switch-case match enumeration very much!
		switch (list[i])
		{
		case Sunday: cout << "Doctor " << (char)(65 + i) << "'s workday is: " << "Sunday" << endl; break;
		case Monday: cout << "Doctor " << (char)(65 + i) << "'s workday is: " << "Monday" << endl; break;
		case Tuesday:cout << "Doctor " << (char)(65 + i) << "'s workday is: " << "Tuesday" << endl;	break;
		case Wednesday:cout << "Doctor " << (char)(65 + i) << "'s workday is: " << "Wednesday" << endl;	break;
		case Thurday: cout << "Doctor " << (char)(65 + i) << "'s workday is: " << "Thurday" << endl; break;
		case Friday: cout << "Doctor " << (char)(65 + i) << "'s workday is: " << "Friday" << endl; break;
		case Saturday: cout << "Doctor " << (char)(65 + i) << "'s workday is: " << "Saturday" << endl; break;
		}
	}
}
