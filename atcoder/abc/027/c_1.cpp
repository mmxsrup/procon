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

ll N;
int dfs1(ll now, int cnt){
	if(now > N) return cnt;
	if(cnt % 2)dfs1(now * 2, cnt + 1);
	else dfs1(now * 2 + 1, cnt + 1); //おおきく
}
int dfs2(ll now, int cnt){
	if(now > N) return cnt;
	if(cnt % 2 == 0)dfs2(now * 2, cnt + 1);
	else dfs2(now * 2 + 1, cnt + 1);
}

int main(void){
	cin >> N;
	if(N == 0){
		printf("Aoki\n"); return 0;
	}

	int d = 0;
	ll n = N;
	while(n > 0){
		d++; n >>= 1;
	}
	int ret;
	if(d % 2){
		ret = dfs1(1ll, 0);
	}else{
		ret = dfs2(1ll, 0);
	}
	if(ret % 2) printf("Aoki\n");
	else printf("Takahashi\n");
	return 0;
}