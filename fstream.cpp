#include <iostream>
#include <fstream>
#include<sstream>
using namespace std;
int main() {
	char str[1000],ch;
	ofstream outfile("f1.dat", ios::out);
	if (!outfile) cerr << "open file error!"; // 如果为空对象则文件打开失败，通常用此来检测文件是否正常打开；
	cout << "please input sentence: " << endl;
	for (int j = 0;; j++) {
		cin.getline(str, 1000, '\n');// 整行获取标准输入流的内容，第一个参数传指针，将数据写入数组中，第二个参数设置读取上限1000字符，第三个参数分隔符
		if (str[0] == '/')	break;// 用户一开始输入 ’/‘ 则结束循环
		for (int i = 0; str[i] != '\0';i++) outfile.put(str[i]); // 用循环体一个个字符写入文件中 也可以 outfile<< str[i] '\0'字符串结尾标识
		outfile.put('\n'); 
	}
	outfile.close();

	ifstream infile("f1.dat", ios::in);
	if (!infile) cerr << "open file error!";
	for (int i = 0; !infile.eof(); i++) { // eof()判断是否读完文件了
		infile >>noskipws>> ch;	 // noskipws 保留空格和换行符一个个字符读出来	
		cout << ch;

	}
	infile.close();
}
