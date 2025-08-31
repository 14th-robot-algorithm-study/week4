#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
	int num;
	int cost;
};

struct cmp {
	bool operator()(Edge a, Edge b) {
		return a.cost > b.cost;
	}
};
int N, M, P;
vector <Edge> v1[1'001];
vector <Edge> v2[1'001];

int visited1[1'001];
int visited2[1'001];

int res1[1'001];
int res2[1'001];

int total[1'001];
int max_val = 0;

void dijkstra(int st) {
	priority_queue <Edge, vector<Edge>, cmp> pq;
	pq.push({ st, 0 });
	visited1[st] = 0;

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();
		for (int i = 0; i < v1[now.num].size(); i++) {
			int next = v1[now.num][i].num;

			int nextCost = v1[now.num][i].cost + now.cost;
			if (visited1[next] > nextCost) {
				visited1[next] = nextCost;
				pq.push({ next, nextCost });
			}
		}
	}
}

void redijkstra(int st) {
	priority_queue <Edge, vector<Edge>, cmp> pq;
	pq.push({ st, 0 });
	visited2[st] = 0;

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();
		for (int i = 0; i < v2[now.num].size(); i++) {
			int next = v2[now.num][i].num;

			int nextCost = v2[now.num][i].cost + now.cost;
			if (visited2[next] > nextCost) {
				visited2[next] = nextCost;
				pq.push({ next, nextCost });
			}
		}
	}
}

int main() {
	std::cin >> N >> M >> P;
	for (int i = 0; i < M; i++) {
		int a, b, cost;
		std::cin >> a >> b >> cost;
		v1[a].push_back({ b, cost });
		v2[b].push_back({ a, cost });
	}

	for (int i = 1; i < N + 1; i++) {
		fill(visited1, visited1 + 1'001, 21e8);
		fill(visited2, visited2 + 1'001, 21e8);
		if (i == P) {
			continue;
		}

		dijkstra(i);
		redijkstra(i);
		res1[i] = visited1[P];
		res2[i] = visited2[P];
	}

	for (int i = 1; i < N + 1; i++) {
		total[i] = res1[i] + res2[i];
		if (max_val < total[i]) {
			max_val = total[i];
		}
	}

	std::cout << max_val;

	return 0;
}
