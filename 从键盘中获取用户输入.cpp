// 从键盘读入一行为一个字符串，统计其中数字字符的个数并输出。字符串可能包含空格，最长不超过1000个字符
#include <iostream>
using namespace std;
int main() {
	char ch[1000];
	int count=0;
// 从键盘中获取用户输入的字符，然后回车确认是以\n结尾的，而不是\0，
//\0是编译系统给字符串静态添加的，而不是运行时添加的
	cin.getline(ch, 1000, '\n'); // 不要将cin.getline作为判断，否则会有无限输入流请求
	for (int i = 0; i < strlen(ch);i++) 
			if (ch[i] <= '9'&&ch[i] >= '0') count++;	
	cout << count << endl;
	return 0;
}
