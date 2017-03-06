#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

int main(void){
	int d, n;
	cin >> d >> n;
	vector<int> t(d);
	rep(i, d) cin >> t[i];
	vector<int> a(n), b(n), c(n);
	rep(i, n) cin >> a[i] >> b[i] >> c[i];
	vector<bool> flag[201][201];//flag[i][j]=true i日目にj番目の服が着れる
	rep(i, d) rep(j, n){
			if(a[j] <= t[i] && t[i] <= b[j])
				flag[i][j] = true;
	}

	int dp[201][101];
	rep(i, n)

}