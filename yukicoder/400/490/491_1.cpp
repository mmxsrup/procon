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
	ll n; cin >> n;
	ll cnt = 0;
	ll m = n / (1000000001);
	set<ll> se;
	for (int i = 1; i <= 100000; ++i){
		string left = to_string(i);
		string right = left; reverse(all(right));
		string even = left + right;
		string odd = left + right.substr(1);
		se.insert(stoll(odd)); se.insert(stoll(even));
	}
	for(auto u : se) if(u <= m) cnt++;
	printf("%lld\n", cnt);
	return 0;
}