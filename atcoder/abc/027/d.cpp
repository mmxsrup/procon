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
	int size = s.size();
	//dp[何文字][座標] = 幸福度の最大値
	int dp[1010][1010];
	rep(i, 1010) rep(j, 1010) dp[i][j] = -INF;

	//座標はマイナス方向にも動くのでdp[][505]　505を座標0とする
	dp[0][505] = 0;//0文字と座標0で幸福度は0(初期値)
	reps(i, 1, size + 1){
		char c = s[i - 1];
		rep(j, 1010){
			if(dp[i - 1][j] != -INF){
				if(c == '+'){
					dp[i][j] = max(dp[i][j], dp[i - 1][j] + j - 505);
				}
				else if(c == '-'){
					dp[i][j] = max(dp[i][j], dp[i - 1][j] - j + 505);
				}
				else{//２つの選択肢あり
					dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j]);
					dp[i][j - 1] = max(dp[i][j - 1], dp[i - 1][j]);
				}
			}
		}
	}
	
	printf("%d\n", dp[size][505]);
	return 0;
}