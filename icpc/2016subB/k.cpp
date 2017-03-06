#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
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
#define reps(i,f,n) for(int i=(f);i<(n);i++)


int main(void){
	int m;
	cin >> m;
	rep(i, m){
		double menseki;
		cin >> menseki;
		double hen = sqrt(menseki);
		double ans = hen * sqrt(2) / 2;
		printf("%.8f\n", ans);
	}
	return 0;
}