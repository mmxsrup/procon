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

int main(void){
	string s; cin >> s;
	ll cnt = 0;
	/*
	TLE
	rep(i, s.size())rep(j, s.size()){
		if(i == j) continue;
		if(i < j){
			if(s[i] == 'U')cnt++;
			else cnt += 2;
		}else{
			if(s[i] == 'D') cnt++;
			else cnt += 2;
		}
	}
	*/

	for (int i = 0; i < s.size(); ++i) {
		int d1 = i, d2 = s.size() - i - 1;
		if(s[i] == 'U') cnt += d1 * 2 + d2;
		else cnt += d1 + d2 * 2;
	}
	printf("%lld\n", cnt);
	return 0;
}