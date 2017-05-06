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

int dp[1110][1110];

string s;
int main(void){
	cin >> s;
	rep(i, 1110)rep(j, 1110) dp[i][j] = -INF;
	dp[0][510] = 0;
	reps(i, 1, s.size() + 1){
		rep(j, 1010){
			if(dp[i - 1][j] != -INF){
				if(s[i - 1] == '+'){
					chmax(dp[i][j], dp[i - 1][j] + j - 510);
				}
				else if(s[i - 1] == '-'){
					chmax(dp[i][j], dp[i - 1][j] - j + 510);
				}
				else{
					chmax(dp[i][j + 1], dp[i - 1][j]);
					chmax(dp[i][j - 1], dp[i - 1][j]);
				}
			}
		}
	}
	printf("%d\n", dp[s.size()][510]);
	return 0;
}