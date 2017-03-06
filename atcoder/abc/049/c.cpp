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
	string s; cin >> s;
	rep(i, s.size() - 1){
		if(s[i] == 'e'){
			string d1 = s.substr(i, 6);
			string d2 = s.substr(i, 5);
			if(d1 == "eraser"){
				i += 6;
			}else if(d2 == "erase"){
				i += 5;
			}else{
				printf("NO\n");
				return 0;
			}
		}else if(s[i] == 'd'){
			string d1 = s.substr(i, 7);
			string d2 = s.substr(i, 5);
			if(d1 == "eraser"){
				i += 6;
			}else if(d2 == "erase"){
				i += 5;
			}else{
				printf("NO\n");
				return 0;
			}
		}
	}
	return 0;
}