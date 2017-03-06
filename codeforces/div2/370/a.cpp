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
#define reps(i,f,n) for(int i=(f);i<(n);i++)

int a[100010];
int main(void){
	ll n; cin >> n;
	vector<ll> ans;
	rep(i, n){
		cin >> a[i];
	}
	ll now = 0;
	ll b1 = 0;
	ll b2 = 0;
	for (int i = n - 1; i >= 0; --i){
		if(i % 2 == 0){//奇数番目
			ll t = a[i] - b1 + b2;
			ans.push_back(t);
			b1 += t;
		}else{
			ll t = a[i] + b1 - b2;
			ans.push_back(t);
			b2 += t;
		}
	}
	for (int i = ans.size() - 1; i >= 0; --i){
		printf("%I64d ", ans[i]);
	}
	printf("\n");
	return 0;
}