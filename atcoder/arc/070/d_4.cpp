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
vector<int> a;
int dp[5010];

bool solve(int m){
	rep(i, 5010) dp[i] = 0;
	dp[0] = 1;
	rep(i,  N)for (int j = K; j >= 0; --j){
		if(i == m) continue;
		if(dp[j] == 0) continue;
		dp[min(5000, j + a[i])] = 1;
	}
	for (int i = max(0, K - a[m]); i < K; ++i){
		if(dp[i] == 1) return true; //必要
	}
	return false; //不必要
}

int main(void){
	cin >> N >> K;
	rep(i, N){
		int d; cin >> d;
		a.pb(d);
	}
	sort(all(a));
	
	int l = 0, r = N;//[l, r)
	while(r - l > 1){ //小さいやつほどfalse
		int m = (l + r) / 2;
		if(solve(m)) r = m;
		else l = m;
	}
	for (int i = max(0, l - 10); i <= min(N - 1, r + 10); ++i){
		printf("i %d\n", i);
		if(solve(i)){
			printf("%d\n", i);
			return 0;
		}
	}
	printf("%d\n", N);
	return 0;
}