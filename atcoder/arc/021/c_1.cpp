/*
priority_queueを利用して、小さいものを見つける部分を高速化
*/
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
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;

#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int K, N;
int AD[101010][3];
ll sum = 0;

int main(void){
	scanf("%d %d", &K, &N);
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < 2; ++j)
			scanf("%d", &AD[i][j]);
	}

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >que;

	rep(i, N)
		que.push(pair<int, int>(AD[i][0], i)); //queのfiには価格、queのseには入れた回数の番号
	rep(i, K){
		pair<int, int> q_tmp = que.top(); //値をtmp
		que.pop();
		sum += q_tmp.fi;
		q_tmp.fi += AD[q_tmp.se][1]; //価格を更新
		que.push(q_tmp);
	}

	printf("%lld\n", sum);
	return 0;
}