#include <iostream>
#include <set>
using namespace std;

int N;
int parent[10];
set <int> val;

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
	parent[0] = 0;
	parent[1] = 0;
	parent[2] = 0;

	parent[3] = 3;
	parent[4] = 3;
	parent[5] = 3;

	parent[6] = 6;
	parent[7] = 6;

	parent[8] = 8;
	parent[9] = 8;
}

int main() {
	init();
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		char a, b;
		std::cin >> a >> b;

		int val1 = a - 'A';
		int val2 = b - 'A';

		if (find(val1) != find(val2)) {
			parent[find(val2)] = find(val1);
		}
	}

	for (int i = 0; i < 10; i++) {
		val.insert(find(parent[i]));
	}

	std::cout << val.size() << "개";

	return 0;
}
