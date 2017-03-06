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



int main(void){
	//come[i] := i人(自分をふくめて)で海にいくとき、ついてきてくれる友達の数
	int come[100010];

	rep(i, 100010) come[i] = 0;//0で初期化

	int n; scanf("%d", &n);
	rep(i, n){
		int a, b;
		scanf("%d %d", &a, &b);
		reps(j, a, b + 1){
			come[j]++;
		}
	}

	
	int ans = 0;
	reps(i, 2, 100010){
		//今調べているは自分も含めてi人であれば来てくれる友達が、
		//come[i]人いるいるので、come[i] + 1人がi人を超えているかを確かめる
		if(come[i] + 1 >= i){
			//自分も含めてi人であれば来てくれるという条件を満たすので、
			//実際に来てくれる友達の数はi-1人
			ans = max(ans, i - 1);
		}
	}
	printf("%d\n", ans);

	return 0;
}