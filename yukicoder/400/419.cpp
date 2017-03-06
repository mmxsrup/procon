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
	double a, b; cin >> a >> b;
	if(a < b) swap(a, b);
	double ans = 1e12;
	if(a == b){
		ans = sqrt(a * a + b * b);
		printf("%.9f\n", ans);
		return 0;
	}
	double tmp = sqrt(a * a + b * b);
	ans = min(ans, tmp);
	tmp = sqrt(a * a - b * b);
	ans = min(ans, tmp);
	printf("%.9f\n", ans);
	return 0;
}