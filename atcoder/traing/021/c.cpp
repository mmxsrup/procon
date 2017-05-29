#pragma GCC optimize "O3"
#pragma GCC target "avx"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=n-1;i>=(0);i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define eall(v) unique(all(v), v.end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;


int N, M;
vector<pair<int, int>> G[100010]; // G[i] := i->j color
//dist[i<<32+j] := 頂点iへ路線 jでつくときのコストの最小値
unordered_map<uint64_t, int> dist;
using PP = pair<int, pair<int, int>>;

uint64_t func(uint64_t x, uint32_t y) {
    uint64_t ret = x << 32 + y;
    ret += y;
    // cout << x << " " << y << " " << ret << endl;
    return ret;
}

void dijkstra(int start){
    priority_queue<PP, vector<PP>, greater<PP>> que; // コスト 位置 路線
    // dist[start][-1] = 0;
    dist[func(start, -1)] = 0;
    que.push(mp(0, mp(start, -1)));
    
    while(!que.empty()){
        auto tm = que.top(); que.pop();
       	int cost = tm.fi, u = tm.se.fi, color = tm.se.se;
        // printf("%d %d %d\n", cost, u, color);
        if(dist[func(u, color)] < cost) continue; // これでTLE回避してください
        if(u == N - 1) break;
        for(auto tm : G[u]){
            int v = tm.fi, nc = tm.se; // u->v nc
            int ncost = cost + ((nc == color) ? 0 : 1);
            if(dist.find(func(v, nc)) == dist.end() || dist[func(v, nc)] > ncost){
                dist[func(v, nc)] = ncost;
                que.push(mp(ncost, mp(v, nc)));
            }
        }
    }
}

int main(void){
	scanf("%d %d", &N, &M);
	rep(i, M){
		int p, q, c; scanf("%d %d %d", &p, &q, &c);
		p--, q--;
		G[p].emplace_back(mp(q, c)), G[q].emplace_back(mp(p, c));
	}
	dijkstra(0);
	int mi = INF;

	rep(i, 100001){
        if(dist.find(func(N - 1, i)) != dist.end()){
            // printf("%d\n", dist[func(N - 1, i)]);
            chmin(mi, dist[func(N - 1, i)]);
        }
    }
    if(mi != INF) printf("%d\n", mi);
    else printf("-1\n");
	return 0;
}