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

int n;

int main(void) {
	cin >> n;
	set<int> se;
	multiset<int> mse;
	rep(i, n){
		int t; cin >> t;
		se.insert(t), mse.insert(t);
	}

	ll ma1 = 0, ma2 = 0;
	for(auto u : se) {
		if(mse.count(u) >= 4) {
			chmax(ma1, u), chmax(ma2, u);
		}else if(mse.count(u) >= 2){
			if(u > ma1) {
				ma2 = ma1, ma1 = u;
			}else if(u > ma2) {
				ma2 = u;
			}
		}
	}
	cout << ma1 * ma2 << endl;
	return 0;
}