#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <bitset>
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
	int n; cin >> n;
	vector<int> v(n);
	rep(i, n){
		scanf("%d", &v[i]);
	}
	int cnt = 0;
	rep(i, n - 1){
		if(v[i] > v[i + 1]) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}