//
// Created by heath on 15-9-26.
//
#include <iostream>
#include <string>
#include <set>

using namespace std;

string input[8];
int length;
set<string> result;

void swap (string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

void full_permutation(int start) {
    if (start == length) {
        string str = "";
        for (int i = 0; i < length; ++i) {
            str += input[i];
        }
        result.insert(str);
    } else {
        for (int i = start; i < length; ++i) {
            swap(input[start], input[i]);
            full_permutation(start + 1);
            swap(input[start], input[i]);
        }
    }
}

int main() {
    int case_number;
    cin >> case_number;
    while (case_number--) {
        cin >> length;
        for (int i = 0; i < length; ++i) {
            cin >> input[i];
        }
        full_permutation(0);
        cout << (*result.begin()) << endl;
        result.clear();
    }
}
