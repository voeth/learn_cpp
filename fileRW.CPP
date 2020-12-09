#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int input = 0, num[10], sorted = 0, temp;
	
	ofstream out1("file1.txt"),out2("file2.txt"),out3("file3.txt");
	
	if (out1&&out2) {
		for (int i = 0; i < 10; i++) {
			cin >> input;
			if (input % 3 == 0) out1 << input << ' ';
			else out2 << input << ' ';
		}
	}

	else if (!out1) cerr << "Open file1.txt error" << endl;
	else cerr << "Open file2.txt error" << endl;
	out1.close();  // close()才能从缓存流真正写入磁盘
	out2.close();
	 

	ifstream in1("file1.txt"), in2("file2.txt");

	int len = 0;
	while (in1 >> num[len]) len++; // 输入流对象读到文件尾部会自动阻断循环，而且能避免空格输入
	while (in2 >> num[len]) len++;
		

	while (!sorted) {
		sorted = 1;
		for(int i=0;i<len-1;i++)
			if (num[i] < num[i + 1]) {
				sorted = 0;
				temp = num[i];
				num[i] = num[i + 1];
				num[i + 1] = temp;
			}
	}

	for (int i = 0; i < len; i++) cout<<num[i]<<' ';
	out3.close();
	
	return 0;

}

