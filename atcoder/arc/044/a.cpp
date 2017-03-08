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
	string s; cin >> s;
	ll n = stoll(s);
	if(n == 1){
		printf("Not Prime\n"); return 0;
	}
	auto d = s.back() - '0';
	int sum = 0;
	bool f = true;
	for(auto u : s) sum += u - '0';
	for (int i = 2; i * i <= n; ++i){
		if(n % i == 0){
			f = false;
			break;
		}
	}
	if(f){
		printf("Prime\n"); return 0;
	}

	if((d % 2 != 0 && d != 5) && sum % 3 != 0){
		printf("Prime\n");
	}else{
		printf("Not Prime\n");
	}
	return 0;
}