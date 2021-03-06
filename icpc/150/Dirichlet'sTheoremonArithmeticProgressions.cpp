/*1 1 1で　１を出力してしまった*/
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
#define REP(i,n) for (int i=(n)-1;i>=0;i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define REPS(i,f,n) for (int i=(f)-1;i>=(n);i--)
int dx[8] = {1, 0, 0, -1, 1, 1, -1, -1};
int dy[8] = {0, 1, -1, 0, 1, -1, 1, -1};

int a, d, n;

void slove(void){
	int cnt = 0;
	int now = a;

	while(cnt != n){
		bool flag = true;//素数かどうかを判定flag
		for (int i = 2; i * i <= now ; ++i){
			if (now % i == 0){
				flag = false;//素数ではない
				break;
			}
		}
		/*1は素数ではないが上の素数判定では1もtrueとしてしまうので、now != 1を追加した*/
		if (flag == true && now != 1) cnt++;//素数発見
		now += d;//等差数列を進める
	}

	printf("%d\n", now - d);//最後に+dしてしまってるのでマイナスしておく
	return;
}

int main(void){
	rep(i, 1000){
		scanf("%d %d %d", &a, &d, &n);
		if (a == 0) break;
		slove();
	}
	return 0;
}