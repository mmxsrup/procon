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
ll x[200010], y[200010];

int main(void){
	cin >> N;
	vector<pair<ll, int> > v;
	map<ll, ll> ma;
	rep(i, N) cin >> x[i] >> y[i];
	vector<ll> vx, vy;
	rep(i, N){
		if(x[i] > y[i]) swap(x[i], y[i]);
		vx.pb(x[i]), vy.pb(y[i]);
		if(x[i] == y[i]) ma[x[i]]++;
		else ma[x[i]]++, ma[y[i]]++;
	}
	rep(i, N){
		if(ma[x[i]] >= N){
			printf("0\n");
			return 0;
		}
		if(ma[y[i]] >= N){
			printf("0\n");
			return 0;
		}
	}
	sort(all(vx)), sort(all(vy));
	ll red1 = abs(vx[N - 1] - vy[0]);
	ll blu1 = abs(vy[N - 1] - vx[0]);
	ll red2 = vx[N - 1] - vx[0];
	ll blu2 = vy[N - 1] - vy[0];
	// ll red3 = abs(vx[N - 1] - vy[N - 1]);
	// ll blu3 = abs(vx[0] - vy[0]);
	ll ans = min(red1 * blu1, red2 * blu2);
	cout << ans << endl;
	return 0;
}