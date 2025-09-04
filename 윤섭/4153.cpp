#include <iostream>
using namespace  std;

int main() {
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0) break;
		int A = a * a;
		int B = b * b;
		int C = c * c;

		if (A + B == C || B + C == A || C + A == B) {
			cout << "right" << "\n";
		}
		else {
			cout << "wrong" << "\n";
		}
	}
}
