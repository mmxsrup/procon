
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
	int n, t; cin >> n >> t;
	ll sum = 0;
	vint a(n);
	vint b(n);
	rep(i, n){
		cin >> a[i] >> b[i];
	}
	rep(i, n) sum += a[i];
	vint c(n);
	rep(i, n) c[i] = a[i] - b[i];
	sort(all(c));
	reverse(all(c));
	ll nokori = sum - t;
	ll cnt = 0;
	rep(i, n){
		if(nokori <= 0) break;
		nokori -= c[cnt];
		cnt++;
	}
	if(nokori > 0){
		printf("-1\n");
		return 0;
	}
	printf("%lld\n", cnt);
	return 0;

}