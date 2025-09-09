#include <iostream>
#include <string>
using namespace std;

int main() {
	int A, B, C, res;
	string a, b, c;

	std::cin >> a >> b >> c;

	A = stoi(a);
	B = stoi(b);
	C = stoi(c);

	res = stoi(a + b) - stoi(c);

	std::cout << A + B - C << "\n";
	std::cout << res;

	return 0;
}
