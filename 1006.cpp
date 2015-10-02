//
// Created by heath on 15-10-2.
//

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int number_of_each_set, len = 5;
    string input_set[100];
    while (cin >> number_of_each_set && number_of_each_set) {
        string result;
        for (int i = 0; i < number_of_each_set; ++i) {
            cin >> input_set[i];
        }
        char next[] = "ABCDE";
        int min = 9999;
        map<char, int> m;
        do {
            for (int k = 0; k < len; ++k) {
                m[next[k]] = k;
            }
            int count = 0;
            for (int i = 0; i < number_of_each_set; ++i) {
                for (int j = 0; j < len; ++j) {
                    for (int l = j + 1; l < len; ++l) {
                        //map用于查找输入集合中第i个string的字符在当前排列组合产生的
                        //string中的位置
                        if (m[input_set[i][j]] > m[input_set[i][l]]) {
                            count++;
                        }
                    }
                }
            }
            if (count < min) {
                min = count;
                result = next;
            }
        } while (next_permutation(next, next + 5));
        cout << result << " is the median ranking with value " << min << "." << endl;
    }
}