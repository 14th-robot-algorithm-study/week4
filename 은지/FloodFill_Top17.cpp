#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Point {
	int y, x;
};

int N, M;
int year;
int num_val;
int map[76][76];
int visited[76][76];
int zeronum[76][76];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1 ,1 };


void melt() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] -= zeronum[i][j];

			if (map[i][j] < 0) {
				map[i][j] = 0;
			}
		}
	}
}


void reset() {
	memset(visited, 0, sizeof(visited));
	memset(zeronum, 0, sizeof(zeronum));

	num_val = 0;
}


int count(Point cp) {
	int num = 0;

	for (int i = 0; i < 4; i++) {
		int ny = cp.y + dy[i];
		int nx = cp.x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
			continue;
		}

		if (map[ny][nx] == 0) {
			num++;
		}
	}

	return num;
}


void bfs(Point st) {
	queue <Point> q;
	q.push(st);
	visited[st.y][st.x] = 1;

	while (!q.empty()) {
		Point now = q.front();
		zeronum[now.y][now.x] = count(now);
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
				continue;
			}

			if (map[ny][nx] == 0) {
				continue;
			}

			if (visited[ny][nx]) {
				continue;
			}

			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
}


void init() {
	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> map[i][j];
		}
	}
}


int main() {
	init();

	while (1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] != 0 && visited[i][j] == 0) {
					bfs({ i, j });
					num_val++;
				}
			}
		}

		// [1] 빙산이 모두 녹았을 경우
		if (num_val == 0) {
			year = 0;
			break;
		}

		// [2] 빙산이 분리됐을 경우
		if (num_val > 1) {
			break;
		}

		// [3] 빙산이 한 덩어리일 경우
		if (num_val == 1) {
			melt();
			year++;
			reset();
		}
	}

	std::cout << year;

	return 0;
}
