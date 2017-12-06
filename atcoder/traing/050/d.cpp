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

int N, K;
string s;
bool solve(string& d1, string& d2) {
	if(d1.size() != d2.size()) return false;
	bool f = true;
	rep(i, d1.size()) if(!(d1[i] == d2[i] || d1[i] == '?')) f = false;
	return f;
}
bool solve2(string& d) {
	vector<int> memo(d.size() + 1, 0);
	rep(i, d.size()) {
		int c = d[i] - '0';
		memo[i + 1] = memo[i] + c;
	}
	bool f = true;
	reps(i, 1, d.size() + 1)reps(j, i, d.size() + 1) {
		int c1 = memo[j] - memo[i - 1];
		int c0 = j - i + 1 - c1;
		if(abs(c1 - c0) > K) f = false;
	}
	return f;
}

int main(void) {
	cin >> N >> K;
	cin >> s;
	ll ans = 0;
	if(N <= 12) {
		for (int mask = 0; mask < (1<<N); ++mask) {
			string t;
			rep(i, N) {
				if(mask & (1<<i)) t += '1';
				else t += '0';
			}
			if(!solve(s, t)) continue;
			if(!solve2(t)) continue;
			ans++;
			ans %= MOD;
		}
	}else if(K <= 5) {
		for (int mask = 0; mask < (1<<K); ++mask) {
			string d;
			rep(i, K) {
				if(mask & (1<<i)) d += '1';
				else d += '0';
			}
			string t;
			int idx = 0;
			rep(i, s.size()) {
				if(s[i] == '?') t += d[idx++];
				else t += s[i];
			}
			cout << s << endl;
			cout << t << endl;
			if(!solve(s, t)) continue;
			if(!solve2(t)) continue;
			printf("ok\n");
			ans++;
			ans %= MOD;
		}
	}
	printf("%lld\n", ans);
	return 0;
}