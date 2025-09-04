#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

int T, N, M;
int parent[101];
vector <int> v[101];
set <int> s;

int find(int tar) {
	if (tar == parent[tar]) {
		return tar;
	}

	return parent[tar] = find(parent[tar]);
}


void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2) {
		return;
	}

	parent[t2] = t1;
}


void init() {
	s.clear();
	memset(v, 0, sizeof(v));
	memset(parent, 0, sizeof(parent));

	std::cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int from, to;
		std::cin >> from >> to;

		v[from].push_back(to);		
	}


	for (int i = 0; i < N + 1; i++) {
		parent[i] = i;
	}

}


int main() {
	std::cin >> T;

	for (int i = 1; i < T + 1; i++) {
		init();

		for (int i = 1; i < N + 1; i++) {
			if (v[i].size() == 0) {
				continue;
			}

			for (int j = 0; j < v[i].size(); j++) {
				setUnion(i, v[i][j]);
			}
		}

		for (int i = 1; i < N + 1; i++) {
			if (find(parent[i]) != 0) {
				s.insert(find(parent[i]));
			}
		}

		std::cout << "#" << i << " " << s.size() << "\n";

	}

	return 0;
}
