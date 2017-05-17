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

int K, N;
string v[55], w[55];
bool solve1(vector<int> &len){
	// printf("k\n");
	rep(i, N){
		int sum = 0;
		for(auto u : v[i]) sum += len[u - '0'];
		if(sum != w[i].size()) return false;
	}
	return true;
}

set<string> se[12];

bool solve2(vector<int> &len){
	rep(i, 12)se[i].clear();
	// printf("k\n");
	rep(i, N){
		int idx = 0;
		for(auto u : v[i]){
			int d = len[u - '0'];
			se[u - '0'].insert(w[i].substr(idx, d));
			idx += d;
		}
	}
	reps(i, 1, K + 1){
		if(se[i].size() != 1) return false;
	}
	return true;
}

int main(void){
	cin >> K >> N;
	rep(i, N)cin >> v[i] >> w[i];
	for (int mask = 0; mask < pow(3, K); ++mask){
		// printf("mask %d\n", mask);
		vector<int> len;
		len.pb(0);
		int tmp = mask;
		rep(i, K){
			len.pb(tmp % 3 + 1);
			tmp /= 3;
		}
		if(!solve1(len)) continue;
		if(!solve2(len)) continue;
		break;
	}
	// printf("ok\n");
	reps(i, 1, K + 1){
		for(auto u : se[i]) cout << u << endl;
	}
	return 0;
}