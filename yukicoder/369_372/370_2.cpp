#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
	int N, M;
	//int D[1010];
	int ans = 10000000; //ansを大きいめの値で初期化
	int sum = 0;

	//入力 N個を拾う
	scanf("%d %d", &N, &M);

	vector<int> D(M);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &D[i]);
	}

	//vectorのソートを行う 昇順にソート
	sort(D.begin(), D.end());

	for (int i = 0; i <= M - N; ++i)
	{
		//どちらも負から取りに行く時
		if (D[i] <= 0 && D[i + N - 1] >= 0)
		{
			sum = D[i] * -1; //D[i]の方が絶対値が大きい　i < i + N - 1
		//どちらも正から取りに行く時
		}else if(D[i] >= 0 && D[i + N - 1] >= 0){
			sum = D[i + N - 1];
		//正と負をどちらも取りに行く
		}else{
			sum = D[i + N - 1] - D[i] + min(D[i] * -1, D[i + N - 1]);
		}

		//　ans の更新
		if (sum < ans)
		{
			ans = sum;
		}
	}

	printf("%d\n", ans);
	return 0;
}





// まず正と負に分ける方法も

