#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Edge {
	int y, x;
	int val;
};

struct cmp {
	bool operator()(Edge a, Edge b) {
		return a.val > b.val;
	}
};

int Y, X, N;
int max_val;
int map[1'001][1'001];
int visited[1'001][1'001];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void dijkstra(Edge sp) {
	priority_queue <Edge, vector <Edge>, cmp> pq;
	pq.push(sp);
	visited[sp.y][sp.x] = sp.val;

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (visited[now.y][now.x] < now.val) {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
				continue;
			}

			if (map[ny][nx] == -1) {
				visited[ny][nx] = -1;
				continue;
			}

			int ncost = visited[now.y][now.x] + map[ny][nx];

			if (ncost < visited[ny][nx]) {
				visited[ny][nx] = ncost;
				pq.push({ny, nx, ncost});
			}
		}
	}
}

void init() {
	std::cin >> Y >> X >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 21e8;
		}
	}
}

int main() {
	init();
	dijkstra({ Y, X, map[Y][X] });
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (max_val < visited[i][j]) {
				max_val = visited[i][j];
			}
		}
	}

	std::cout << max_val;

	return 0;
}
