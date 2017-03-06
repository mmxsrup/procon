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

set<pair<int, int> > S;
vector<pint> side;

int main(void){
	int n, m;
	cin >> n >> m;
	S.insert(mp(0, m - 1));
	rep(i, n){
		int tl, tr;
		cin >> tl >> tr;
		side.pb(mp(tl, tr));
	}

	rep(i, n){
		int l, r;
		l = side[i].fi, r = side[i].se;
		int rel = m - l - 1, rer = m - r - 1;
		if(rel > rer) swap(rel, rer);
		if(rel < l){
			side[i].fi = rel, side[i].se = rer;
		}
	}
	sort(all(side));
	rep(i, n){
		bool ok = false;
		int l = side[i].fi, r = side[i].se;
		// printf("l %d r %d\n", l, r);
		for(auto u : S){
			if(u.fi <= l && r <= u.se){
				if(u.fi != l){
					S.insert(mp(u.fi, l - 1));
				}
				if(u.se != r){
					S.insert(mp(r + 1, u.se));
				}
				S.erase(mp(u.fi, u.se));
				ok = true;
				break;
			}
		}
		if(!ok){//回転
			l = m - l - 1, r = m - r - 1;
			if(l > r)swap(l, r);
			// printf("dame %d %d\n", l, r);
			for(auto u : S){
				if(u.fi <= l && r <= u.se){
					if(u.fi != l){
						S.insert(mp(u.fi, l - 1));
					}
					if(u.se != r){
						S.insert(mp(r + 1, u.se));
					}
					S.erase(mp(u.fi, u.se));
					ok = true;
					break;
				}
			}
		}
			
		/*
		for(auto v : S){
			printf("k %d %d\n", v.fi, v.se);
		}
		*/
		
		if(!ok){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}