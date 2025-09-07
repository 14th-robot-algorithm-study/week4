#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    int s, m, l, xl, xxl, xxxl;
    cin >> s >> m >> l >> xl >> xxl >> xxxl;
    int T, P;
    cin >> T >> P;

    int sizes[6] = { s, m, l, xl, xxl, xxxl };
    int total_bundles = 0;
    for (int i = 0; i < 6; ++i) {
        int cnt = sizes[i];
        total_bundles += (cnt + T - 1) / T; 
    }

    int pen_bundles = N / P;        
    int single_pens = N - pen_bundles * P; 

    cout << total_bundles << '\n';
    cout << pen_bundles << " " << single_pens << '\n';
}
