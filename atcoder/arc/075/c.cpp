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

int n;
int dp[10010];
int s[110];
int main(void){
	cin >> n;
	rep(i, n) cin >> s[i];
	dp[0] = 1;
	for (int i = 0; i < n; ++i){
		for (int j = 10000; j >= 0; --j){
			if(j - s[i] >= 0 && dp[j - s[i]]){
				dp[j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 10000; i >= 0; --i){
		if(i % 10 != 0 && dp[i]) chmax(ans, i);
	}
	printf("%d\n", ans);
	return 0;
}