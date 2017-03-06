#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

// 最大公約数
// ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

// 最小公倍数
ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }

int main(void){
	ll n, d; cin >> n >> d;

	/*
	if(n == d){
		printf("0\n");
		return 0;
	}else if(n % 2 == 1){
		printf("%lld\n", n - 1);
		return 0;
	}else if(n - d == 1){
		printf("%lld\n", n - 1);
		return 0;
	}
	*/
	printf("%lld\n", (lcm(n, d) / d) - 1);

	return 0;
}