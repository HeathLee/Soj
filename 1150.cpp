//
// Created by heath on 15-10-1.
//

#include <iostream>
#include <queue>
#include <string>

using namespace std;

class MoBan {
private:
    int x;
    int y;
    string op;

public:
    MoBan(int x, int y, string s="") {
        this->x = x;
        this->y = y;
        op = s;
    }

    MoBan A() {
        MoBan m = MoBan(this->y, this->x, op + "A");
        return m;
    }

    MoBan B() {
        int temp_x, temp_y;
        temp_x = x % 10 * 1000 + x / 10;
        temp_y = y % 10 * 1000 + y / 10;
        MoBan m = MoBan(temp_x, temp_y, op + "B");
        return m;
    }

    MoBan C() {
        int x1, x2, x3, x4, y1, y2, y3, y4, temp_x, temp_y;
        x1 = x / 1000;
        x2 = x % 1000 / 100;
        x3 = x % 100 / 10;
        x4 = x % 10;

        y1 = y / 1000;
        y2 = y % 1000 / 100;
        y3 = y % 100 / 10;
        y4 = y % 10;

        temp_x = x1 * 1000 + y2 * 100 + x2 * 10 + x4;
        temp_y = y1 * 1000 + y3 * 100 + x3 * 10 + y4;
        MoBan m = MoBan(temp_x, temp_y, op + "C");
        return m;
    }

    int get_x() {
        return x;
    }

    int get_y() {
        return  y;
    }

    string get_op() {
        return op;
    }

    bool operator == (MoBan m) {
        return x == m.get_x() && y == m.get_y();
    }


    int get_count() {
        return op.length();
    }
};


int main() {
    int m;
    MoBan init = MoBan(1234, 8765);
    int x[4], y[4];
    while (cin >> m && m != -1) {
        for (int i = 0; i < 4; ++i) {
            cin >> x[i];
        }
        for (int j = 0; j < 4; ++j) {
            cin >> y[j];
        }

        int temp_x = x[0] * 1000 + x[1] * 100 + x[2] * 10 + x[3];
        int temp_y = y[0] * 1000 + y[1] * 100 + y[2] * 10 + y[3];
        MoBan result = MoBan(temp_x, temp_y);

        queue<MoBan> q;
        q.push(init);
        while (!q.empty()) {
            if (q.front() == result) {
                cout << q.front().get_count() << " " << q.front().get_op() << endl;
                break;
            } else {
                q.push(q.front().A());
                q.push(q.front().B());
                q.push(q.front().C());
                q.pop();
            }
            if (q.front().get_count() > m) {
                cout << -1 << endl;
                break;
            }
        }
    }
}
