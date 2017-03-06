/*
全探索
再帰関数
XOR
*/

#include <cstdio>
#include <algorithm>
#include <string>
#include <vector> 
#include <functional>
#include <bitset>
using namespace std;

typedef long long ll;

int T[10][10];
int N, K;

// numQは(何個目 - 1)の質問であるか
// valueはXORの値
bool XOR(int numQ, int value){
	if (numQ == N) //N回の質問が終わっていたら
	{
		return (value == 0);
	}

	for (int j = 0; j < K; ++j)
	{
		/*ループを利用することによって、一度にK回の再帰を行う　それがnumQ==Nに成るまで続く　K*K*+K。。。で増えてく*/
		if (XOR(numQ + 1, value ^ T[numQ][j]))
		{
			return true;
		}
	}
	return false;
}

int main(void){

	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			scanf("%d", &T[i][j]); //i:N  j:K
		}
	}

	if(XOR(0, 0)){
		printf("Found\n");
	}else{
		printf("Nothing\n");
	}

	return 0;
}