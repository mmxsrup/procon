#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <cstdio>
using namespace std;
#define mp make_pair
#define fi first
#define se second	
#define rep(i,n) for(int i=0;i<(n);i++)

int n, m;
bool flag[(1 << 16)];//flagの桁数めのbitが立っている時(1)
long long dp[(1 << 16)];
//&演算子を用いて、現在見ているmaskに対して、position桁目が1かどうかを見ている
bool contain(int mask, int position){
	if((mask & (1 << position)) != 0) return true;
	else return false;
}

int main(void){
	scanf("%d %d", &n, &m);
	vector<pair<int, int> > inf;
	rep(i, m){
		int x, y; scanf("%d %d", &x, &y);
		x--; y--;//0オリジン
		inf.push_back(mp(x, y));
	}

	//与えられた情報に矛盾しない集合を探す
	for(int mask = 0; mask < (1 << n); ++mask){
		flag[mask] = true;//初期化
		rep(i, m){//与えられた情報をすべて確認
			//集合が矛盾している

			if(contain(mask, inf[i].se) == true && contain(mask, inf[i].fi) == false){
				//printf("mask %d fi %d se %d\n", mask, inf[i].fi, inf[i].se);
				flag[mask] = false;
			}
		}
	}

	/*
	for(int mask = 0; mask < (1 << n); ++mask){
		if(flag[mask] == true) printf("%d true\n", mask);
		else printf("%d false\n", mask);
	}
	*/


	dp[0] = 1;//空集合の時は0! = 0で場合の数は0通り
	for (int mask = 1; mask < (1 << n); ++mask){
		//集合が与えられた条件を見たしている時
		if(flag[mask] == true){
			rep(i, n){
				//集合が条件を満たすもので、maskのiビット目が1である時
				if(contain(mask, i) == true && flag[mask ^ (1 << i)] == true){
					//maskのibit目を0にしたものの場合の数を足す
					//printf("seikai %x\n", mask);
					// printf("mask %d dp %lld\n", mask, dp[mask ^ (1 << i)]);
					dp[mask] += dp[mask ^ (1 << i)];
					// printf("dp %lld\n", dp[mask]);
				}
			}
		}
	}
	printf("%lld\n", dp[(1 << n) - 1]);
	return 0;
}