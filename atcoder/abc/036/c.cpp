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
	int n;
	int num[1000000000];
	cin >> n;
	vint v(n);
	vint tmp(n);
	rep(i, n) scanf("%d", &v[i]);

	tmp = v;

	sort(all(v));

	int prv = v[0];
	num[v[0]] = 0;
	int cnt = 0;
	reps(i, 1, n){
		if(prv < v[i]){
			cnt++;
		}
		num[v[i]] = cnt;

		prv = v[i];
	}

	rep(i, n){
		printf("%d\n", num[tmp[i]]);
	}

	return 0;
}