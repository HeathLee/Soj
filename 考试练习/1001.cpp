//
// Created by heath on 15-10-30.
//

#include <iostream>

using namespace std;

int main() {
    int result[10001] = {0};
    int count = 0;
    for (int i = 1; i <= 10000; ++i) {
        int a = i;
        int a2 = i * i;
        int mod = 10;
        do {
            if (a % mod == a2 % mod) {
                a /= 10;
                a2 /= 10;
                if (a == 0) {
                    result[count++] = i;
                }
            } else {
                break;
            }
        } while (a > 0);
    }
    int n;
    while (cin >> n) {
        for (int i = 0; i < count; ++i) {
            if (result[i] <= n) {
                cout << result[i] << endl;
            }
        }
    }
}