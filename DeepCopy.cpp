#include<iostream>
#include<fstream>
#include<cstring>
#include "DEMO\\intArray.h"
using namespace std;

intArray::intArray()
{
	length = 10;
	array = new int[length];
}

intArray::intArray(char *filename)
{
	ifstream myFile(filename);
	array = new int[300];
	length = 0;
	while (myFile >> array[length++]);
	length--;
	myFile.close();
}

// 深拷贝常用的写法，重载“=”操作符实现
intArray& intArray::operator=(const intArray & src)
{
	if (array != NULL) delete[] array;
	length = src.length;
	array = new int[length];
	//*************333***********
	for (int i = 0; i < length; i++) *(array + i) = src.array[i];


	//**********666*********
	return *this;
}

intArray::~intArray()
{	// 删除指向数组的指针，要这样写
	delete[] array;
}

void intArray::show()
{
	int step = 0;
	for (int i = 0; i < length; i = i + step)
	{
		cout << array[i] << endl;
		step++;
	}
}

void main()
{
	intArray *arrayP = new intArray((char *)"DEMO\\input.dat");
	intArray myArray;
	myArray = *arrayP;
	(*arrayP).show();
	delete arrayP;

	//writeToFile("");
}


