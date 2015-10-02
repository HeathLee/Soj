//
// Created by heath on 15-9-26.
//

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int array[1100];
int d[1100][1100];

int dp(int a, int b) {
    if(d[a][b] != -1)
        return d[a][b];

    if (a > b)
        return 0;

    int left_sum = array[a] + (array[a + 1] >= array[b] ?
                               dp(a + 2, b) : dp(a + 1, b - 1));
    int right_sum = array[b] + (array[a] >= array[b - 1] ?
                                dp(a + 1, b - 1) : dp(a, b - 2));
    d[a][b] = max(left_sum, right_sum);
    return d[a][b];
}

int main() {
    int n;
    int count = 1;
    while (cin >> n && n) {
        memset(d, -1, sizeof(d));
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> array[i];
            sum += array[i];
        }
        int result = 2 * dp(0, n - 1) - sum;
        cout << "In game " << count++ << ", "
        << "the greedy strategy might lose by as many as " << result
        << " points." << endl;
    }
}
