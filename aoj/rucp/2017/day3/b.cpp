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
int r[110];
int s[110], p[110], c[110];
int points[110], pointp[110], pointc[110], sum[110];

int main(void){
	cin >> N;
	rep(i, N) cin >> r[i];
	rep(i, N) cin >> s[i] >> p[i] >> c[i];


	vector<pair<int, int>> v(N);
	rep(i, N){
		v[i] = make_pair(s[i], i);
	}
	sort(all(v)); reverse(all(v));
	rep(k, N){
		if(k != 0 && v[k - 1].fi == v[k].fi) points[v[k].se] = points[v[k - 1].se];
		else points[v[k].se] = r[k];
	}
	rep(i, N){
		v[i] = make_pair(p[i], i);
	}
	sort(all(v)); reverse(all(v));
	rep(k, N){
		if(k != 0 && v[k - 1].fi == v[k].fi) pointp[v[k].se] = pointp[v[k - 1].se];
		else pointp[v[k].se] = r[k];
	}
	rep(i, N){
		v[i] = make_pair(c[i], i);
	}
	sort(all(v)); reverse(all(v));
	rep(k, N){
		if(k != 0 && v[k - 1].fi == v[k].fi) pointc[v[k].se] = pointc[v[k - 1].se];
		else pointc[v[k].se] = r[k];
	}

	rep(i, N) sum[i] = points[i] + pointc[i] + pointp[i];
	rep(i, N) printf("%d\n", sum[i]);
	return 0;
}