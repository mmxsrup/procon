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

class FoxesOfTheRoundTable{
public:
	vector <int> minimalDifference(vector <int> h){
		vector<pair<int, int> > v;
		rep(i, h.size()){
			v.pb(mp(h[i], i));
		}
		sort(all(v));
		vector<int> l, r;
		rep(i, v.size()){
			if(i % 2 == 0) l.pb(v[i].se);
			else r.pb(v[i].se);
		}
		reverse(all(r));
		l.insert(l.end(), all(r));
		return l;
	}
};

int main(void){
	FoxesOfTheRoundTable ft;
	auto ret = ft.minimalDifference({1,99,50,50});
	for(auto u : ret){
		printf("%d ", u);
	}
	printf("\n");
	return 0;
}