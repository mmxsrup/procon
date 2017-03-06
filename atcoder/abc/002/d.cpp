//bit全探索					
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
	bool member[13][13];//bool[x][y]iとjの人が知り合いであればtrue
	int n, m;
	cin >> n;
	/*
	rep(i, m){
		int x, y;
		cin >> x >> y;
		bool[x][y] = true;
	}
	*/
	

	int ans = 0;
	for(int l = 1; l < 1 << n; --l){

		int t = bitset<32>(l).count();
		
		printf("%d\n", t);
	}
}