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

int dp[35][55]; // dp[i][j] := i日目までに

int main(void){
	while(1){
		int n; cin >> n;
		if(n == 0) break;
		vector<vector<int>> v(31); // v[i] := i日目に会える人
		rep(i, n){
			int f; cin >> f;
			rep(j, f){
				int d; cin >> d;
				v[d].pb(i);
			}
		}
		vector<set<int>> se(n);
		rep(i, n) se.insert(i);
		reps(i, 1, 31){
			for(auto u : v[i]){

			}
		}
	}
	return 0;
}