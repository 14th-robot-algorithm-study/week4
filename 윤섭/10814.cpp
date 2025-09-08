#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct person {
	int age;
	string name;
};

person people[100000];

bool compare(const person &a, const person &b) {
	return a.age < b.age;
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> people[i].age >> people[i].name;
	}

	stable_sort(people, people + N, compare);

	for (int i = 0; i < N; i++) {
		cout << people[i].age << " " << people[i].name << "\n";
	}
}
