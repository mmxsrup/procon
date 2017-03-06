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

int n, b;
vector<ll> xs, ys, ps;//使用する座標
map<ll, ll> zipx, zipy;//<元, 圧縮後>
map<ll, ll> unzipx, unzipy, unzipz;//<圧縮後, 元>
// map<pair<ll, ll>, ll> score;
int board[410][410];
int memo[410][410];
int main(void){
	cin >> n >> b;
	ll x[410], y[410], p[410];
	rep(i, n){
		cin >> x[i] >> y[i] >> p[i];
		// score[mp(x[i], y[i])] = p[i];
		xs.pb(x[i]); ys.pb(y[i]);
	}

	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(),xs.end()), xs.end());//重複消去
	sort(ys.begin(), ys.end());
	ys.erase(unique(ys.begin(), ys.end()), ys.end());
	rep(i, xs.size()){
		zipx[i] = xs[i];
		unzipx[xs[i]] = i;
	}
	rep(i, ys.size()){
		zipy[i] = ys[i];
		unzipy[ys[i]] = i;
	}

	rep(i, n){
		board[unzipy[y[i]]][unzipx[x[i]]] = p[i];
	}
	rep(i, h) memo[i][0] = 0;
    rep(i, w) memo[0][i] = 0;
    rep(i, h)rep(j, w){//横の累積和
        memo[i + 1][j + 1] += memo[i + 1][j] + b[i][j];
    }
    rep(i, w)rep(j, h){//2次元累積和
        memo[j + 1][i + 1] += memo[j][i + 1];
    }

    int ans = 0;
    /*
   (i, j)------------|
   |                 |
   |
   (x1)-------------(y, x)
   */
    reps(i, 1, h + 1)reps(j, 1, w + 1){
        reps(y, i, h + 1)reps(x, j, w + 1){
            ll sum = memo[y][x];
            sum -= memo[i - 1][x];
            sum -= memo[y][j - 1];
            sum += memo[i - 1][j - 1];
            if(sum == 0){
                ans = max(ans, (y - i + 1) * (x -  j + 1));
            }
        }
    }
    rep(xl, xs.size()){
    	reps(xr, i + 1, xs.size()){
    		rep(y1, )
    	}
    }
}