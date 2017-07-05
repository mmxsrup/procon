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


bool check(string t){
	set<char> se;
	for(auto u : t) se.insert(u);
	// printf("size %d\n",set.size() );
	if(se.size() == 1) return true;
	else return false;
}

int main(void) {
	string s; cin >> s;
	int ans = INF;
	rep(i, s.size()){
		char c = s[i];
		// printf("c %c\n", c);
		string tmp = s;

		while(!check(tmp)){
			// cout << tmp <</ endl;
			string d;
			rep(k, tmp.size() - 1){
				if(tmp[k] == c || tmp[k + 1] == c){
					// printf("	k %d\n", k);
					d += c;
				}else{
					d += tmp[k];
				}
			}
			tmp = d;
		}
		chmin(ans, s.size() - tmp.size());
	}
	printf("%d\n", ans);
	return 0;
}