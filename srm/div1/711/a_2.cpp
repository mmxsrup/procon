#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=n-1;i>=(0);i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define eall(v) unique(all(v), v.end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;


class ConsecutiveOnes{
public:
	long long get(long long n, int k){
		int cnt = 0, ma = 0;
		for (ll i = 0, d = 1; i <= 50 ; i++, d <<= 1){
			if((n & d)){
				cnt++;
				chmax(ma, cnt);
			}else{
				cnt = 0;
			}
		}
		if(ma >= k) return n;
		
		ll ans =  n | ((1ll << k) - 1);
		ll tmpans = ans;
		int e = 0;
		while(tmpans > 0){
			if(tmpans % 2){
				e++;
			}else{
				break;
			}
			tmpans /= 2;
		}
		return (ans ^ ((1ll<<(e-k)) - 1));
	}
};

int main(void){
	ConsecutiveOnes co;
	auto d = co.get(364269800189924,33); cout << d << endl;
	return 0;
}