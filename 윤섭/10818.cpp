#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int maxNum = -21e8;
	int minNum = 21e8;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		
		maxNum = max(num, maxNum);
		minNum = min(num, minNum);
	}

	cout << minNum << " " << maxNum;
}
