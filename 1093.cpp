//
// Created by heath on 15-10-30.
//

#include <iostream>

using namespace std;

void print(int weight, int rate, int added) {
    cout << "Weight (" << weight << ") has best price $" <<
    (weight + added) * rate << " (add " << added << " pounds)\n";
}

int main() {
    int weight1, weight2, weight3;
    int rate1, rate2, rate3, rate4;
    int balance_point_1, balance_point_2, balance_point_3;
    int set_count = 0;
    while (cin >> weight1 >> rate1 >> weight2 >> rate2 >> weight3 >> rate3 >>
           rate4) {
        set_count++;
        //价格可能为0
//        balance_point_1 = (weight1 + 1) * rate2 / rate1;
//        balance_point_2 = (weight2 + 1) * rate3 / rate2;
//        balance_point_3 = (weight3 + 1) * rate4 / rate3;

        cout << "Set number " << set_count << ":\n";
        int weight;
        while (cin >> weight && weight) {
            if (weight <= weight1 &&
                weight * rate1 <= (weight1 + 1) * rate2) {
                print(weight, rate1, 0);
            } else if (weight <= weight2 &&
                       weight * rate2 <= (weight2 + 1) * rate3) {
                int added = (weight1 + 1 - weight <= 0) ? 0 : weight1 + 1 -
                                                              weight;
                print(weight, rate2, added);
            } else if (weight <= weight3 &&
                       weight * rate3 <= (weight3 + 1) * rate4) {
                int added = (weight2 + 1 - weight <= 0) ? 0 : weight2 + 1 -
                                                              weight;
                print(weight, rate3, added);
            } else {
                int added = (weight3 + 1 - weight <= 0) ? 0 : weight3 + 1 -
                                                              weight;
                print(weight, rate4, added);
            }
        }
        cout << endl;
    }
}
