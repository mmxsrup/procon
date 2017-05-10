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
#define rall(v) (v).rbegin(), (v).rend()
#define eall(v) unique(all(v), v.end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define OUT(x) cout << #x << " = " << x << endl; 
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

int N;
int C[100010], A[100010];
int dp[100010];
int main(void){
	cin >> N;
	if(N >= 110) return 0;
	rep(i, N - 1) cin >> C[i] >> A[i];
	dp[0] = 0;
	reps(i, 1,  N + 1){
		set<int> se;
		for (int j = i - 1; j >= max(0, i - C[i]); --j){
			se.insert(dp[j]);
		}
		int res = 0;
		while(se.count(res)) res++;
		dp[i] = res;
	}
	int f = 0;
	rep(i, N)rep(j, A[i]){
		f ^= dp[i + 1];
	}
	if(f == 0) printf("Second\n");
	else printf("First\n");
	return 0;
}