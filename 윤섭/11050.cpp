#include <iostream>
using namespace std;

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++)
        result *= i;
    return result;
}

int main() {
    int N, K;
    cin >> N >> K;

    int ans = factorial(N) / (factorial(K) * factorial(N - K));
    cout << ans << "\n";

    return 0;
}
