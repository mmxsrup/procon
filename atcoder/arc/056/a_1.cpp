#include <iostream>
using namespace std;
typedef long long ll;

int main(void){
	ll a, b, k, l;
	cin >> a >> b >> k >> l;
	ll ans = 1e12;
	ans = min(ans, a * k);//1つだけを大量にかう
	ans = min(ans, b * (k / l + 1));//セットだけで買う
	//1つとセット合わせて買う
	ll tmp = a * (k % l) + b * (k / l);
	ans = min(ans, tmp);
	cout << ans << endl;
	return 0;
}