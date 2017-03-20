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

int N, K;
int a[5010];

bool dp[5010][5010]; //dp[i][j] := i番目までを考えて,合計がjの時があるなら1
bool solve(int idx){
	rep(i, 5010)rep(j, 5010) dp[i][j] = 0;
	dp[0][0] = 1;
	rep(i, N)rep(j, K + 1){
		if(dp[i][j] == 0) continue;
		dp[i + 1][j] = 1;
		if(j + a[i] > K) continue;
		dp[i + 1][j + a[i]] = 1;
	}
	reps(i, max(0, K - a[idx]), K){
		if(dp[N][i]) return true;
	}
	return false;
}

int main(void){
	cin >> N >> K;
	rep(i, N) cin >> a[i];
	sort(a, a + N);
	int l = 0, r = N;
	while(r - l > 1){
		int m = (l + r) / 2;
		// printf("m %d\n",m );
		if(!solve(m)) l = m;
		else r = m;
	}
	printf("%d\n", l + 1);
	return 0;
}