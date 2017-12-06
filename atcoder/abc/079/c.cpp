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

int main() {
	string s; cin >> s;
	rep(i, 2)rep(j, 2)rep(k, 2) {
		int sum = s[0] - '0';
		if(i == 0) sum += s[1] - '0';
		else sum -= s[1] - '0';
		if(j == 0) sum += s[2] - '0';
		else sum -= s[2] - '0';
		if(k == 0) sum += s[3] - '0';
		else sum -= s[3] - '0';
		if(sum == 7) {
			// printf("%d %d %d\n", i, j, k);
			string ans{s[0]};
			// cout << ans << endl;

			if(i == 0) ans += "+";
			else ans += "-";
			ans += s[1];

			if(j == 0) ans += "+";
			else ans += "-";
			ans += s[2];

			if(k == 0) ans += "+";
			else ans += "-";
			ans += s[3];

			cout << ans + "=7" << endl;
			return 0;
		}
	}
	return 0;
}