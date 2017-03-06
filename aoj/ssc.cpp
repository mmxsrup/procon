#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

struct Edge {
    int src, dst; Weight weight;
    Edge(int s, int d, int w) : src(s), dst(d), weight(w) {}
};

vector<int> kosaraju(const Graph &g){
    int n = g.size(), sz = 0; Graph rg(n);
    vector<int> stk, cmp(n, -1), added(n), visited(n), ord(n);
    for(auto &es : g){
        for(auto &e : es) rg[e.dst].eb(e.dst, e.src, e.weight);
        sz += es.size();
    }
    stk.resize(n + sz); sz = 0;
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        int s = 0; stk[s++] = i;
        while(s != 0){
            int v = stk[s-1]; visited[v] = true;
            bool pushed = false;
            for(auto &e : g[v]){
                int dst = e.dst;
                if(!visited[dst]){ stk[s++] = dst; pushed = true; }
            }
            if(pushed) continue;
            int t = stk[s-1];
            if(!added[t]){ added[t] = true; ord[n-++sz] = t; }
            --s;
        }
    }
    int k = 0;
    for(int &u : ord){
        if(cmp[u] != -1) continue;
        int s = 0; stk[s++] = u;
        while(s != 0){
            int v = stk[--s]; cmp[v] = k;
            for(auto &e : rg[v]){
                int d = e.dst;
                if(cmp[d] == -1) stk[s++] = d;
            }
        }
        ++k;
    }
    return cmp;
}

int main(void){
	int n, m; cin >> n >> m;
    Graph g(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        g[a].eb(a, b, 0);
    }
    vector<int> c = kosaraju(g);
    int q; cin >> q;
    rep(i, q){
        int a, b;
        cin >> a >> b;
        if(c[a] == c[b]) cout << '1' << endl;
        else cout << '0' << endl;
    }
    return 0;
}