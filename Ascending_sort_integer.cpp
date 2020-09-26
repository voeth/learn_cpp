// Ascending sorting integer number.
# include <iostream>
using namespace std;
int main() {
	void sort(int *,int len = 4);
	int a[4];
	cout << "enter four numbers" << endl;
	for (int i = 0; i < 4; i++) cin >> a[i];
	sort(a);
	for (int i = 0; i < 4; i++) cout << a[i] << endl;
	return 0;
}
void sort(int *list, int len) {
	int front, end, point,temp; //front,end record offset for point(relative position in array). point record the position of minest element. 
	// Using the double loop to compare front and end element. Ascending sort.
	for (front = 0; front < len-1; front++) {
		point = front; // Initialize a minest element.	
		for (end = front + 1; end < len; end++) {
			// The end compare front
			if (*(list+point) > *(list + end)) {// Using the point to get value of array
				point = end;  // Record the position of the minest element.
			}
		}
		// Exchange the position of minest element to the most front(in current loop)
		temp = *(list + front);
		*(list + front) = *(list + point);
		*(list + point) = temp;
	}
}
