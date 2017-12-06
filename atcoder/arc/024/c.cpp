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
string s;
int memo[100010][30];

int main(void) {
	cin >> N >> K;
	cin >> s;
	rep(i, N) memo[i + 1][s[i] - 'a']++;
	rep(i, 30)rep(j, 100001) memo[j + 2][i] += memo[j + 1][i];
	/*
	rep(i, 26){
		rep(j, s.size() + 1) {
			printf("%d ", memo[j][i]);
		}
		printf("\n");
	}
	*/
	map<vector<int>, vector<int>> ma;
	rep(i, N - K + 1) {
		// printf("i %d\n", i);
		vector<int> t;
		rep(j, 26) {
			t.pb(memo[i + K][j] - memo[i][j]);
			// printf("%d ", memo[i + K][j] - memo[i][j]);
		}
		// printf("\n");
		ma[t].pb(i);
	}

	bool f = false;
	rep(i, N - K) {
		// printf("i %d\n", i);
		vector<int> t;
		rep(j, 26) t.pb(memo[i + K][j] - memo[i][j]);
		for(auto u : ma[t]) {
			// printf("u %d\n", u);
			if(abs(i - u) >= K) {
				// printf("i %d u %d\n", i, u);
				f = true;
			}
		}
		// printf("\n");
	}
	if(f) printf("YES\n");
	else printf("NO\n");
	return 0;
}