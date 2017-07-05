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

int N;
int mi, ma;
int v[110], w[110];
int V;
int dp[100010];


int main(void){
	cin >> N;
	rep(i, N) cin >> v[i] >> w[i];
	cin >> V;
	for (int i = 0; i < N; ++i){
		for (int j = 100000; j >= w[i]; --j){
			chmax(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	int ansl = INF, ansr = 1;
	reps(i, 1, 100001){
		if(dp[i] == V)chmin(ansl, i), chmax(ansr, i);
	}
	printf("%d\n", ansl);
	if(ansr == 100000) printf("inf\n");
	else printf("%d\n", ansr);
	return 0;
}