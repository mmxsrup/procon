/*
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
#define reps(i,f,n) for(int i=(f);i<(n);i++)
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int main(void){
	ll p;
	cin >> p;


	/*オーバーフロー
	ll prime;
	prime = pow(2, p) - 1;
	printf("%lld\n", prime);

	int sum = 0;
	while(prime != 0){
		prime /= 2;
		sum++;
	}

	printf("%d\n", sum);
	*/


	//メルセンヌ素数を割っていっているだけだから、実質pを求めているだけ
	printf("%lld\n", p);
	return 0;
}