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

int sum(int r){
	if(r <= 0) return 0;
	return r * (1 + r) / 2;
}


/*
40度
*/
int main(void){
	int r, g, b; cin >> r >> g >> b;
	int ans = INF;
	rep(i, r)rep(j, g)rep(k, b){
		int lr = i, rr = r - i - 1;//-100の左右
		int lg = j, rg = g - j - 1;//0の左右
		int lb = k, rb = b - k - 1;//100の左右
		if(rr + lg > 99) continue;
		if(rg + lb > 99) continue;
		// printf("%d %d %d %d %d %d\n", lr, rr, lg, rg, lb, rb);
		int ret = sum(lr) + sum(rr) + sum(lg) + sum(rg) + sum(lb) + sum(rb);
		chmin(ans, ret);
	}

	rep(i, 300)rep(j, 300){
		int lr = i + r - 1, rr = i;
		int lb = j, rb = j + b - 1;
		if(199 + rr + lb != g) continue;
		printf("%d %d %d %d\n", lr, rr, lb, rb);
		int ret = sum(lr) - sum(rr - 1) + sum(99 + rr) + sum(99 + lb) + sum(rb) - sum(lb - 1);
		chmin(ans, ret);
	}
	cout << ans << endl;
	return 0;
}