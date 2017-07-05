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
	bool flag = true;
	for (int i = s.size() - 1; i >= 0; --i){
		// printf("%d %c\n", i, s[i]);
		if(s.substr(max(0, i - 5), 6) == "eraser"){
			i -= 5;
		}else if(s.substr(max(0, i - 4), 5) == "erase"){
			i -= 4;
		}else if(s.substr(max(0, i - 6), 7) == "dreamer"){
			i -= 6;
		}else if(s.substr(max(0, i - 4), 5) == "dream"){
			i -= 4;
		}else{
			flag = false;
			break;
		}

	}
	if(flag)printf("YES\n");
	else printf("NO\n");
	return 0;
}