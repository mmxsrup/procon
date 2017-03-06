//ある高さX以下を保ちながら風船を割ることができるかという判定問題
/*
難点
-問題を読み替える部分。 ある高さXの時条件を満たすのかを調べる
-高さXまでに割らなければならない時間(それぞれの風船)をソートしておく
-ある高さを２分探索で探す部分。取り得るすべてのXを全て調べていたらTLE

解法
ある高さをXとするなら、(X - Hi) / Si　いないに割らなければならないということになる。　(X < Hiなら不可)
条件を満たす高さXを２分探索で求める
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

const int MAX_N = 100005;
const ll INF = 1e14;
ll n;
ll h[MAX_N], s[MAX_N];

bool binarySearch(ll mid){//midは決めた高さ
	vector<ll> limittime(n);//limittime[i]は風船iを高さXまでに割るためには何秒までに割らなければならないかを入れる
	rep(i, n){
		if(mid - h[i] < 0) return false;//この条件をn個の風船の中で少なくとも１つでも満たしたら、不可
		//limittime[i] = (X - H[i]) / S[i]を計算する
		limittime[i] = (mid - h[i]) / s[i];
	}
	//昇順にソート
	sort(all(limittime));
	//i番目風船を高さXまでに割るには、limittime[i]秒いないに割らなければならない
	//昇順limittime[i]をソートすることで、割らなければならない時間がきつい（タイトなもの）から見ていける。
	rep(i, n){//iはスタートからの経過時間
		//printf("%d %lld\n", i, limittime[i]);
		if(limittime[i] < i) return false; //割らなければならない時間を超えてしまっている。
	}
	return true;
}

int main(void){
	cin >> n;
	rep(i, n) scanf("%lld %lld", &h[i], &s[i]);

	//２分探索 leftは探索範囲の先頭要素 rightは末尾の次の要素を指定する。
	ll left = 0, right = INF;
	while(left < right){
		ll mid = (left + right) / 2;
		//printf("%lld %lld %lld \n", left, mid, right);
		//binarySearchのreturn == trueはもっとXを小さくできるということ
		if(binarySearch(mid) == false){
			left = mid + 1;//後半を探索
			//printf("left ; %lld\n", left);
		}
		else{
			right = mid;//前半を探索
			//printf("right ; %lld\n", right);
		}
	}
	printf("%lld\n", left);
	return 0;
}