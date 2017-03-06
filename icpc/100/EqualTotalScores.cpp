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
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

void slove(int n, int m){
	vint vtaro(n);//太郎くんの数字の組みを入れる配列
	vint vhana(m);//花子さんの数字の組みを入れる配列
	int sumtaro = 0, sumhana = 0;
	rep(i, n){
		int tmp;
		scanf("%d", &tmp);
		sumtaro += tmp;
		vtaro[i] = tmp;
	}
	sort(all(vtaro));//最小の組みを求めやすいようにソートしておく

	rep(i, m){
		int tmp;
		scanf("%d", &tmp);
		sumhana += tmp;
		vhana[i] = tmp;
	}
	sort(all(vhana));

	double sa = sumtaro - sumhana; //合計値の差
	//組みの和が小さくなるものから求めるように全探索する。
	rep(i, n){
		rep(j, m){
			if (vtaro[i] - vhana[j] == (sa / 2)){
				//入れかえて和が同じになるには、上の条件式を満たせばいい
				printf("%d %d\n", vtaro[i], vhana[j]);
				return;
			}
		}
	}
	printf("-1\n");
	return;
}

int main(void){
	int n, m;
	rep(i, 1000){
		cin >> n >> m;

		if (n == 0) break;
		slove(n, m);
	}
	return 0;
}