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
	double x = 20;
	double ans = (x * x+ 4.0) / 8.0;
	int x1 = ans;
	double x2 = (x1 * x1 + 4.0) / 8.0;
	int x3 = x2;
	double x4 = (x3 * x3 + 4.0) / 8.0;
	printf("%d\n", int(x4));

	return 0;
}