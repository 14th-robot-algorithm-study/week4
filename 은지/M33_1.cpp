#include <iostream>

int parent[4];

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
	for (int i = 0; i < 4; i++) {
		parent[i] = i;
	}
}

int main() {
	init();

	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		char a, b;
		std::cin >> a >> b;

		int val1 = a - 'A';
		int val2 = b - 'A';

		if (find(val1) == find(val2)) {
			std::cout << "발견";
			return 0;
		}
		setUnion(val1, val2);
	}

	std::cout << "미발견";

	return 0;
}
