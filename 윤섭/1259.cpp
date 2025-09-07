#include <iostream>
#include <string>
using namespace std;

int main() {
    while (true) {
        string num;
        cin >> num;

        if (num == "0") break;

        int flag = 0;

        for (int i = 0; i < num.size() / 2; i++) {
            if (num[i] != num[num.size() - i - 1]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
}
