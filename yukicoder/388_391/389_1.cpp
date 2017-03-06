#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <numeric>
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
static const int MOD =1000000007;

int h[1000];
int main(void){
	int m; cin >> m;
	vector<int> h;
	string s;
	cin.ignore();
	getline(cin, s);
	stringstream ss(s);
    int x;
    while (ss >> x) h.emplace_back(x);
    ll cnt = h.size();
    ll sum = accumulate(all(h), 0);
    printf("cnt%lld sum%lld\n", cnt, sum);
    if(sum == 0) {
    	printf("0\n");
    	return 0;
    }
    if(m - sum + 1 < cnt){
    	printf("NA\n");
    	return 0;
    }
    if(sum = m){
    	printf("1\n");
    	return 0;
    }
  
    ll bunnsi = 1;
	ll bunnsitmp = cnt + 1;
	while(bunnsitmp > 0){
		bunnsi *= bunnsitmp % MOD;
		bunnsi %= MOD;
		bunnsitmp--;
	}
	printf("bunnsi%lld\n", bunnsi);
	ll bunnbo = 1;
	ll bunnbotmp = m - sum;
	while(bunnbotmp > 0){
		bunnbo *= bunnbotmp % MOD;
		bunnbo %= MOD;
		bunnbotmp--;
	}
	printf("bunnbo %lld\n", bunnbo);
	printf("%lld\n", bunnsi / bunnbo % MOD);
	return 0;
}