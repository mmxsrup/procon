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
	int pura = 0, maina = 0;
	cin >> n;

	vint v(n);
	rep(i, n) v[i] = -1;

	rep(i, n){
		char tmp;
		cin >> tmp;

		if ('0' <= tmp && tmp <= '9'){
			v.push_back(tmp - '0');
		}else if (tmp == '-'){
			maina++;
		}else if (tmp == '+'){
			pura++;
		}
	}
	sort(all(v));
	reverse(all(v));
	//大きい順

	int sum_kigou = pura + maina;//作らないければならない数字の組みの数sum_kigou + 1
	int sum_num = n - sum_kigou;
	//最大の整数を作る桁数
	int maxketa = sum_num - (sum_kigou);
	
	baisuu = 10 * (maxketa - 1);
	ll ma = 0;
	rep(i, maxketa){
		ma += baisuu * v[i];
		baisuu /= 10;
	}

	ll ans_max;
	rep(i, )
}