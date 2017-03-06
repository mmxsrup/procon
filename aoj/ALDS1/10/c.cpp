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

int slove(string X, string Y){
	int dp[1000][1000];//dp[Xの長さ][Yの長さ] = LCS
	int sizex = X.size();
	int sizey = Y.size();

	//添字が文字の長さになるように、添字0に空白文字を入れる。
	X = ' ' + X;
	Y = ' ' + Y;

	reps(i, 0, sizex + 1) dp[i][0] = 0;//一方の文字列が0ならdpは0
	reps(i, 0, sizey + 1) dp[0][i] = 0;//一方の文字列が0ならdpは0

	int ans = 0;//最小の答え
	reps(i, 1, sizex + 1){
		reps(j, 1, sizey + 1){
			if(X[i] == Y[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else if(X[i] != Y[j]) dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

			ans = max(ans, dp[i][j]);
		}
	}
	return ans;
}

int main(void){
	int n; cin >> n;
	string s1, s2;
	rep(i, n){
		cin >> s1 >> s2;
		printf("%d\n", slove(s1, s2));
	}
	return 0;
}