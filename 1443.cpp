//
// Created by heath on 15-10-3.
//

#include <iostream>
#include <queue>

using namespace std;

int get_hightest_priority(queue<pair<int, int> > print_queue) {
    int priority = 0;

    while (!print_queue.empty()) {
        int front = print_queue.front().first;
        print_queue.pop();
        if (priority < front) priority = front;
    }

    return priority;
}

int main() {
    int case_number, job_number, my_position, priority;
    cin >> case_number;

    while (case_number--) {
        int result = 0;
        queue<pair<int, int> > print_queue;
        cin >> job_number >> my_position;

        for (int i = 0; i < job_number; i++) {
            cin >> priority;
            if (i != my_position)
                print_queue.push(pair<int, int>(priority, 0));
            else
                print_queue.push(pair<int, int>(priority, 1));
        }

        while (print_queue.front().second != 1 ||
               print_queue.front().first !=
               get_hightest_priority(print_queue)) {

            if (print_queue.front().first ==
                get_hightest_priority(print_queue)) {

                result++;
                print_queue.pop();
            } else {
                print_queue.push(pair<int, int>(print_queue.front().first,
                                                print_queue.front().second));
                print_queue.pop();
            }
        }
        cout << ++result << endl;
    }
}
