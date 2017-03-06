#include <iostream>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

//n^k (mod m)
ll pow_mod(ll n, ll k, ll m){
	if(k == 0){
		return 1;
	}else if(k % 2 == 1){
		return pow_mod(n, k - 1, m) * n % m;
	}else{
		ll t = pow_mod(n, k / 2, m);
		return t * t % m;
	}
}

int main(void){
	ll n, m, p; cin >> n >> m >> p;
	cout << pow_mod(n, p, m) << endl;
}