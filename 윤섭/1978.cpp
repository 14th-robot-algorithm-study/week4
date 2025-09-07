#include <iostream>
using namespace std;

int main() {
	int N;
	int ans = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		
		int cnt = 0;
		for (int j = 1; j <= num; j++) {
			if (num % j == 0) cnt++;
			
			if (num == j && cnt == 2) {
				ans++;
			}
		}
	}

	cout << ans;
}
