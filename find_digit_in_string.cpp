/*
将字符串中的连续数字作为整数并存到另一个数组中
例如input:a123x456-=-17960?302tab587，
output:
123
456
17960
302
587
*/
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int main() {
	char str[50], *str_point;
	int count=0, e10=1, digit=0, num=0, digit_list[10], *digit_point;
	cout << "Enter string" << endl;
	cin>>str;
	str_point = str;
	digit_point = digit_list;
	for (int i = 0;; i++) {
		if (*(str_point+i) >= '0'&&*(str_point+i) <= '9') count++;
		else {
			if (count > 0) {
				for (int ii = 0; ii <count ; ii++) {
					if (i != strlen(str)-1&&*(str_point+i)>'0'&&*(str_point+i)<'9') {
						digit = digit + (*(str + i - ii) - 48)*e10; // 从字符型元素开始逐个往前运算
					}
					else digit = digit + (*(str + i - ii - 1) - 48)*e10; // 从字符型元素开始逐个往前运算
					e10 *= 10;
				}
				/* 这样写指针容易乱
				*digit_point = digit;
				digit_point++;
				*/
				*(digit_point + num) = digit;
				digit = 0,e10=1,count=0;
				num++;
				
			}
		}
		if (*(str_point + i) == '\0') break;// 放在循环体结尾，不然无法检查最后一串数
	}

	for (int i = 0; i < num; i++) cout << *(digit_point + i) << endl;
}

/*
a123x456-=-17960?302tab587s
*/
