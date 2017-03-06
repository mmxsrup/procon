#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
int b[110][110];
ll memo[110][110];
int main(void){
	int h, w; cin >> h >> w;
	rep(i, h)rep(j, w) cin >> b[i][j];
	rep(i, h)rep(j, w){
		if((i + j) % 2 == 0){
			b[i][j] *= -1;
		}
	}
	rep(i, h) memo[i][0] = 0;
	rep(i, w) memo[0][i] = 0;
	rep(i, h)rep(j, w){//横の累積和
		memo[i + 1][j + 1] += memo[i + 1][j] + b[i][j];
	}
	rep(i, w)rep(j, h){//2次元累積和
		memo[j + 1][i + 1] += memo[j][i + 1];
	}

	int ans = 0;
	/*
	(i, j)------------|
	|				  |
	|
	|--------------(y, x)
	*/
	reps(i, 1, h + 1)reps(j, 1, w + 1){
		reps(y, i, h + 1)reps(x, j, w + 1){
			ll sum = memo[y][x];
			sum -= memo[i - 1][x];
			sum -= memo[y][j - 1];
			sum += memo[i - 1][j - 1];
			if(sum == 0){
				ans = max(ans, (y - i + 1) * (x -  j + 1));
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}