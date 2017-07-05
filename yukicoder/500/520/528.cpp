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
ll MOD1 = 1e9;
ll MOD2 = 1e9 + 7;
int main(void){
	cin >> s;
	int d = 0;
	ll ans1 = 1, ans2 = 1;
	rep(i, s.size() / 2 + 1){
		if(s[i] < s[s.size() - i - 1]){
			ans1 += s[i] - '0' + d, ans2 += s[i] - '0' + d;
			if(s[i] >= '1') d = 1;
		}else{
			ans1 *= s[s.size() - i - 1] - '0' + d, ans2 *= s[s.size() - i - 1] - '0' + d;
			if(s[s.size() - i - 1] >= '1') d = 1;
		}
		ans1 %= MOD1, ans2 %= MOD2;
	}
	printf("%lld\n%lld\n", ans1, ans2);
	return 0;
}