#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;

int t;
int n;
int A[110];
int rA[110];
int dp[110][110]; //dp[i][j]:= 2つ前にi番目をを1つ前にj番目のAを使った
int rdp[110][110];
int maxdp[110];
int maxrdp[110];
int main(void){
	cin >> t;
	while(t--){
		int n; cin >> n;
		rep(i, n){
			cin >> A[i];
			rA[n - i - 1] = A[i];
		}
		rep(i, n)rep(j, n){
			if(i == j) dp[i][j] = 1;
			else dp[i][j] = -1;
		}
		rep(i, n){
			reps(j, i, n){
				reps(k, j + 1, n){
					if(dp[i][j] == -1) continue;
					ll now = A[k] - A[j], pre = A[j] - A[i];
					if(now > pre){
						chmax(dp[j][k], dp[i][j] + 1);
					}
				}
			}
		}
	
		rep(i, n)rep(j, n){
			printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
		}

		rep(i, n)rep(j, n){
			if(i == j) rdp[i][j] = 1;
			else rdp[i][j] = -1;
		}
		rep(i, n){
			reps(j, i, n){
				reps(k, j + 1, n){
					if(rdp[i][j] == -1) continue;
					ll now = rA[k] - rA[j], pre = rA[j] - rA[i];
					if(now > pre){
						chmax(rdp[j][k], rdp[i][j] + 1);
					}
				}
			}
		}
		rep(i, n){
			int d = 0;
			rep(j, i + 1){
				chmax(d, dp[i][j]);
			}
			maxdp[i] = d;
		}
		rep(i, n){
			int d = 0;
			rep(j, i + 1){
				chmax(d, rdp[i][j]);
			}
			maxrdp[i] = d;
		}
		int ans = 0;
		rep(i, n){
			chmax(ans, maxdp[i] + maxrdp[i] - 1);
		}
		printf("%d\n", ans);
	}

	return 0;
}