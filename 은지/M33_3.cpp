#include <iostream>
using namespace std;

int N;
int parent[5];
int arr[5][5];

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
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}
}

int main() {
	std::cin >> N;
	init();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[i][j] == 0) {
				continue;;
			}

			if (find(i) == find(j)) {
				std::cout << "cycle 발견";
				return 0;
			}

			setUnion(i, j);
		}
	}

	std::cout << "미발견";
	return 0;
}
