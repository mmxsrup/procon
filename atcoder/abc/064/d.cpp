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

int me[110];
int main(void){
	int n; cin >> n;
	string s; cin >> s;
	rep(i, s.size()){
		reps(j, i, s.size()){
			if(s[i] == '(' && s[j] == ')' && me[i] == 0 && me[j] == 0 ){
				me[i] = me[j] = 1;
			}
		}
	}
	int r = 0, l = 0;
	rep(i, s.size()){
		if(me[i] == 0){
			if(s[i] == '(') r++;
			else l++;
		} 
	}
	rep(i, l) s = '(' + s;
	rep(i, r) s = s + ')';
	cout << s << endl;
	return 0;
}