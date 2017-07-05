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


int n, a;
string k;
int b[100010];

int main(void){
	cin >> n >> a;
	cin >> k;
	reps(i, 1, n + 1) cin >> b[i];

	if(k.size() <= 6) {
		ll cnt = stoi(k);
		int now = a;
		rep(i, cnt) {
			now = b[now];
		}
		printf("%d\n", now);
		return 0;
	}

	int start, now = a;
	set<int> used;
	used.insert(a);
	rep(i, 200010) {
		now = b[now];
		if(used.count(now)){
			start = now;
			break;
		}
	}
	ll cnt;
	if(a == start) cnt = 0;
	else {
		rep(i, 200010) {
			now = b[now];
			if(now == start) {
				cnt = i + 1;
				break;
			}
		}
	}

	ll d1 = 0;
	for(auto u : k) {
		d1 = (d1 * 10 + (u - '0')) % MOD;
	}
	ll d2 = cnt % MOD;
	ll time = (d1 - d2 + MOD) % MOD;
	int ans = a;
	rep(i, time) {
		ans = b[ans];
	}
	cout << ans << endl;
	return 0;
}