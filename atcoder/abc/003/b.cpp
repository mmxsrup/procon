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
	string s, t; cin >> s >> t;
	rep(i, s.size()){
		bool flag = true;
		if(s[i] != '@' && t[i] != '@' && s[i] != t[i]){
			flag = false;
		}else if(s[i] == '@' && t[i] != '@'){
			bool d = false;
			for(auto c : "atcoder"){
				if(t[i] == c) d = true;
			}
			if(d == false) flag = false;
		}else if(s[i] != '@' && t[i] == '@'){
			bool d = false;
			for(auto c : "atcoder"){
				if(s[i] == c) d = true;
			}
			if(d == false) flag = false;
		}
		if(flag == false){
			printf("You will lose\n");
			return 0;
		}
	}
	printf("You can win\n");
	return 0;
}