//dp
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<pint> vpint;
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for (int i=(n)-1;i>=0;i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define REPS(i,f,n) for (int i=(f)-1;i>=(n);i--)
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
const int INF = 1e9;
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