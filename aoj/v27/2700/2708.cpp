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

string s;
int main(void){
	cin >> s;
	vector<int> v;
	if(s.size() >= 3){
		rep(i, s.size() - 2) if(s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')v.pb(i);
	}else{
		printf("No\n");
		return 0;
	}
	
	if(v.size() >= 2){
		rep(i, v.size() - 1){
			if(v[i + 1] - v[i] == 3){
				printf("No\n");
				return 0;
			}
		}
	}
	

	while(s.size() >= 3 && s != "ABC"){
		bool flag = false;
		rep(i, s.size() - 2){
			if(s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C'){
				string s1 = s.substr(0, i);
				string s2 = s.substr(i + 3);
				// cout << "s1 " << s1 << " s2 " << s2 << endl;
				if(s1.size() == 0) s = s1 + 'A' + s2;
				else if(s2.size() == 0) s = s1 + 'C' + s2;
				else if(s1.back() == 'A') s = s1 + 'B' + s2;
				else if(s1.back() == 'B') s = s1 + 'C' + s2;
				flag = true;
			}
		}
		// cout << s << endl;	
		if(!flag){
			printf("No\n");
			return 0;
		}
	}
	if(s == "ABC") printf("Yes\n");
	else printf("No\n");
	return 0;
}