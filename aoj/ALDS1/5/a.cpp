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

int a[51];
int n;

//入力値のtmp(m) から選んだ要素を引いていく再帰関数
bool slove(int i, int m){
	if(m == 0) return true;//m=0は和がmになったことを示している
	if(i >= n) return false;//iがnより大きくなってしまったら、できてない
	/*
	 slove(i + 1 , m)はi番目のmを選ばない時
	 slove(i + 1, m - A[i])はi番目のmを選ぶ時
	 ||　はどちらかで成り立っていれば良いよいうことor
	*/
	return (slove(i + 1, m) || slove(i + 1, m - a[i]));//分割

}

int main(void){
	int q;
	cin >> n;
	rep(i, n) scanf("%d", &a[i]);
	cin >> q;
	rep(i, q){
		int tmp;
		cin >> tmp;
		if (slove(0, tmp)) printf("yes\n");
		else printf("no\n");
	}

	return 0;
}