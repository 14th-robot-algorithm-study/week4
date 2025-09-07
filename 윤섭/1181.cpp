#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string word[20000];

bool compare(const string& a, const string& b) {
	if (a.size() != b.size()) {
		return a.size() < b.size();
	}
	return a < b;
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> word[i];
	}
	
	sort(word, word + N, compare);

	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (word[i] != word[cnt - 1]) {
			word[cnt] = word[i];
			cnt++;
		}
	}

	for (int i = 0; i < cnt; i++) {
		cout << word[i] << "\n";
	}
}
