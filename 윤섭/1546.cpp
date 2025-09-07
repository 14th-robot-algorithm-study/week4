#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int	N;
	cin >> N;

	double arr[1000] = { 0 };
	double max_num = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		max_num = max(max_num, arr[i]);
	}

	double ans = 0;
	for (int i = 0; i < N; i++) {
		ans += (arr[i] / max_num) * 100;
	}
	cout << ans / N;

}
