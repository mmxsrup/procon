#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e6;
int dp[35];//dp[i] := 長さiの板を作るのに、必要な最小の枚数

int main(void){
	int v[4];
	rep(i, 4) cin >> v[i];

	int ita[3], ans = INF;
	for (int a = 1; a <= 30; ++a){//a,b,cを全探索
		for (int b = a + 1; b <= 30; ++b){
			for (int c = b + 1; c <= 30; ++c){

				ita[0] = a; ita[1] = b; ita[2] = c;
				rep(i, 35)dp[i] = INF;//-1は作れない
				dp[a] = 1; dp[b] = 1; dp[c] = 1;//初期化

				for (int y = 0; y < 3; ++y){//使う板
					for (int x = 1; x <= 30; ++x){
						if(x - ita[y] > 0){
							dp[x] = min(dp[x], dp[x - ita[y]] + 1);
						}
					}
				}

				int now = 0;
				rep(i, 4){
					if(dp[v[i]] != -1){
						now += dp[v[i]];
					}else{
						break;
					}
					if(i == 3){
						ans = min(now, ans);//v[0]~v[3]まで作れた
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}