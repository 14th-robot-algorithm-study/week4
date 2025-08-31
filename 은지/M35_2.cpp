#include <iostream>
#include <queue>
using namespace std;

struct Point {
	int y, x;
	int cost;
};

int N;
Point st;
int MAP[10][10] = {};

struct cmp {
	bool operator()(Point a, Point b) {
		return a.cost < b.cost;
	}
};

priority_queue <Point, vector<Point>, cmp> q;

void HEAP() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (MAP[i][j] == 0) {
				continue;
			}

			q.push({ i, j, MAP[i][j] });
		}
	}
}



void init() {
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> MAP[i][j];
		}
	}
}

int main() {
	init();
	HEAP();

	for (int i = 0; i < 3; i++) {
		Point sp = q.top();
		q.pop();

		std::cout << (char)('A' + sp.y) << "-" << (char)('A' + sp.x) << " " << sp.cost << "\n";
	}
	return 0;
}
