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

/* 
+
-
*
/ 4 / 3 = 1
% 4 % 2 = 0
*/
int main(void){
	int cnt = 0;
	for (int i = 2; i <= 10000000; ++i){ // i
		bool flag = 1; // flag := 1なら素数 0 素数じゃない
		for (int x = 2; x * x <= i; ++x){ // iがxで割れるかどうか
			if(i % x == 0){
				flag = 0;
				break;
			}
		}
		if(flag == 1) cnt++;
		if(cnt == 10001){
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}