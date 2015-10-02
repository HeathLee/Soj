//
// Created by heath on 15-9-26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Period {
private:
    double avg_planes;
    int start;
    int end;

public:
    Period(int start, int end) {
        this->start = start;
        this->end = end;
    }

    int get_start() const {
        return start;
    }

    int get_end() const {
        return end;
    }

    double get_avg_planes() const {
        return avg_planes;
    }

    int get_length() const{
        return end- start + 1;
    }

    void set_avg_planes(double avg) {
        avg_planes = avg;
    }
};

bool cmp(const Period* a, const Period* b) {
    if (a->get_avg_planes() > b->get_avg_planes())
        return true;
    if (a->get_avg_planes() < b->get_avg_planes())
        return false;
    if (a->get_length() > b->get_length())
        return true;
    if (a->get_length() < b->get_length())
        return false;
    if (a->get_end() < b->get_end())
        return true;
    return  false;
}

int main() {
    int case_number;
    cin >> case_number;
    for (int i = 1; i <= case_number; ++i) {
        int quarters, request_periods, min_quarters;
        int quarters_arr[300] = {0};
        cin >> quarters >> request_periods >> min_quarters;
        for (int j = 0; j < quarters; ++j) {
            cin >> quarters_arr[j];
        }

        vector<Period*> p;
        int period_length = min_quarters;
        for (; period_length <= quarters; ++period_length) {
            for (int j = 0; j <= quarters - period_length; ++j) {
                Period* temp = new Period(j, j + period_length - 1);
                int sum = 0;
                for (int l = j; l < j + period_length; ++l) {
                    sum += quarters_arr[l];
                }
                temp->set_avg_planes(sum / (double)period_length);
                p.push_back(temp);
            }
        }

        sort(p.begin(), p.end(), cmp);

        cout << "Result for run " << i << ":" << endl;
        int count = 0;
        vector<Period *>::iterator iterator = p.begin();
        while (iterator != p.end() && count < request_periods) {
            cout << (*iterator)->get_start() + 1
            << "-" << (*iterator)->get_end() + 1 << endl;
            iterator++;
            count++;
        }
    }
}
