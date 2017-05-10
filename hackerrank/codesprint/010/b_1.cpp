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
int ans = INF;
void dfs(list<int> v){
	/*
	for(auto u : v){
		printf("%d ", u);
	}
	*/
	bool flag = true;
	list<int>::iterator pos;
	for(auto i0 = v.begin(); i0 != v.end(); ++i0){
		auto i1 = next(i0), i2 = next(i1);
		if((*i0 < *i1 && *i1 < *i2 || 
			*i0 > *i1 && *i1 > *i2)){
			flag = false;
			break;
		}
	}
	if(flag){
		chmin(ans, n - v.size());
		return;
	}
	
	return;
}

int main(void){
	cin >> n;
	list<int> a;
	rep(i, n){
		int d; cin >> d;
		a.pb(d);
	}
	if(n <= 2){
		printf("0\n"); return 0;
	}
	dfs(a);
	cout << ans << endl;
	return 0;
}
