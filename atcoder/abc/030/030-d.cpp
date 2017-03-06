#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector> 
#include <functional>
using namespace std;

typedef long long ll;

int N, a; //aは探しているもの
int word[100010];
//この配列flagは０で初期化してさらに０以外の数字が入っている時何回目のステップできたかがわかるようにするためのもの
//例：　flag[4] = 3　の時　word[4] に３回目に訪れたことがある
int flag[100010]; 
int looking;
ll k;

int main(void){
	int eda, jyunkan, len;
	//入力
	scanf("%d %d", &N, &a);
	scanf("%lld", &k);
	for (int j = 0; j < N; ++j)
	{
		scanf("%d", &word[j]);
	}

	//flag用の配列を０で初期化
	for (int i = 0; i < N; ++i)
	{
		flag[i] = 0;
	}

	//０回めに訪れている　（上で初期化してるので意味はないが）
	flag[a - 1] = 0;
	//初期に探すもの
	looking = a;

	/*周期の取得など*/
	for (int i = 1; i <= N; ++i) //iは何回目のステップであるかを表している
	{
		looking = word[looking - 1]; //探すものを更新していく
		if (flag[looking - 1] != 0)
		{
			//０でないということはすでにこの単語を調べたことがあることを意味する
			eda = flag[looking - 1]; //枝
			jyunkan = i - flag[looking - 1]; //循環数
			len = i; //閉路にとうたつするまでの長さ
		}else{
			//初見です
			flag[looking - 1] = i; //i番目の訪れたことをメモしていく
		}
	}

	//kがものすごく大きいのでどうするか
	int ans;
	if (jyunkan == 0)
	{
		ans = a;
		for (int i = 0; i < len; ++i)
		{
			ans = word[ans];
		}
	}else{
		ans = looking - 1;
		for (int i = 0; i < (len + 1 - eda) % jyunkan; ++i)
		{
			ans = word[ans];
		}
	}
	printf("%d\n", ans);

	return 0;
}
