
#include <iostream>
#include <algorithm>
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

int main(void){
	int n;cin >> n;
	vint a(n);
	rep(i, n) scanf("%d", &a[i]);

	ll sum = 0;
	rep(i, n){
		sum = sum * 2 + a[i];
	}
	printf("%lld\n", sum);
	return 0;
}