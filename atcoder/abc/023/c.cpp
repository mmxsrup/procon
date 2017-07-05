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

#define int long long

int R, C, K, N;
int r[100010], c[100010];
int h[100010], w[100010];
int cnth[100010], cntw[100010];

signed main(void) {
	cin >> R >> C >> K >> N;
	rep(i, N){
		cin >> r[i] >> c[i];
		r[i]--, c[i]--;
		h[r[i]]++, w[c[i]]++;
	}
	rep(i, R) cnth[h[i]]++;
	rep(i, C) cntw[w[i]]++;


	int ans = 0;
	rep(i, K + 1){
		ans += cnth[i] * cntw[K - i];
	}
	rep(i, N){
		if(h[r[i]] + w[c[i]] == K) ans--;
		if(h[r[i]] + w[c[i]] == K + 1) ans++;
	}
	cout << ans << endl;
	return 0;
}