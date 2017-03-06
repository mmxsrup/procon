/*
 * No.20 砂漠のオアシス
 *
 * 解法)
 * 次の町へ行くためにはオアシスを通らないで行く方法と, オアシスを通って回復してから向かう方法がある.
 * そこでDijkstra法で次の町とオアシスへ行くための最小コストを求める. 次の町へ行くためのコストがVより小さいのなら,
 * 判定は真.
 * いけなかったのならば, オアシスを始点とするDijkstra法を用いて体力が足りるか判定する.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct State {
    int cost, x, y;

    bool operator>(const State& s) const {
        return cost > s.cost;
    }
};

const int kINF = 1 << 25;
const int kMAX_N = 210;

int N, V, Ox, Oy;
int L[kMAX_N][kMAX_N];

int cost[kMAX_N][kMAX_N];

int dx[] = {1, 0, -1, 0},
    dy[] = {0, 1, 0, -1};

void Dijkstra(int x, int y) {
    priority_queue<State, vector<State>, greater<State> > que;
    fill((int* )cost, (int* )(cost + kMAX_N), kINF);

    cost[x][y] = 0;
    que.push((State){0, x, y});
    while (!que.empty()) {
        State s = que.top(); que.pop();
        printf("%d %d %d\n", s.y, s.x, s.cost);
        if (cost[s.x][s.y] < s.cost) continue;

        for (int i = 0; i < 4; i++) {
            int nx = s.x + dx[i], ny = s.y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && cost[nx][ny] > s.cost + L[nx][ny]) {
                cost[nx][ny] = s.cost + L[nx][ny];
                que.push((State){s.cost + L[nx][ny], nx, ny});
            }
        }
    }
}

void Solve() {
    Dijkstra(0, 0);
    if (cost[N - 1][N - 1] < V) {
        cout << "YES" << endl;
        return;
    }
    if ((Ox == 0 && Oy == 0) || cost[Ox - 1][Oy - 1] >= V) {
        cout << "NO" << endl;
        return;
    }
    int to_oasis = cost[Ox - 1][Oy - 1];
    Dijkstra(Ox - 1, Oy - 1);

    int from_oasis = cost[N - 1][N - 1];
    if (from_oasis < (V - to_oasis) * 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    cin >> N >> V >> Ox >> Oy;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> L[x][y];
        }
    }

    Solve();

    return 0;
}
