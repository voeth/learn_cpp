#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Person {
	string name;
	int age;
};
int main() {
	
	Person *person = new Person[3];// 使用new内存管理更可控
	for (int i = 0; i < 3; i++) cin >> person[i].name >> person[i].age;
	
	// 注意用 | 分隔打开文件方式否则无效 默认情况下文件打开文件输出流将删除以前的数据
	ofstream outfile = ofstream("f1.dat", ios::binary|ios::app|ios::ate);
	//outfile.seekp(5 * sizeof(Person), ios::beg); 
	for (int i = 0; i < 3; i++) outfile.write((char *) &person[i], sizeof(person[i])); 
	outfile.close();
	
	delete[] person;
	//delete &outfile;
	  
	
	ifstream infile = ifstream("f1.dat", ios::binary|ios::in);
	Person *p =new Person [100];// 只有内存足够就能保证申请到预期指定的空间，数据将存在堆中 
	//Person p[10];	系统自动分配和回收内存，数据存在栈中，当数据量较大时，无法保证获取预期的内存空间，程序运行时容易导致内存地址访问错误
	int len = -1;

// 以每个数据所占的内存大小作为单位偏移量，sizeof确保正确获取数据的内存大小。从文件头部往后移3个单位内存相当于忽略了3条数据，seek|tell g(get) 输入流 p(put) 输出流
	infile.seekg(3*sizeof(Person) ,ios::beg);
	for (int i = 0; !infile.eof(); i++) { // 读取文件所有内容
		infile.read((char *)&p[i], sizeof(p[i]));
		cout << "已经读取到了"<<infile.tellg() << endl; // 获取当前文件流指针位置
		len++; }

	for (int i = 0; i < len; i++) { // 完整输出文件所有内容
		cout << "No." << i+1<< endl;
		cout << p[i].name << " " << p[i].age << endl;
	}
	//delete[] p;
	infile.close();
}
