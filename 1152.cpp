//
// Created by heath on 15-10-5.
//

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int ROW = 5;
int COL = 6;

bool visited[31];

struct Horse {
    int x, y;

    Horse() { }

    Horse(int start) {
        x = (start - 1) / COL + 1;
        y = (start - 1) % COL + 1;
    }

    vector<int> get_valid_location() {
        vector<int> result;
        if (x - 2 >= 1 && y - 1 >= 1 && !visited[(x - 2 - 1) * COL + y - 1]) {
            result.push_back((x - 2 - 1) * COL + y - 1);
        }
        if (x - 2 >= 1 && y + 1 <= COL && !visited[(x - 2 - 1) * COL + y + 1]) {
            result.push_back((x - 2 - 1) * COL + y + 1);
        }
        if (x - 1 >= 1 && y - 2 >= 1 && !visited[(x - 1 - 1) * COL + y - 2]) {
            result.push_back((x - 1 - 1) * COL + y - 2);
        }
        if (x - 1 >= 1 && y + 2 <= COL && !visited[(x - 1 - 1) * COL + y + 2]) {
            result.push_back((x - 1 - 1) * COL + y + 2);
        }
        if (x + 1 <= ROW && y - 2 >= 1 && !visited[(x + 1 - 1) * COL + y - 2]) {
            result.push_back((x + 1 - 1) * COL + y - 2);
        }
        if (x + 1 <= ROW && y + 2 <= COL &&
            !visited[(x + 1 - 1) * COL + y + 2]) {
            result.push_back((x + 1 - 1) * COL + y + 2);
        }
        if (x + 2 <= ROW && y - 1 >= 1 && !visited[(x + 2 - 1) * COL + y - 1]) {
            result.push_back((x + 2 - 1) * COL + y - 1);
        }
        if (x + 2 <= ROW && y + 1 <= COL &&
            !visited[(x + 2 - 1) * COL + y + 1]) {
            result.push_back((x + 2 - 1) * COL + y + 1);
        }
        return result;
    }
};

int result[30];
bool stop = false;

void DFS(int location, int count) {
    if (count == ROW * COL) {
        stop = true;
        return;
    }
    vector<int> v = Horse(location).get_valid_location();
    for (int i = 0; i < v.size(); ++i) {
        if (!visited[v[i]]) {
            visited[v[i]] = true;
            result[count] = v[i];
            DFS(v[i], count + 1);
        }
    }
    if (!stop) {
        visited[location] = false;
    }
}

int main() {
    int start;
    while (cin >> start && start != -1) {
        memset(visited, false, sizeof(visited));
        memset(result, 0, sizeof(result));
        visited[start] = true;
        result[0] = start;
        stop = false;
        DFS(start, 1);
        for (int i = 0; i < ROW * COL - 1; ++i) {
            cout << result[i] << " ";
        }
        cout << result[ROW * COL - 1] << endl;
    }
}

