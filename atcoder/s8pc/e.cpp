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

int N, K, X;
int S[2510];
set<int> setS;

int main(void){
	cin >> N >> K >> X;
	rep(i, K) cin >> S[i];
	rep(i, K) setS.insert(S[i]);
	ll exp = 0;
	rep(i, K) exp += pow(2, S[i]);

	ll ans = 0;
	for (ll mask = 0; mask < (1 << (1 + N)); ++mask){
		bool flag = true;
		for (int pos = 0; pos < 1 + N; ++pos){
			if(setS.count(pos) == 0) continue;
			if((mask & (1 << pos)) == 0){
				flag = false; break;
			}
		}
		ll retu = mask | exp;
	}
	return 0;
}