//区間の両端だけを考えて解く方法
//わかりにくくて断念
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
	
	int come[100010];

	rep(i, 100010) come[i] = 0;

	int n; scanf("%d", &n);
	rep(i, n){
		int a, b;
		scanf("%d %d", &a, &b);
		come[a]++;
		come[b + 1]--;
	}

	int ans = 0;//最悪の場合は連れていける友達は0
	int sum = 1;//自分はまずいる
	rep(i, 100010){
		sum += come[i];
		if(i <= sum) ans = i;
	}
	printf("%d\n", --ans);

	return 0;
}