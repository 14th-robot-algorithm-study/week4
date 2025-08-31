#include <iostream>
#include <queue>
using namespace std;

struct point {
	int y, x;
};

int arr[5][5];
int visited[5][5];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1 ,1 };

void bfs(point st) {
	queue <point> q;
	q.push(st);
	visited[st.y][st.x] = 1;

	while (!q.empty()) {
		point now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) {
				continue;
			}

			if (visited[ny][nx]) {
				continue;
			}

			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny, nx });
		}
	}
}

int main() {
	int y, x;
	std::cin >> y >> x;

	bfs({ y, x });

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cout << visited[i][j] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}
