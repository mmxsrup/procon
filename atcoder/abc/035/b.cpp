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
	string s; int t; cin >> s >> t;
	int x = 0, y = 0, nazo = 0;
	for(auto u : s){
		if(u == 'L') x--;
		else if(u == 'R') x++;
		else if(u == 'U') y++;
		else if(u == 'D') y--;
		else nazo++;
	}
	x = abs(x), y = abs(y);
	if(t == 1){
		printf("%d\n", x + y + nazo);
	}else{
		if(x + y >= nazo){
			printf("%d\n", x + y - nazo);
		}else{
			if((nazo - x - y) % 2 == 0) printf("0\n");
			else printf("1\n");
		}
	}
	return 0;
}