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

int N;
int tu[150010], tv[150010];
vector<int> G[150010];

long double dfs(int now, int pre, long double E, int dist){
	double ret = 0;
	int nextsize;
	if(pre == -1) nextsize = G[now].size();
	else nextsize = G[now].size() - 1;
	if(nextsize == 0){
		return dist * E;
	}
	for(auto u : G[now]){
		if(u == pre) continue;
		ret += dfs(u, now, E / nextsize, dist + 1);
	}
	return ret;
}

int main(void){
	cin >> N;
	rep(i, N - 1) cin >> tu[i] >> tv[i];
	rep(i, N - 1) tu[i]--, tv[i]--;
	rep(i, N - 1){
		G[tu[i]].pb(tv[i]);
		G[tv[i]].pb(tu[i]);
	}

	int one = 0, two = 0;
	rep(i, N){
		if(G[i].size() == 1) one++;
		else if(G[i].size() == 2) two++;
	}
	// printf("%d %d\n", one, two);
	if(one == 2 && two == N - 2){
		// printf("k\n");
		rep(i, N){
			if(G[i].size() == 1){
				printf("%.9Lf\n", (long double)(N - 1));
			}else{
				printf("%.9Lf\n", (long double)(N - 1) / 2.0);
			}
		}
		return 0;
	}


	
	rep(i, N){
		long double ret = dfs(i, - 1, 1.0, 0);
		printf("%.9Lf\n", ret);
	}
	return 0;
}