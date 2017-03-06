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

const ll mod = 1000000007;

int main(void){
	int n, K;
	cin >> n >> K;

	//LCM(a. b) = (a * b) / GCD(a, b);
	//GCD(i, K) = GCD(i % K, K) modを利用して効率よく計算する
	//ユークリットの互除法より
	//i = K * z + i % K (zは商)
	//K = i % K + (あまり)
	//上の２式よりGCD(i, K) = GCD(K, i % K)

	vector<ll> gcdmemo(K);//gcdmemo[i]にはiとKのgcdが入ってる
	rep(i, K){//iはmod(K)の値
		gcdmemo[i] = __gcd(i, K);//gcd(0, K)のgcdはK
	}

	ll sum = 0;
	reps(i, 1, n + 1){
		sum += ((i * K) / gcdmemo[i % K]) % mod;
	}
	printf("%lld\n", sum % mod);
	return 0;

}