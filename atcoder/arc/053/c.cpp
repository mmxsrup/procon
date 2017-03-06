#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector> 
#include <functional>
using namespace std;

typedef long long ll;

int main(void){
	int N;
	//入力
	scanf("%d", &N);
	long long int a[100010];
	long long int b[100010];

	//vectorの宣言
	vector<pair<ll, ll> > down, same, up;

	//入力
	for (int i = 0; i < N; ++i)
	{
		scanf("%lld %lld", &a[i], &b[i]);
	}

	//上がるものと下がるものを分ける
	for (int i = 0; i < N; ++i)
	{
		if (a[i] < b[i])
		{
			down.push_back(make_pair(a[i], b[i]));
		}else if(a[i] == b[i]){
			same.push_back(make_pair(a[i], b[i]));
		}else{
			//ソートのためにbを前に入れる
			up.push_back(make_pair(b[i], a[i]));
		}
	}

	//ソートを行う
	//downはaが小さい順にできればいい
	sort(down.begin(), down.end());
	//upはbが大きい順にできればいい
	sort(up.begin(), up.end());
	reverse(up.begin(), up.end());

	ll ans = 0;
	ll now = 0;
	
	//最大を求める
	/*
 	1 down
 	2 same(無視していい)
 	3 up 
 	の順番で
	*/
	for (int i = 0; i < down.size(); ++i)
	{
		//最大値を計算
		ans = max(ans, now + down[i].first);
		//実際の位置を計算
		now += down[i].first - down[i].second;
	}
	for (int i = 0; i < same.size(); ++i)
	{
		//最大値の計算
		ans = max(ans, now + same[i].first);
		//実際の位置を計算
		now += same[i].first - same[i].second;
	}

	for (int i = 0; i < up.size(); ++i)
	{
		//最大値を計算
		ans = max(ans, now + up[i].second);
		//実際の位置を計算
		now += up[i].second - up[i].first;
	}

/*
	for (int i = 0; i < down.size(); ++i)
	{
		printf("%lld %lld\n", down[i].first, down[i].second);
	}
	for (int i = 0; i < up.size(); ++i)
	{
		printf("%lld %lld\n", up[i].first, up[i].second);
	}
	printf("\n");
*/
	//int tmp = down.size();
	//int tmp1 = down.size();
	//printf("%d %d\n", tmp, tmp1);
/*
	for (int i = 0; i < down.size(); ++i)
	{
		printf("%lld %lld\n", down[i].first, down[i].second);
	}
	for (int i = 0; i < up.size(); ++i)
	{
		printf("%lld %lld\n", up[i].first, up[i].second);
	}
*/	
	printf("%lld\n", ans);

	return 0;
}