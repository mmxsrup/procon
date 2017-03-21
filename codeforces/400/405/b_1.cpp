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

int n, m;
vector<int> G[200100];
set<pair<int, int>> se;

bool flag = true;
void dfs(int now, int pre, int cnt, int start){
	if(cnt >= 3) return;
	if(cnt == 2){
		if(!se.count(mp(now, start))){flag = false; return;}
		else return;
	}
	for(auto nex : G[now]){
		if(nex == pre) continue;
		dfs(nex, now, cnt + 1, start);
	}
	return;
}

int main(void){
	scanf("%d %d", &n, &m);
	rep(i, m){
		int a, b; scanf("%d %d", &a, &b);
		a--; b--;
		G[a].pb(b); G[b].pb(a);
		se.insert(mp(a, b)); se.insert(mp(b, a));
	}
	rep(i, n){
		dfs(i, -1, 0, i);
	}
	if(!flag){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	return 0;
}