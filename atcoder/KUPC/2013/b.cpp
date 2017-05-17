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

int n, x, m;
int l[10], r[10], s[10];

int solve(vector<int> &v){
	rep(i, m){
		int sum = 0;
		reps(j, l[i], r[i] + 1){
			sum += v[j];
		}
		if(sum != s[i]) return -1;
	}
	int ret = 0;
	for(auto u : v) ret += u;
	return ret;
}


int main(void){
	cin >> n >> x >> m;
	rep(i, m) cin >> l[i] >> r[i] >> s[i];
	rep(i, m) l[i]--, r[i]--;
	int ans = -1;
	vector<int> ansv;
	for (int mask = 0; mask < pow(x + 1, n); ++mask){
		vector<int> num;
		int tmp = mask;
		rep(i, n){
			num.pb(tmp % (x + 1));
			tmp /= (x + 1);
		}
		int ret = solve(num);
		if(ret > ans){
			ans = ret;
			ansv = num;
		}
	}
	if(ans == -1) printf("-1\n");
	else{
		rep(i, ansv.size()){
			if(i != ansv.size() - 1) printf("%d ", ansv[i]);
			else printf("%d\n", ansv[i]);
		}
	}
	return 0;
}