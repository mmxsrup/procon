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

const int MAX_N = 20;
vector<pair<int, int> > G[MAX_N]; /* G[u][v] := u->v's weight */
int dp[(1 << MAX_N)][MAX_N];
int pre[MAX_N];
void Traveling_Salesman(int n){ /* n := Number of vertices */
	rep(i, (1 << n))rep(j, n)dp[i][j] = INF; /* Initialization */
	dp[0][0] = 0;
	for (int mask = 0; mask < (1 << n); ++mask){
		for (int u = 0; u < n; ++u){ /* Current vertex */
			for(auto p : G[u]){ /* Next vertex */
				int v = p.first, w = p.second;
				if((mask & (1 << v)) == 0){
					if(dp[mask | (1 << v)][v] > dp[mask][u] + w){
						dp[mask | (1 << v)][v] = dp[mask][u] + w;
						pre[v] = u;
					}
				}
			}
		}
	}
}

int main(void){
	int v, e;
	scanf("%d %d", &v, &e);
	rep(i, e){
		int s, t, d; scanf("%d %d %d", &s, &t, &d);
		G[s].pb(mp(t, d));
	}
	Traveling_Salesman(v);
	int ret = dp[(1 << v) - 1][0];
	if(ret == INF){
		printf("-1\n");
	}else{
		printf("%d\n", ret);
	}

	return 0;
}