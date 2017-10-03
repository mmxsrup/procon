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
	while(1) {

		string s[55];
		string t[55];

		int n; cin >> n;
		if(n == 0) break;
		rep(i, n) cin >> s[i];
		rep(i, n){
			t[i] += s[i][0];
			rep(j, s[i].size() - 1){
				if(s[i][j] == 'a' || s[i][j] == 'i' || s[i][j] == 'u' || s[i][j] == 'e' || s[i][j] == 'o'){
					t[i] += s[i][j + 1];
				}
			}
		}
		
		// rep(i, n) cout << t[i] << endl;
		int ans = -1;
		reps(k, 1, 51) {
			set<string> se;
			rep(i, n) se.insert(t[i].substr(0, k));
			// printf("se\n");
			// for(auto u : se) cout << u << endl;
			// printf("\n");
			if(se.size() == n) {
				ans = k; break;
			}
		}
		printf("%d\n", ans);
		
	}
	return 0;
}