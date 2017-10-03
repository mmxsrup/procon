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

int N;
string s1, s2;
int main(void) {
	cin >> N;
	cin >> s1 >> s2;

	ll ans;
	int prev; // 1:=縦 0:=横
	int start;
	if(s1[0] == s2[0]) {
		prev = 1;
		ans = 3;
		start = 1;
	}else {
		prev = 0;
		ans = 6;
		start = 2;
	}
	reps(i, start, N) {
		if(s1[i] == s2[i]) { // 縦
			if(prev == 0) { // 横
				ans *= 1;
			}else { // 縦
				ans *= 2;
			}
			prev = 1;
		}else { // 横
			if(prev == 0) { //横
				ans *= 3;
			}else { // 縦
				ans *= 2;
			}
			prev = 0;
			i++;
		}
		ans %= MOD;
	}
	printf("%lld\n", ans);
	return 0;
}