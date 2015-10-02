//
// Created by heath on 15-10-1.
//

#include <iostream>
#include <queue>
#include <string>
#include <set>

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

    int get_x() const{
        return x;
    }

    int get_y() const{
        return  y;
    }

    string get_op() const{
        return op;
    }

    bool operator == (MoBan m) {
        return x == m.get_x() && y == m.get_y();
    }

    int get_count() const {
        return op.length();
    }
};

MoBan A(const MoBan &b) {
    int x = b.get_x();
    int y = b.get_y();
    int temp_x1 = x / 100;
    int temp_x2 = x % 100;
    int temp_y1 = y / 100;
    int temp_y2 = y % 100;

    MoBan m = MoBan(temp_x2 * 100 + temp_x1, temp_y2 * 100 + temp_y1,
                    b.get_op() + "A");
    return m;
}

MoBan B(const MoBan &b) {
    int temp_x, temp_y;
    int x= b.get_x();
    int y = b.get_y();
    temp_x = x / 1000 + x % 1000 * 10;
    temp_y = y / 1000 + y % 1000 * 10;
    MoBan m = MoBan(temp_x, temp_y, b.get_op() + "B");
    return m;
}

MoBan C(const MoBan &b) {
    int x1, x2, x3, x4, y1, y2, y3, y4, temp_x, temp_y;
    int x= b.get_x();
    int y = b.get_y();
    x1 = x / 1000;
    x2 = x % 1000 / 100;
    x3 = x % 100 / 10;
    x4 = x % 10;

    y1 = y / 1000;
    y2 = y % 1000 / 100;
    y3 = y % 100 / 10;
    y4 = y % 10;

    temp_x = x1 * 1000 + x3 * 100 + y3 * 10 + x4;
    temp_y = y1 * 1000 + x2 * 100 + y2 * 10 + y4;
    MoBan m = MoBan(temp_x, temp_y, b.get_op() + "C");
    return m;
}

int main() {
    int step;
    MoBan init = MoBan(1234, 5678);
    int x[4], y[4];
    while (cin >> step && step != -1) {
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
        set<int> s;
        q.push(init);
        s.insert(init.get_x()*10000+init.get_y());
        while (!q.empty()) {
            MoBan mb = q.front();
            if (mb == result) {
                cout << mb.get_count() << " " << mb.get_op() << endl;
                break;
            } else {
                MoBan temp = A(mb);
                if (s.find(temp.get_x()*10000 + temp.get_y()) == s.end()) {
                    q.push(temp);
                    s.insert(temp.get_x()*10000 + temp.get_y());
                }
                temp = B(mb);
                if (s.find(temp.get_x()*10000 + temp.get_y()) == s.end()) {
                    q.push(temp);
                    s.insert(temp.get_x()*10000 + temp.get_y());
                }
                temp = C(mb);
                if (s.find(temp.get_x()*10000 + temp.get_y()) == s.end()) {
                    q.push(temp);
                    s.insert(temp.get_x()*10000 + temp.get_y());
                }
                q.pop();
            }
            if (mb.get_count() > step) {
                cout << -1 << endl;
                break;
            }
        }
    }
}
