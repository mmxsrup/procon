#include <cstdio>
#include <algorithm>

using namespace std;

const long long int mod = 1000000007;
int H, W;

long long a[1000][1000];
long long dp[1000][1000];

// 十時方向に動かすための配列
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

long long slove(int y, int x){
	//すでに計算ずみであれば即答えを返す
	if (dp[y][x] != -1)
		return dp[y][x];

	//計算がまだされていない
	for (int i = 0; i < 4; ++i)
	{
		//少なくとも一通りはある
		long long int res = 1;
		//十字方向を確かめる
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= H)
			continue;
		if (ny < 0 || ny >= W)
			continue;
		//フィールド内の時
		if (a[y][x] >= a[nx][ny])
			res = res + slove(nx, ny);
	}
	return dp[y][x] = res
}

int main(void){
	//入力
	scanf("%d %d", &H, &W);
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			scanf("%lld", a[i][j]);
		}
	}

	//初期化
	memset(dp, -1, sizeof(dp));
	ll ans = 0;

	//経路の合計を計算
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			ans += slove(i, j);
		}
	}

	printf("%lld\n", ans % mod);

	return 0;
}