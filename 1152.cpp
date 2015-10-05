//
// Created by heath on 15-10-5.
//

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

bool visited[31];

struct Horse {
    int x, y;

    Horse() { }

    Horse(int start) {
        x = (start - 1) / 6 + 1;
        y = (start - 1) % 6 + 1;
    }

    vector<int> get_valid_location() {
        vector<int> result;
        if (x - 2 >= 1 && y - 1 >= 1 && !visited[(x - 2 - 1) * 6 + y - 1]) {
            result.push_back((x - 2 - 1) * 6 + y - 1);
        }
        if (x - 2 >= 1 && y + 1 <= 6 && !visited[(x - 2 - 1) * 6 + y + 1]) {
            result.push_back((x - 2 - 1) * 6 + y + 1);
        }
        if (x - 1 >= 1 && y - 2 >= 1 && !visited[(x - 1 - 1) * 6 + y - 2]) {
            result.push_back((x - 1 - 1) * 6 + y - 2);
        }
        if (x - 1 >= 1 && y + 2 <= 6 && !visited[(x - 1 - 1) * 6 + y + 2]) {
            result.push_back((x - 1 - 1) * 6 + y + 2);
        }
        if (x + 1 <= 5 && y - 2 >= 1 && !visited[(x + 1 - 1) * 6 + y - 2]) {
            result.push_back((x + 1 - 1) * 6 + y - 2);
        }
        if (x + 1 <= 5 && y + 2 <= 6 && !visited[(x + 1 - 1) * 6 + y + 2]) {
            result.push_back((x + 1 - 1) * 6 + y + 2);
        }
        if (x + 2 <= 5 && y - 1 >= 1 && !visited[(x + 2 - 1) * 6 + y - 1]) {
            result.push_back((x + 2 - 1) * 6 + y - 1);
        }
        if (x + 2 <= 5 && y + 1 <= 6 && !visited[(x + 2 - 1) * 6 + y + 1]) {
            result.push_back((x + 2 - 1) * 6 + y + 1);
        }
        return result;
    }
};

int result[30];
bool stop = false;

void DFS(int location, int count) {
    if (count == 30) {
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
        for (int i = 0; i < 29; ++i) {
            cout << result[i] << " ";
        }
        cout << result[29] << endl;
    }
}

