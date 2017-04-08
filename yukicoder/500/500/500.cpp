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

int main(void){
	ll N; cin >> N;
	ll ans = 1;
	if(N >= 50){
		printf("000000000000\n");
		return 0;
	}
	bool f = false;
	reps(i, 1, N + 1){
		ans *= i;
		if(ans >= 1000000000000){
			ans %= 1000000000000;
			f = true;
		}
		/*
		if(ans == 0){
			printf("000000000000\n");
			return 0;
		}
		*/
	}
	if(f){
		string d = to_string(ans);
		while(d.size() < 12) d = '0' + d;
		cout << d << endl;
	}else{
		printf("%lld\n", ans);
	}
	return 0;
}