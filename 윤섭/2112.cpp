#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, D, W, K;
int film[13][20];
int backup[13][20];
int answer;

bool check() {
	for (int c = 0; c < W; c++) {
		int cnt = 1, ok = 0;
		for (int r = 1; r < D; r++) {
			if (film[r][c] == film[r - 1][c]) cnt++;
			else cnt = 1;
			if (cnt >= K) { ok = 1; break; }
		}
		if (!ok) return false;
	}
	return true;
}

void dfs(int row, int used) {
	if (used >= answer) return;
	if (row == D) {
		if (check()) answer = min(answer, used);
		return;
	}

	dfs(row + 1, used);

	int tmp[20];
	for (int c = 0; c < W; c++) {
		tmp[c] = film[row][c];
		film[row][c] = 0;
	}

	dfs(row + 1, used + 1);

	for (int c = 0; c < W; c++) film[row][c] = 1;
	dfs(row + 1, used + 1);

	for (int c = 0; c < W; c++) film[row][c] = tmp[c];
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> D >> W >> K;
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> film[i][j];
			}
		}

		answer = K;

		if (check()) answer = 0;
		else dfs(0, 0);

		cout << "#" << tc << " " << answer << "\n";
	}
}
