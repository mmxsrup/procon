#include <bits/stdc++.h>
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
 
string s[1010];
string sfirst, send;
int N;
 
bool solve(const string& a, const string& b) {
	int cnt = 0;
	rep(i, a.size()) if(a[i] != b[i]) cnt++;
	return cnt == 1 ? true : false;
}
 
const int MAX_N = 1010;
using TYPE = double; // 距離の型を入れる
vector<pair<int, TYPE> > G[MAX_N];
 
pair<vector<TYPE>, vector<int>> dijkstra(int start, int goal){//スタートとゴールを逆に
    vector<TYPE> dist(MAX_N, INFF);
    vector<int> pre(MAX_N, -1);//pre[i] := iの前の頂点
    dist[start] = 0;//dist[i] :=　start->iまでの最短距離
    priority_queue<pair<TYPE, int>, vector<pair<TYPE, int> >, greater<pair<TYPE, int> > > que;
    que.push(make_pair(0, start));
    while(!que.empty()){
        TYPE cost; int u;//今までにかかった時間 現在の頂点
        cost = que.top().first, u = que.top().second;
        que.pop();
        if(dist[u] < cost) continue;
        for (auto tmp : G[u]){
            int v = tmp.first; TYPE time = tmp.second;//隣接する頂点 その頂点まで行く時間
            if(dist[v] > dist[u] + time){//u->v
                dist[v] = dist[u] + time;
                if(pre[v] != -1) {
                	printf("no\n");
                }
                pre[v] = u;
                que.push(make_pair(dist[v], v));
            }
        }
    }
    if(dist[goal] == INFF) return make_pair(dist, vector<int>(1, -1)); // start->goalに経路がない場合
    //経路復元
    vector<int> path;
    int s = start, t = goal;
    for (; t != s; t = pre[t]) path.push_back(t);
    
    path.push_back(s);
    reverse(path.begin(), path.end());
    return make_pair(dist, path); //start-> * -> goal startからgoalまでの最短経路(辞書順最小)
}
 
 
int main(void) {
	cin >> sfirst >> send;
	cin >> N;
	rep(i, N) cin >> s[i];
	if(sfirst == send)  {
		printf("0\n");
		cout << sfirst << endl;
		cout << send << endl;
		return 0;
	}
 
	s[N] = sfirst, s[N + 1]  = send;
	int sidx = N, eidx = N + 1; 
	rep(i, N + 2)reps(j, i + 1, N + 2){
		if(i == j) continue;
		if(solve(s[i], s[j])) {
			// cout << s[i] << " " << s[j] << endl;
			G[i].pb(mp(j, 1ll)), G[j].pb(mp(i, 1ll));
		}
	}
	auto ret = dijkstra(sidx, eidx);
 
	auto route = ret.second;
	int dist = route.size();
	if(route[0] == -1) {
		printf("-1\n");
	}else{
		printf("%d\n", dist - 2);
		for(auto u : route) cout << s[u] << endl;
	}
	return 0;
}