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

int N, Q; ll 	T;
ll A[100010]; int D[100010];
ll X[100010];
ll ans[100010];

int main(void){
	cin >> N >> T >> Q;
	rep(i, N) cin >> A[i] >> D[i];
	rep(i, N) cin >> X[i], X[i]--;
	vector<pair<int, int>> kukan;
	int l = 0, r = 0;
	while(l < N){
		while(r < N && D[r] == 1) r++;
		while(r < N && D[r] == 2) r++;
		//[l, r)の奴らはおなじとこで 止まる
		kukan.pb(mp(l, r - 1));
		l = r;
	}
	for(auto u: kukan){
		// printf("%d %d\n", u.fi, u.se);
		int L = u.fi, R = u.se;
		ll tans;
		bool flag = false;
		reps(i, L, R){
			if(D[i] == 1 && D[i + 1] == 2){
				tans = (A[i] + A[i + 1]) / 2;
				// printf("tans %lld\n", tans);
				flag = true;
				break;
			}
		}
		if(flag){
			reps(i, L, R + 1){
				if(D[i] == 1) ans[i] = min(tans, A[i] + T);
				else ans[i] = max(tans, A[i] - T);
			}	
		}else{
			reps(i, L, R + 1){
				if(D[i] == 1) ans[i] = A[i] + T;
				else ans[i] = A[i] - T;
			}
		}
	}
	rep(i, Q){
		printf("%lld\n", ans[X[i]]);
	}
	return 0;
}