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

ll n;
ll a[200010];
ll sum[200010];

//x^k mod
long long powmod(long long x, long long k, long long m){ // 繰り返し二乗法(logk)
	if(k == 0) return 1;
	if(k % 2 == 0) return powmod(x * x % m, k / 2, m);
	else return x * powmod(x, k - 1, m) % m;
}

int main(void){
	ll max_a = 0;
	cin >> n;
	rep(i, n){
		cin >> a[i];
		chmax(max_a, a[i]);
	}

	if(a[0] != 0){
		printf("0\n"); return 0;
	}
	reps(i, 1, n) if(a[i] == 0){
		printf("0\n"); return 0;
	}

	rep(i, n){
		sum[a[i]]++;
	}
	rep(i, max_a + 1){
		if(sum[i] == 0){ // 木の高さにで飛んでいるものはない
			printf("0\n"); return 0;
		}
	}

	ll ans = 1;
	//同じ高さのものをつなぐ
	reps(i, 1, max_a + 1){
		//同じ高さの頂点を2つ選ぶ方法は, sum[i] C 2 通り
		ans *= powmod(2, sum[i] * (sum[i] - 1) / 2, MOD);
		ans %= MOD;
	}
	//下のやつと一つ上のやつをつなぐ 
	for (int i = max_a; i >= 1; --i){
		//任意の下のやつ1つに対して上のやつを選ぶか選ばないか (何も選ばないのはダメ)
		ll t = powmod(2, sum[i - 1], MOD) - 1;
		ans *= powmod(t, sum[i], MOD); //下の奴がsum[i]個あるので
		ans %= MOD;
	}
	printf("%lld\n", ans);
	return 0;
}