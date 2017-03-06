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
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;

int main(void){
	string s; 
	getline(cin, s);
	vector<int> dd, rr;
	int l = 0;
	while(l < s.size()){
		string t;
		while(s[l] != ' '){
			t += s[l]; 
			l++;
		}
		cout << t << endl;
		auto d = atoi(t);
		if(d > 0){
			dd.pb(d);
		}else{
			rr.pb(d);
		}
	}
	if(dd.size() == 1){
		printf("%d\n", dd[0]);
	}else{
		printf("%d\n", rr[0]);
	}	
	return 0;
}