#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

int main()
{
	int num, base;
	cin >> num >> base;
	string s = "0123456789ABCDEF";
	string result;
	while (num != 0) {
		result += s[num%base];
		num /= base;
	}
	reverse(result.begin(), result.end());
	cout << result;
	return 0;
}
