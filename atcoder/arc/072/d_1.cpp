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
 
ll X, Y;
 
bool flag = false;



void dfs(ll x, ll y, int cnt){
	// printf("%lld %lld \n", x, y);
	if(x <= 1 && y <= 1){
		if(cnt % 2) flag = true;
		return;
	}
 
	ll dx, dy;
	if(x >= 2){
		if(x % 2) dx = x - 1;
		else dx = x;
		dfs(x - dx, y + dx / 2, cnt + 1);
		if(dx >= 4){
			dx -= 2;
			dfs(x - dx, y + dx / 2, cnt + 1);
		}
 
	}
	if(y >= 2){
		if(y % 2) dy = y - 1;
		else dy = y;
		dfs(x + dy / 2, y - dy, cnt + 1);
 		if(dy >= 4){
 			dy -= 2;
 			dfs(x + dy / 2, y - dy, cnt + 1);
 		}
	}
	return;
}
 
int main(void){
	cin >> X >> Y;
	dfs(X, Y, 0);
	if(flag) printf("Alice\n");
	else printf("Brown\n");
 
	return 0;
}