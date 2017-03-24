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

int Gx, Gy, K;
int x[6], y[6], N[6];
map<pair<int, int>, int> mpp;
vector<int> v;

int main(void){
	cin >> Gx >> Gy >> K;
	rep(i, K) cin >> x[i] >> y[i] >> N[i];
	rep(i, K) mpp[mp(x[i], y[i])] += N[i];
	for(auto u : mpp){
		printf("%d %d %d\n", u.fi.fi, u.fi.se, u.se);
	}
	return 0;
}