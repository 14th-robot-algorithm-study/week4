#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Point {
	int y, x;
};

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int T;
int N, K;
int map[8][8];
int visited[8][8];
int max_height;
int max_length;

void dfs(Point cp, int len, int flag) {
	max_length = max(max_length, len);

	for (int dir = 0; dir < 4; dir++) {
		Point np = { cp.y + dy[dir], cp.x + dx[dir] };
		if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= N) continue;
		if (visited[np.y][np.x] == 1) continue;
		if (map[np.y][np.x] >= map[cp.y][cp.x] && flag == 1) continue;

		if (map[np.y][np.x] < map[cp.y][cp.x]) {
			visited[np.y][np.x] = 1;
			dfs(np, len + 1, flag);
			visited[np.y][np.x] = 0;
		}
		else if (map[np.y][np.x] >= map[cp.y][cp.x] && flag == 0) {
			if (map[np.y][np.x] - K < map[cp.y][cp.x]) {
				int temp = map[np.y][np.x];
				map[np.y][np.x] = map[cp.y][cp.x] - 1;
				visited[np.y][np.x] = 1;
				dfs(np, len + 1, 1);
				visited[np.y][np.x] = 0;
				map[np.y][np.x] = temp;
			}
		}
	}
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		memset(map, 0, sizeof(map));
		max_height = 0;
		max_length = 0;
		cin >> N >> K;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				max_height = max(max_height, map[i][j]);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == max_height) {
					visited[i][j] = 1;
					dfs({ i, j }, 1, 0);
					visited[i][j] = 0;
				}
			}
		}
		
		cout << "#" << tc << " " << max_length << "\n";
	}
}
