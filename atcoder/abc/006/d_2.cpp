/*
動的計画法を使う
左から順番に最後にそのカードを使った時の、最大の長さはいくつか計算していく　メモっていく
次の値は前の値を利用して最大値から計算する
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
#include <list>
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
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int main(void){
	int n;
	scanf("%d", &n);
	//dp[i]は添え字の番号目のカードまでで、できる単調増加になる数字の個数
	vector<int> v(n), dp(n);
	rep(i, n){
		scanf("%d", v[i]);
		dp[i] = 1; //i番目の数は選ぶので少なくとも１つはある

		reps(i, 1, N){
			reps(j, i, N){
				if (v[i] > v[j])
				{
					max[]
				}
			}
		}
	}



	#include <iostream>
#include <algorithm>
using namespace std;
 
int N;
int c[30010];
int dp[30010];
 
int main() {
  cin >> N;
  for (auto i = 0; i < N; i++) {
    cin >> c[i];
  }
  fill(dp, dp+30010, 1);
  for (auto i = 1; i < N; i++) {
    for (auto j = 0; j < i; j++) {
      if (c[j] < c[i]) {
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
  }
  int maxi = 0;
  for (auto i = 0; i < N; i++) {
    maxi = max(maxi, dp[i]);
  }
  cout << N - maxi << endl;
}



}