#include <iostream>
using namespace std;

int main() {
	int maxNum = -21e8;
	int maxIndex = -1;
	for (int i = 0; i < 9; i++) {
		int Num;
		cin >> Num;

		if (maxNum < Num) {
			maxNum = Num;
			maxIndex = i+1;
		}
	}

	cout << maxNum << "\n" << maxIndex;
}
