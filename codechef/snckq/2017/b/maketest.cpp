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

const int MAX_N = 100000, MIN_N = 1, MAX_M = 200000, MIN_M = 0;
int main(void){
	srand((unsigned int)time(NULL));
	printf("1\n");
	int n = rand() % (MAX_N - MIN_N + 1) + MIN_N;
	int m = min(rand() % (MAX_M - MIN_M + 1) + MIN_M, n * (n - 1) / 2);
	printf("%d %d\n", n, m);

	for (int i = 0; i < m; ++i){
		int u = rand() % (n - 1 + 1) + 1;
		int v = rand() % (n - 1 + 1) + 1;
		if(u == v){
			i--; continue;
		}
		printf("%d %d\n", u, v);
	}
	return 0;
}