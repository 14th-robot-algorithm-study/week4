#include <iostream>
#include <string>
using namespace std;

bool isVPS(const string& s) {
    int cnt = 0;
    for (char c : s) {
        if (c == '(') cnt++;
        else cnt--;
        if (cnt < 0) return false;
    }
    return cnt == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << (isVPS(s) ? "YES\n" : "NO\n");
    }
}
