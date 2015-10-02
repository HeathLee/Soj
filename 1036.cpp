//
// Created by heath on 15-10-2.
//
#include <iostream>
#include <set>

using namespace std;

int main() {
    string keyword;

    while (cin >> keyword && keyword != "THEEND") {
        set<pair<char, int> > s;
        for (int i = 0; i < keyword.length(); ++i) {
            s.insert(make_pair(keyword.at(i), i));
        }
        string ciphertext;
        char original[10][10];
        cin >> ciphertext;
        int col = keyword.length();
        int row = ciphertext.length() / col;
        set<pair<char, int> >::iterator iterator1 = s.begin();
        int count = 0;
        for (; iterator1 != s.end(); ++iterator1) {
            for (int i = 0; i < row; ++i) {
                original[i][(*iterator1).second] = ciphertext.at(count++);
            }
        }
        for (int j = 0; j < row; ++j) {
            for (int i = 0; i < col; ++i) {
                cout << original[j][i];
            }
        }
        cout << endl;
    }
}