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
	
int h, a, d;

double dp[100010];
//dp[i] := これまでの攻撃が i のとき、合計が k になるまでに攻撃する回数の期待値

int main(void){
	cin >> h >> a >> d;
	rep(i, 100010) dp[i] = INF;
	dp[0] = 0;
   	for (int i = 1; i <= h; ++i){
   		dp[i] = min(dp[max(0, i - a)] + 1.0, dp[max(0, i - d)] + 1.5);
   	}
    printf("%f\n", dp[h]);

    return 0;
}
