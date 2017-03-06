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

int main(void){
	int x, y; cin >> x >> y;
	vector<int> a(3);
	rep(i, 3) a[i] = x;
	sort(a.begin(), a.end());

	ll cnt = 0;
	while(!(a[0] == y && a[1] == y && a[2] == y)){
		cnt++;
		sort(all(a));
		printf("%d %d %d\n", a[0], a[1], a[2]);
		int maxx = a[2], midd = a[1], minn = a[0];
		if(midd - minn + 1 <= y){
			maxx = y;
		}else{
			// a[0] = a[2] - a[1] + 1;
			maxx = midd - minn + 1;
		}
		a[0] = minn; a[1] = midd; a[2] = maxx;
	}
	cout << cnt << endl;
	return 0;
}