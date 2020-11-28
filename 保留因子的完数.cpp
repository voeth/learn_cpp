#include <iostream>
using namespace std;
int main() {
	int factors[100] = { 1 };
	for (int i = 6; i < 1000; i++) {
		int len = 1, judge = 1;
		for (int ii = 2; ii < i / 2; ii++) {
			bool inserted = false;
			if(i%ii==0){
				for (int iii = 0; iii < len; iii++) {
					if (ii == factors[iii]) {
						inserted = true;
						break;
					}
				}
				if (!inserted) {
					factors[len] = ii,factors[len + 1] = i / ii;
					judge += ii + i / ii;
					len += 2;
				}
			}
		}
		if (judge == i) {
			cout << i << " its factors are ";
			for (int ii = 0; ii < len; ii++) cout << factors[ii] << ',';
			cout << endl;
		}
		
	}
	return 0;
}

