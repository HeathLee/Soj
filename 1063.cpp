//
// Created by heath on 15-10-5.
//

//时间复杂度太高，还需优化
//相比网上的一般使用二分查找做法，可能较多的时间花费在了map的插入(大雾。。。内存倒是降了，时间反而增加了
//map查找时也是使用二分查找

#include <iostream>
#include <algorithm>

using namespace std;

struct Person {
    int id, salary, height, boss_id, subordinate_number;

    Person() { }

    Person(int id_, int salary_, int height_) {
        id = id_;
        salary = salary_;
        height = height_;
        subordinate_number = 0;
    }
};

bool cmp(Person a, Person b) {
    return a.salary > b.salary;
}

bool cmp2(Person a, Person b) {
    return a.id < b.id;
}

int main() {
    int case_number;
    cin >> case_number;
    while (case_number--) {
        //map<int, int> m;
        int employee_number, query_number;
        cin >> employee_number >> query_number;
        Person p[30000];
        for (int i = 0; i < employee_number; ++i) {
            int id, salary, height;
            cin >> id >> salary >> height;
            p[i] = Person(id, salary, height);
        }

        sort(p, p + employee_number, cmp);

//        for (int k = 0; k < employee_number; ++k) {
//            m[p[k].id] = k;
//        }

        int end = employee_number - 1;
        while (end) {
            int temp = end;
            temp--;
            if (temp <= 0) {
                p[end].boss_id = 0;
            }
            while (p[temp].height < p[end].height) {
                temp--;
            }
            p[temp].subordinate_number += p[end].subordinate_number + 1;
            p[end].boss_id = p[temp].id;
            end--;
        }
        sort(p, p + employee_number, cmp2);
        for (int j = 0; j < query_number; ++j) {
            int id;
            cin >> id;
            int bot = 0, top = employee_number - 1, h;
            while (bot <= top) {
                h = (bot + top) / 2;
                if (p[h].id == id)
                    break;
                else if (p[h].id < id)
                    bot = h + 1;
                else
                    top = h - 1;
            }
//            cout << p[m[id]].boss_id << " "
//                << p[m[id]].subordinate_number << endl;
            cout << p[h].boss_id << " "
            << p[h].subordinate_number << endl;
        }
    }
}
