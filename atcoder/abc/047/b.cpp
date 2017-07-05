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

int W, H, N;
int x[110], y[110], a[110];
int D[110][110];

int main(void) {
	cin >> W >> H >> N;
	rep(i, N){
		cin >> x[i] >> y[i] >> a[i];
	}
	rep(k, N){
		if(a[k] == 1){
			rep(i, x[k])rep(j, H) D[j][i] = 1;
		}else if(a[k] == 2){
			reps(i, x[k], W)rep(j, H) D[j][i] = 1;
		}else if(a[k] == 3){
			rep(i, y[k])rep(j, W) D[i][j] = 1;
		}else if(a[k] == 4){
			reps(i, y[k], H)rep(j, W) D[i][j] = 1;
		}
	}
	int cnt = 0;
	rep(i, H)rep(j, W)if(D[i][j])cnt++;
	printf("%d\n", H * W - cnt);
	return 0;
}