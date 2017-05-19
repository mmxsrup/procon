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

int n, m;
int l[300010], r[300010], x[300010];
int ans[300010];

int main(void){
	cin >> n >> m;
	rep(i, m) cin >> l[i] >> r[i] >> x[i];
	rep(i, m) l[i]--, r[i]--, x[i]--;
	rep(i, 300010) ans[i] = -1;

	set<int> se;
	rep(i, n) se.insert(i);
	rep(i, m){
		auto itr = se.lower_bound(l[i]);
		// while(itr != se.end() && *itr <= r[i]){ /* 条件文の順番注意 */
		while(*itr <= r[i] && itr != se.end()){
			if(*itr == x[i]){
				itr++;
				continue;
			}
			ans[*itr] = x[i];
			itr = se.erase(itr); /* set.erase が次の要素のイテレータを返す */
		}
	}

	rep(i, n){
		if(i != n - 1) printf("%d ", ans[i] + 1);
		else printf("%d\n", ans[i] + 1);
	}
	return 0;
}