#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
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

set<string> tmp;

void dfs(string s, int cnt, int size){
	if(cnt == size){
		tmp.insert(s);
		return;
	}
	if(cnt < size / 2){
		rep(i, 10){
			string d = to_string(i);
			dfs(s + d, cnt + 1, size);
		}
	}

	if(cnt >= size / 2){
		auto left = s;
		auto right = s;
		reverse(all(right));
		if(size % 2 == 1){
			rep(i, 10){
				string d = to_string(i);
				tmp.insert(left + d + right);
			}
		}else{
			tmp.insert(left + right);
		}
	}
	return;
}

ll solve(ll n){
	ll ret = 0;
	string s = to_string(n);
	reps(cnt, 1, s.size() + 1){
		reps(i, 1, 10){
			auto d = to_string(i);
			dfs(d, 1, cnt);
		}
	}
	for(auto u : tmp){
		ll d = stoll(u);
		if(d <= n) ret++;
	}
	return ret;
}

int main(void){
	ll n; cin >> n;
	n /= (INF + 1);
	printf("%lld\n", solve(n));
	return 0;
}