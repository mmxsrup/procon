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
#define reps(i,f,n) for(int i=(f);i<(n);i++)
int h, w;
string s[55];
int dp[55][55][2][2];//dp[i][j][k][l] k=0 b k = 1 w l = 1つかった
int main(void){
	cin >> h >> w;
	ll ans = 0;
	rep(i, h) cin >> s[i];
	int cntb = 0, cntw = 0;
	rep(i, h)rep(j, w){
		if(s[i][j] == 'w') cntw++;
		if(s[i][j] == 'b') cntb++;
	}

	rep(i, 55)rep(j, 55)rep(k, 2)rep(l, 2) dp[i][j][k][l] = -1;

	rep(i, h){
		if(s[i][0] == 'b') dp[i][0][0][0] = 0;
		else if(s[i][0] == 'w') dp[i][0][1][0] = 0;
	}
	rep(i, w){
		if(s[0][i] == 'b') dp[0][i][0][0] = 0;
		else if(s[0][i] == 'w') dp[0][i][1][0] = 0;
	}
	
	reps(i, 1, h)rep(k, 2)rep(l, 2){
		if(dp[i - 1][0][k][l] == -1)continue;
		if(s[i][0] == 'b'){
			dp[i][0][0][1] = max(dp[i][0][0][1], dp[i - 1][0][1][0]);
			rep(u, 2)rep(v, 2){
				dp[i][0][0][0] = max(dp[i][0][0][0], dp[i - 1][0][u][v]);
				dp[i][0][0][0] = max(dp[i][0][0][0], dp[i - 1][0][u][v]);
			}
		}else{
			dp[i][0][1][1] = max(dp[i][0][1][1], dp[i - 1][0][0][0]);
			rep(u, 2)rep(v, 2){
				dp[i][0][1][0] = max(dp[i][0][1][0], dp[i - 1][0][u][v]);
				dp[i][0][1][0] = max(dp[i][0][1][0], dp[i - 1][0][u][v]);
			}
		}
	}
	reps(i, 1, w)rep(k, 2)rep(l, 2){
		if(dp[0][i - 1][k][l] == -1)continue;
		if(s[0][i] == 'b'){
			dp[0][i][0][1] = max(dp[0][i][0][1], dp[0][i - 1][1][0] + 1);
			rep(u, 2)rep(v, 2){
				dp[0][i][0][0] = max(dp[0][i][0][0], dp[0][i - 1][u][v]);
				dp[0][i][0][0] = max(dp[0][i][0][0], dp[0][i - 1][u][v]);
			}
		}else{
			dp[0][i][1][1] = max(dp[0][i][1][1], dp[0][i - 1][0][0] + 1);
			rep(u, 2)rep(v, 2){
				dp[0][i][1][0] = max(dp[0][i][1][0], dp[0][i - 1][u][v]);
				dp[0][i][1][0] = max(dp[0][i][1][0], dp[0][i - 1][u][v]);
			}
		}
	}


	rep(i, h)rep(j, w)rep(k, 2)rep(l, 2){
		printf("dp[%d][%d][%d][%d] = %d\n", i, j, k, l, dp[i][j][k][l]);
	}

	// printf("%d %d\n", dp[0][0][1][0], dp[0][0][0][1]);
	for (int i = 1; i < h; ++i){
		for (int j = 1; j < w; ++j){
			for (int k = 0; k < 2; ++k){
				for (int l = 0; l < 2; ++l){
					
					if(s[i][j] == 'b'){
						//選択
						if(dp[i][j - 1][1][0] != -1){
							dp[i][j][0][1] = max(dp[i][j][0][1], dp[i][j - 1][1][0] + 1);
						}
						if(dp[i - 1][j][1][0] != -1){
							dp[i][j][0][1] = max(dp[i][j][0][1], dp[i - 1][j][1][0] + 1);
						}
						//しない
						rep(u, 2)rep(v, 2){
							dp[i][j][0][0] = max(dp[i][j][0][0], dp[i - 1][j][u][v]);
							dp[i][j][0][0] = max(dp[i][j][0][0], dp[i][j - 1][u][v]);
						}
					}
					if(s[i][j] == 'w'){
						//選択
						if(dp[i][j - 1][0][0] != -1){
							printf("%d %d %d %d\n", i, j, k, l);
							dp[i][j][1][1] = max(dp[i][j][1][1], dp[i][j - 1][0][0] + 1);
						}
						if(dp[i - 1][j][0][0] != -1){
							printf("%d %d %d %d\n", i, j, k, l);
							dp[i][j][1][1] = max(dp[i][j][1][1], dp[i - 1][j][0][0] + 1);
						}
						//しない
						rep(u, 2)rep(v, 2){
							dp[i][j][1][0] = max(dp[i][j][1][0], dp[i - 1][j][u][v]);
							dp[i][j][1][0] = max(dp[i][j][1][0], dp[i][j - 1][u][v]);
						}
					}		
				}
			}
		}
	}

	printf("\n");
	rep(i, h)rep(j, w)rep(k, 2)rep(l, 2){
		printf("dp[%d][%d][%d][%d] = %d\n", i, j, k, l, dp[i][j][k][l]);
	}

	/*
	if(cntw < cntb) swap(cntw, cntb);
	int wan = cntw - cntb;
	ans += 10 * cntb;
	ans += wan;
	printf("%lld\n", ans);
	*/
	return 0;
}