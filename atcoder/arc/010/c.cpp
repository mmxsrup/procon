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

int n, m, Y, Z;
char c[20]; int p[20];
string b;
map<char, int> ma;
//dp[i][j][k] := i番目までのブロックをみて,jのbitが立っているものを使用して,
//最後にkをつかった時の最大値
// ll dp[5010][(1<<12)][12];
// dp[i + 1][*][*] を求める時は, dp[i][*][*]を使うだけなので 使い回す MLE対策
ll dp[2][(1<<12)][12];

void init(int x) {
	rep(j, (1<<12))rep(k, 12) dp[x][j][k] = -INFF;
}

int main(void) {
	cin >> n >> m >> Y >> Z;
	rep(i, m) cin >> c[i] >> p[i];
	cin >> b;

	rep(i, m) ma[c[i]] = i + 1;

	rep(i, 2)rep(j, (1<<12))rep(k, 12) dp[i][j][k] = -INFF;
	dp[0][0][0] = 0;
	rep(i, n){
		init((i + 1) % 2);
		rep(j, (1<<m))rep(k, m + 1) {
			if(dp[i % 2][j][k] == -INFF) continue;
			int idx = ma[b[i]];
			if(idx == k) { // 前使ったものと同じ
				chmax(dp[(i + 1) % 2][j | (1<<(idx-1))][idx], dp[i % 2][j][k] + Y + p[idx - 1]); // 選ぶ
				chmax(dp[(i + 1) % 2][j][k], dp[i % 2][j][k]); // 選ばない
			} else { // 前使ったものと異なる
				chmax(dp[(i + 1) % 2][j | (1<<(idx-1))][idx], dp[i % 2][j][k] + p[idx - 1]); // 選ばない
				chmax(dp[(i + 1) % 2][j][k], dp[i % 2][j][k]); // 選ばない
			}
		}
	}

	ll ans = 0;
	rep(j, (1<<m) - 1)rep(k, m + 1) {
		chmax(ans, dp[n % 2][j][k]);
	}
	rep(k, m + 1) {
		chmax(ans, dp[n % 2][(1<<m)-1][k] + Z);
	}
	cout << ans << endl;
	return 0;
}