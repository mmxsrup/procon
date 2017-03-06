#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;	
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;

int n;
int money[(1 << 15)];//集合の時の合計金額を計算しておく
long long dp[(1 << 15)]; //dp[mask] := mask集合のときのしはらう金額の最小値を入れておく

bool contain(int mask, int position){
	if((mask & (1 << position)) != 0) return true;
	else return false;
}
 
int main(void){
	cin >> n;
	vector<int> v(n);
	rep(i, n) cin >> v[i];

	//金額のsum
	for(int mask = 0; mask < (1 << n); ++mask){
		money[mask] = 0;//初期化
		for (int j = 0; j < n; ++j){
			//jビット目が立っているとき
			if(contain(mask, j)) money[mask] += (v[j] % 1000);
			money[mask] %= 1000;
		}
	}
	// for (int mask = 0; mask < (1 << n); ++mask) cout << money[mask] << endl;
 
	dp[0] = 0;
	for (int mask = 1; mask < (1 << n); ++mask) dp[mask] = INF;
	for (int mask = 1; mask < (1 << n); ++mask){
		rep(i, n){
			//maskのibit目を0にしたものの金額の合計を引く
			int now = v[i] - money[mask ^ (1 << i)];
			if(now < 0) now = 0;
			dp[mask] = min(dp[mask ^ (1 << i)] + now, dp[mask]);
		}
	}
	cout << dp[(1 << n) - 1] << endl;
	return 0;
}