//
// Created by heath on 15-11-17.
//

#include <algorithm>
#include <iostream>

using namespace std;

struct kid {
    int has;
    int wants;

    kid(int has, int wants) {
        this->has = has;
        this->wants = wants;
    }

    kid() { }
};

bool cmp(kid a, kid b) {
    if (a.wants < b.wants) {
        return true;
    } else if (a.wants == b.wants && a.has >= b.has) {
        return true;
    }
    return false;
}

int main() {
    int kid_number, toy_number;
    kid kids[10001];
    while (cin >> kid_number >> toy_number && kid_number) {
        int has, wants;
        for (int i = 0; i < kid_number; ++i) {
            cin >> has >> wants;
            kids[i] = kid(has, wants);
        }
        bool complete = true;
        sort(kids, kids + kid_number, cmp);
        for (int j = 0; j < kid_number; ++j) {
            if (toy_number >= kids[j].wants) {
                toy_number += kids[j].has;
            } else {
                cout << "NO\n";
                complete = false;
                break;
            }
        }
        if (complete) {
            cout << "YES\n";
        }
    }
}