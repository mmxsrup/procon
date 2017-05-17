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

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

ll N, D;
ll X, Y;

int main(void){
	cin >> N >> D >> X >> Y;
	
	if(X % D != 0 || Y % D != 0){
		printf("0.0\n"); return 0;
	}
	int x = X / D, y = Y / D;
	if(N < abs(x) + abs(y)){
		printf("0.0\n"); return 0;
	}

	int amari = N - (abs(x) + abs(y));
	if(amari % 2){
		printf("0.0\n"); return 0;
	}

	X /= D, Y /= D;
	// printf("%d %d\n",X, Y);
	int cnt = 0;
	for (int mask = 0; mask < pow(4, N); ++mask) {
		int d = mask;
		ll nnx = 0, nny = 0;
		rep(i, N){
			int t = d % 4;
			nnx += dx[t];
			nny += dy[t];
			d /= 4;
		}
		// printf("%lld %lld\n", nnx, nny);
		if(nnx == X && nny == Y){
			// printf("k\n");
			cnt++;
		}
	}
	// printf("%d\n", cnt);
	printf("%.9f\n", 1.0 * cnt / pow(4, N));
	return 0;
}