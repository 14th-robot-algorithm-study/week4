#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    unordered_set<int> s;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        if (s.find(x) != s.end()) {
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
    }
}
