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

int n, m;
vector<int> num[100010];
ll s[100010];
int main(void){
	cin >> n >> m;
	ll sum = 0;
	rep(i, n){
		int l, r;
		cin >> l >> r >> s[i + 1];
		sum += s[i + 1];
		num[l].pb(i + 1);
		num[r + 1].pb(-(i + 1));
	}
	ll ans = 0;
	reps(i, 1, m + 1){//i番目の宝石を選ばない時
		// printf("i %d\n", i);
		for(auto u : num[i]){//u番目の遺跡を訪れることができない
			// printf("%d\n", u);
			if(u >= 0) sum -= s[u];
			else sum += s[-u];
		}
		// printf("sum %lld\n", sum);
		chmax(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
}