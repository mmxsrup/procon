/*
二分探索は最初データの全体を探索の範囲とするので、left を 0 に、right を要素数 N に初期化します。
left = mid + 1
right = mid
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

int s[101010];
int n, q;
ll sum = 0;

bool binarysearch(ll key){
	int left = 0;
	int right = n; //right = n - 1だとダメ
	int mid;
	while(left < right){
		mid = (left + right) / 2;
		if(key == s[mid])
			return true;
		else if(key > s[mid])
			left = mid + 1;
		else
			right = mid;
	}
	return false;
}

int main(void){
	cin >> n;

	rep(i, n)
		cin >> s[i];	
	//sort(all(s));
	cin >> q;

	rep(i, q){
		ll k;
		cin >> k;
		if (binarysearch(k))
			sum++;
	}

	printf("%lld\n", sum);
	return 0;

}
