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

int n, k;
vector<int> a;
set<int> seta;
string s[100010];
bool flag[100010];
int main(void){
	cin >> n >> k;
	rep(i, k){
		int t; cin >> t;
		a.pb(t);
		seta.insert(t);
	}
	rep(i, n) cin >> s[i];

	if(n == k){
		printf("\n");
		return 0;
	}
	vector<string, int> v;
	// v.pb(mp('', -1));
	rep(i, n){
		v.pb(mp(s[i], i));
	}
	sort(all(v));

	rep(i, n){
		if(seta.count(v[i].se))flag[i] = 1;
	}
	int l, r;
	rep(i, n){
		if(flag[i] == 1) l = i;
	}
	for (int i = n  - 1; i >= 0; --i){
		if(flag[i] == 1) r = i;
	}
	if(r == )
	reps(i, l, r + 1){
		if(flag[i] == 0){
			printf("NO\n");
			return 0;
		}
	}

	return 0;
}