#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int n, k;
ll v[100010];

int syakutori(void){
	int ans = 0;
	int left = 0, right = 0;
	ll now = 1;//かけ算の合計
	for (right = 0; right < n; ++right){//右を伸ばせるだけのばす
		if(left > right) right = left;
		now *= v[right];
		if(k < now){
			ans = max(ans, right - left);
			now /= v[left];//kを超えたら、左を1のばす
			left++;
		}
	}
	return ans;
}

int main(void){
	cin >> n >> k;
	rep(i, n) cin >> v[i];
	rep(i, n){
		if(v[i] == 0){
			printf("%d\n", n);
			return 0;
		}
	}
	printf("%d\n", syakutori());
	return 0;
}