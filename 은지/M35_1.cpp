#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(char a, char b) {
	return a > b;
}

int main() {
	string str;
	std::cin >> str;

	sort(str.begin(), str.end(), cmp);

	std::cout << str;

	return 0;
}
