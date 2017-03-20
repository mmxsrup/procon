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

string s;
int cnt_m;
int memop[100010], memom[100010];

int main(void){
	cin >> s;
	for(auto u : s){
		if(u == 'M') cnt_m++;
	}

	REP(i, s.size()){
		if(s[i] == '+'){
			memop[i] += memop[i + 1] + 1;
			memom[i] += memom[i + 1];
		}else if(s[i] == '-'){
			memop[i] += memop[i + 1];
			memom[i] += memom[i + 1] + 1;
		}else{
			memop[i] += memop[i + 1];
			memom[i] += memom[i + 1];
		}
	}
	vector<int> vplus, vminus;
	rep(i, s.size()){
		if(s[i] == 'M'){
			vplus.pb(memop[i] - memom[i]);
		}
	}
	ll ans = 0;
	//両側から挟むような形で良い物を選ぶ
	sort(all(vplus)); reverse(all(vplus));
	rep(i, cnt_m / 2) ans += vplus[i];
	reverse(all(vplus));
	rep(i, cnt_m / 2) ans -= vplus[i];
	printf("%lld\n", ans);
	return 0;
}