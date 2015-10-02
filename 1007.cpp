//
// Created by heath on 15-10-2.
//
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main() {
    int col;
    while (cin >> col && col) {
        char input[100][20];
        string temp;
        cin >> temp;
        int row = 0;
        for (int n = 0; n < temp.length();) {
            if (row % 2 == 0) {
                for (int i = 0; i < col; ++i) {
                    input[row][i] = temp.at(n++);
                }
            } else {
                for (int i = col - 1; i >= 0; --i) {
                    input[row][i] = temp.at(n++);
                }
            }
            ++row;
        }
        for (int j = 0; j < col; ++j) {
            for (int i = 0; i < row; ++i) {
                cout << input[i][j];
            }
        }
        cout << endl;
    }
}
