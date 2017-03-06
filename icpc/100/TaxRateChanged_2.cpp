/*13 16 112 can not */
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
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
#define reps(i,f,n) for(int i=(f);i<(n);i++)

void slove(int pr, int ne, int sum){
	int ans = 0;
	reps(i, 1, sum + 100){//元の値段 +100は念のためある程度大きな所まで回すため
		reps(j, 1, sum + 100){//元の値段
			int pre1 = i * (100 + pr) / 100;
			int pre2 = j * (100 + pr) / 100;
			int presum = pre1 + pre2;//税率変更前の値段
			if(sum == presum){
				int tmp1 = i * (100 + ne) / 100;
				int tmp2 = j * (100 + ne) / 100;
				ans = max(ans, tmp1 + tmp2);//合計値が大きければ値を更新
			}
		}
	}
	printf("%d\n", ans);
	return;
}

int main(void){
	int x, y;
	int s;
	rep(i, 10000){
		scanf("%d %d %d", &x, &y, &s);
		if(x == 0 && y == 0 && s == 0) break;
		slove(x, y, s);
	}
	return 0;
}