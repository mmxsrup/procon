/*
__gcd使える？？
*/

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
#define REP(i,n) for (int i=(n)-1;i>=0;i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define REPS(i,f,n) for (int i=(f)-1;i>=(n);i--)
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int main(void){
	int n;
	cin >> n;
	vector<int> a(n);

	rep(i, n)
		cin >> a[i];

	int tmp;
	tmp = a[0];
	reps(i, 1, n)
		tmp = __gcd(tmp, a[i]);

	int sum = 0;
	rep(i, n){
		a[i] = a[i] / tmp;
		sum += a[i];
	}

	printf("%d\n", sum);
	return 0;

}