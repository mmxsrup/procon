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

int N, M;
int x[100], y[100];
int memo[100][100];
bool dp[(1<<16)]; // dp[mask] := 集合maskが条件を満たせばtrue

int main(void){
	cin >> N >> M;
	rep(i, M) cin >> x[i] >> y[i];
	rep(i, M)x[i]--, y[i]--;
	rep(i, (1<<16)) dp[i] = false;
	dp[0] = true;
	rep(i, M) memo[x[i]][y[i]] = memo[y[i]][x[i]] = 1;
	for (int mask = 0; mask < (1<<N); ++mask){
		for (int p = 0; p < N; ++p){ //新しく入る人
			if(!dp[mask]) continue;
			if((mask & (1<<p))) continue;
			bool flag = true;
			for (int i = 0; i < N; ++i){
				if(i == p) continue;
				if((mask & (1<<i)) && (memo[p][i] == 0)){ //関係ない
					flag = false;
					break;
				}
			}
			if(flag) dp[mask | (1<<p)] = true;
		}
	}
	int ans = 0;
	for (int mask = 0; mask < (1<<N); ++mask){
		if(!dp[mask]) continue;
		int cnt = 0;
		for (int p = 0; p < N; ++p){
			if((mask & (1<<p)))cnt++;
		}
		chmax(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}