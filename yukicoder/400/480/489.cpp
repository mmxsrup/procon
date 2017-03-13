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
const ll INFF = 1e18;

ll n, d, k;
ll x[100010];

int main(void){
	cin >> n >> d >> k;
	rep(i, n) cin >> x[i];
	int l = 0, r = 0;
	ll ma = 0;
	int ansl = 0, ansr = 0;
	while(l < n && r < n){
		printf("l : %d\n", l);
		while(r - l <= d - 1){
			r++; //右端を進める.
			if(ma < x[r] - x[l]){ //最大値が更新されるとき.
				ma = x[r] - x[l];
				ansl = l, ansr = r;
			}
			/* 右端が左端より小さくなったら, 左端を右端へ*/
			if(x[r] < x[l]){
				l = r;
				break;
			}
		}
		if(r - l == d) l++; //右端がこれ以上伸ばせないので左端を伸ばす.
		if(l > r)r = l;
	}
	printf("%lld\n", ma * k);
	if(ma == 0) return 0;
	printf("%d %d\n", ansl, ansr);
	return 0;
}