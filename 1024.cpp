//
// Created by heath on 15-10-5.
//

//c的输入流scanf要比cin快很多

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

struct Route {
    int dest;
    int distance;

    Route() { }

    Route(int dest_, int distance_) {
        dest = dest_;
        distance = distance_;
    }
};

vector<Route> v[10001];
bool vistited[10001];
int max_dist = 0;

void DFS(int captial, int dist) {
    bool flag = false;
    for (int i = 0; i < v[captial].size(); ++i) {
        if (!vistited[v[captial][i].dest]) {
            vistited[v[captial][i].dest] = true;
            flag = true;
            DFS(v[captial][i].dest, dist + v[captial][i].distance);
        }
    }
//    for (vector<Route>::iterator it = v[captial].begin(); it != v[captial].end();
//          it++ ) {
//        if (!vistited[it->dest] ) {
//            vistited[it->dest] = true;
//            flag = true;
//            DFS(it->dest, dist + it->distance );
//        }
//    }
    v[captial].clear();
    if (!flag && dist > max_dist) {
        max_dist = dist;
    }
}

int main() {
    int route_number, capital;
    int orginal, dest, dist;
    while (scanf("%d%d", &route_number, &capital) != EOF) {
        memset(vistited, false, sizeof(vistited));
        for (int i = 0; i < route_number - 1; ++i) {
            //cin >> orginal >> dest >> dist;
            scanf("%d%d%d", &orginal, &dest, &dist);
            v[orginal].push_back(Route(dest, dist));
            v[dest].push_back(Route(orginal, dist));
        }
        max_dist = 0;
        vistited[capital] = true;
        DFS(capital, 0);
        printf("%d\n", max_dist);
        // cout << max_dist << endl;
    }
}

