#include <iostream>
using namespace std;

int num[100];
int visited[100];
int ans;
int N, M;

void dfs(int lev, int sum) {
	if (lev == 3) {
		if (ans < sum && sum <= M) {
			ans = sum;
		}
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] == 1) continue;
		visited[i] = 1;
		dfs(lev + 1, sum + num[i]);
		visited[i] = 0;
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	dfs(0, 0);
	cout << ans;
}
