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

int R, C, K;
string s[510];
int memo[510][510]; //縦方向の白の数の累積和

int main(void){
	cin >> R >> C >> K;
	rep(i, R) cin >> s[i];
	reps(i, 1, R + 1)reps(j, 1, C + 1){
		if(s[i - 1][j - 1] == 'o') memo[i][j] += memo[i - 1][j] + 1;
		else memo[i][j] = memo[i - 1][j];
	}
	/*
	rep(i, R){rep(j, C){
			printf("%d ", memo[i][j]);
		}
		printf("\n");
	}
	*/
	

	int ans = 0;
	reps(x, K, R - K + 2)reps(y, K, C - K + 2){
		// printf("x %d y %d\n", x, y);
		bool f = true;
		rep(s, K){
			int dist = (K - s - 1) * 2 + 1;
			int ret1 = memo[x + K - s - 1][y + s] - memo[x - K + s][y + s];
			int ret2 = memo[x + K - s - 1][y - s] - memo[x - K + s][y - s];
			// printf("dist %d %d %d %d %d\n", dist, ret1, ret2, y + K - s - 1, y - K + s);
			if(!(ret1 == dist && ret2 == dist)){
				f = false;
				break;
			}
		}
		if(f) ans++;
	}
	printf("%d\n", ans);
	return 0;
}