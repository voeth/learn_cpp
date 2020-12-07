#include <iostream>
using namespace std;
class CGeo {
public:
	CGeo() {}
	~CGeo() { }
	virtual float area()= 0;
	virtual float perimeter() = 0;
	// 重载操作符写在父类，避免多次在子类声明
	friend bool operator > (CGeo &c1, CGeo &c2);
	friend bool operator <(CGeo &c1, CGeo &c2);
};

class Square :public CGeo {
	float length;
public:
	Square(float l) :length(l) {}
	float area() { return length * length; }
	float perimeter() { return 4 * length; }
	float getLength() { return length; }
};

class Rectangle :public CGeo {
	float width;
	float length;
public:
	Rectangle(float w, float l) :width(w), length(l) {};
	float area() { return width * length; }
	float perimeter() { return 2 * width + 2 * length; }
	float getWidth() { return width; }
	float getLength() { return length; }
};

bool operator >(CGeo &c1, CGeo &c2) {
	if (c1.area() > c2.area()) return true;
	return false;
}

bool operator <(CGeo &c1, CGeo &c2) {
	if (c1.area() < c2.area()) return true;
	return false;
}

int main()
{
	
	Rectangle r(11, 22);
	Square s(6);
	CGeo *g1=&r, *g2=&s;
	cout << g1->area() << endl;
	cout << g2->area() << endl;
	if (g1 > g2) cout << "g1 larger" << endl;
}
