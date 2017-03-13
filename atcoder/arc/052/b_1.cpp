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

double pi = 3.141592653589793;

int n, q;
int x[110], r[110], h[110];
double solve(double tr, double hh){
	return tr * tr * pi* hh / 3.0;
}

double que(double a, double b){
	double ret = 0;
	rep(i, n){
		if(x[i] + h[i] <= a or b <= x[i]) continue;
		double tmpv = 0;
		double hei = x[i] + h[i];
		if(x[i] < a) tmpv += solve((double)r[i] * (hei - a) / h[i], hei - a);
		else tmpv += solve((double)r[i], h[i]);
		if(hei > b) tmpv -= solve((double)r[i] * (hei - b) / h[i], hei - b);
		ret += tmpv;
	}
	return ret;
}

int main(void){
	int ta[100010], tb[100010];
	cin >> n >> q;
	rep(i, n) cin >> x[i] >> r[i] >> h[i];
	rep(i, q) cin >> ta[i] >> tb[i];
	rep(i, q){
		printf("%.6f\n", que(ta[i], tb[i]));
	}
	return 0;
}