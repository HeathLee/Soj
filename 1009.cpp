//
// Created by heath on 15-10-2.
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<long long> result;

void get_prime(long long input) {
    long long upper = pow(input, 0.5);
    bool can_divided = false;
    for (int i = 2; i <= upper; ++i) {
        if (input % i == 0) {
            can_divided = true;
            get_prime(i);
            get_prime(input / i);
            break;
        }
    }
    if (!can_divided) {
        result.push_back(input);
    }
}

int main() {
    int prime_list[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
                        53, 59, 61};
    int k;
    cin >> k;
    for (int i = 0; i < 18 && prime_list[i] < k; ++i) {
        result.clear();
        get_prime((long long) (pow(2, prime_list[i]) - 1));
        if (result.size() > 1) {
            for (int j = 0; j < result.size() - 1; ++j) {
                cout << result[j] << " * ";
            }
            cout << result[result.size() - 1] << " = "
            << (long long) (pow(2, prime_list[i]) - 1)
            << " = ( 2 ^ " << prime_list[i] << " ) - 1" << endl;
        }
    }
}
