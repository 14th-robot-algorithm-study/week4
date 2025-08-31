#include <iostream>
#include <string>
using namespace std;

int N, K;
int parent[21];
char grade[21];

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
	std::cin >> N >> K;
	for (int i = 0; i < K + 1; i++) {
		parent[i] = i;
		grade[i]  = '?';
	}
}

int main() {
	init();

	for (int i = 0; i < N; i++) {
		string a, b;
		std::cin >> a >> b;

		if (isdigit(a[0]) && isdigit(b[0])) {
			int num1 = stoi(a);
			int num2 = stoi(b);

			setUnion(num1, num2);
		}
		
		else if (isdigit(a[0]) && isalpha(b[0])) {
			int num = stoi(a);
			grade[num] = b[0];

			for (int i = 0; i < K + 1; i++) {
				if (find(i) == find(num)) {
					grade[i] = b[0];
				}
			}
		}
		
		else if (isalpha(a[0]) && isdigit(b[0])) {
			int num = stoi(b);
			grade[num] = a[0];

			for (int i = 0; i < K + 1; i++) {
				if (find(i) == find(num)) {
					grade[i] = a[0];
				}
			}
		}
	}

	for (int i = 1; i < K + 1; i++) {
		std::cout << grade[i];
	}
	return 0;
}
