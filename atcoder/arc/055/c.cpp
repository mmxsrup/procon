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
//#define int long long
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for (int i=(n)-1;i>=0;i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define REPS(i,f,n) for (int i=(f)-1;i>=(n);i--)
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

string s;
int size;
ll sum = 0;

void slove(int len_b){
	int a_c = (size - len_b) / 2;//文字列aとbの長さの和
	reps(j, 1, a_c){
		int len_a = j; //文字列aの長さ
		int len_c = a_c - j; //文字列cの長さ

		rep(k, len_a && 0 <= k && k <= size - 1){
			if (s[k] != s[size - a_c + k])//左型のaと右側のaの部分を比較
				return;
		}

		int tmp = len_a + len_b;
		reps(k, tmp, tmp + len_c){
			if (s[k] != s[k + a_c] && 0 <= k && k <= size - 1)//左側のcと右側のcを比較
				return;
		}

		sum++;//aとc全て一致したものを増やす
	}
}

int main (void){
	cin >> s;
	size = s.size();

	reps(i, 1, size - 1){
		if ((size - i) % 2 == 0)
			slove(i);//iは文字列bのながさ
	}
	printf("%lld\n", sum);

	return 0;
}