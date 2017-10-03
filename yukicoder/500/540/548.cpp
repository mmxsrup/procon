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

int main(void) {
	string s; cin >> s;
	int cnt[26] = {0};
	for(auto k : s) {
		cnt[k - 'a']++;
	}

	int d0 = 0, d1 = 0, d2 = 0;
	rep(i, 13) {
		if(cnt[i] == 0) d0++;
		if(cnt[i] == 1) d1++;
		if(cnt[i] == 2) d2++;
	}
	if(d0 > 1 or d2 > 1) {
		printf("Impossible\n");
		return 0;
	}
	if(d0 + d1 + d2 != 13) {
		printf("Impossible\n");
		return 0;
	}

	bool iszero = false;
	rep(i, 13) if(cnt[i] == 0) iszero = true;

	if(iszero) {
		rep(i, 13) {
			if(cnt[i] == 0) {
				printf("%c\n", 'a' + i);
			}
		}
	}else {
		rep(i, 13) {
			if(cnt[i] == 1) {
				printf("%c\n", 'a' + i);
			}
		}
	}

	return 0;
}