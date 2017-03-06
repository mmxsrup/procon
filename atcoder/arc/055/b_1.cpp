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
//#define int long long
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for (int i=(n)-1;i>=0;i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define REPS(i,f,n) for (int i=(f)-1;i>=(n);i--)
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

double dp[1010][1010][2];

int main(void){
	int N, K;

	cin >> N >> K;
	/* dp[どの場所まで来たか][何個のせんべいを食べたか][今ままでのmaxを食べたか]*/
	/* dpの値は条件を満たせる時の確率の最大値*/

	rep(i, K + 1)
		dp[N][i][0] = 0.0;//条件を満たせない確率は0
	rep(i, K + 1)
		dp[N][i][1] = 1.0;//今までの最大値を食べているので、条件を満たし確率は１

	for (int i = N - 1; i >= 0; --i) rep(j, K + 1) rep(k, 2){
		double p = 1.0 / (i + 1.0);//i + 1回目に出されたせんべいが今までに出てきた、i個のせんべいより大きい確率

		/*確率漸化式
		(1.0 - p) * dp[i + 1][j][K] i + 1回目に今までより大きなものが出てこない時は i + 1個目のせんべいは食べないという選択肢一択

		p * max(dp[i + 1][j + 1][1], dp[i + 1][j][0])
			p * dp[i + 1][j + 1][1]  i + 1回目に今までの中で１番大きなものが出てきたので、それを食べる時の確率
			p * dp[i + 1][j][0]  i + 1回目に今までで、１番大きなものが出てきたが、選ばない
			これらの２つの確率の中で確率が大きくなるものを選べばいい
		*/
		double tmp = (1.0 - p) * dp[i + 1][j][K] + p * max( dp[i + 1][j + 1][1], dp[i + 1][j][0] );
		dp[i][j][k] = tmp;
	}

	double ans = dp[0][0][0];
	printf("%.9f\n", ans);

	return 0;
}