#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<pint> vpint;
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

const int INF = 1e9;
const int MAX_N = 100010;
int n, k; //町の数 最大数 
vector<pair<int, int> > G[MAX_N];//グラフを表す隣接リスト fi:to se:cost
int d[MAX_N]; //sからの最短経路
typedef pair<int, int> P;//firstは最短距離,secondは頂点の番号

void dijkstra(void){
    priority_queue<P, vector<P>, greater<P> > que;//firstが小さい順に
    rep(i, n)d[i] = INF;//初期化
    d[0] = 0; que.push(P(0, 0));
    while(!que.empty()){
        auto p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(auto e : G[v]){//e.fi:隣接している頂点の番号 e.se:その頂点までのコスト
            if(d[e.first] > d[v] + e.second){//最短距離が更新されるとき
                d[e.first] = d[v] + e.second;
                que.push(make_pair(d[e.first], e.first));
            }
        }
    }
}

int a[100010];
int ans = 0;
int main(void){
    cin >> n >> k;
    rep(i, n){
        cin >> a[i]; a[i]--;
        if(i == 0 && a[i] != 0) ans++;
        if(i == 0)continue;
        G[a[i]].push_back(make_pair(i, 1)); G[i].push_back(make_pair(a[i], 1));
    }
    dijkstra();//0から他の町への最小値を出す
    vector<int> no;
    rep(i, n){
        if(d[i] > k){
            no.push_back(d[i] - k + 1);
        }
    }
    if(no.size()) ans++;
    all(no);
    bool flag;
    while(flag){
        rep(i, no.size()){
            if(no[i] > k){
                flag = true;
                no[i]--;
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}