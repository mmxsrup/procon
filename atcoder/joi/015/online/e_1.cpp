#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
int N, M, K, S, P, Q, a, b, d1[111111], z[111111]; long long d2[111111]; vector<int> G[111111];
int main() {
    scanf("%d%d%d%d%d%d", &N, &M, &K, &S, &P, &Q);
    queue<int> que1;
    fill(d1, d1 + N, -1);
    for (int i = 0; i < K; i++) {
        scanf("%d", &a); a--; z[a] = 1;
        d1[a] = 0, que1.push(a);
    }
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &a, &b); a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    while (!que1.empty()) {
        int v = que1.front(); que1.pop();
        for (auto &e : G[v]) {
            if (d1[e] == -1) d1[e] = d1[v] + 1, que1.push(e);
        }
    }
    rep(i, N) printf("%d\n", d1[i]);
    /*
    rep(i, N){
        for(auto v : G[i]) printf("%d -> %d %d\n", i, v.first, v.second);
    }
    */
    priority_queue<pair<long long, int> > que2; que2.push(make_pair(0, 0));
    fill(d2 + 1, d2 + N, 1LL << 60);
    while (!que2.empty()) {
        int v = que2.top().second; que2.pop();
        for (auto &e : G[v]) {
            if (z[e]) continue;
            long long f = d2[v] + (d1[e] <= S ? Q : P);
            if (d2[e] > f) d2[e] = f, que2.push(make_pair(-d2[e], e));
        }
    }
    cout << d2[N - 1] - (d1[N - 1] <= S ? Q : P) << endl;
    return 0;
}