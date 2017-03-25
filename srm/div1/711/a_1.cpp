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
	ll slv(string s){
		// cout << "s " << s << endl;
		ll ret = 0;
		int size = (int)s.size();
		ll k = pow(2, (size - 1));
		
		for (int i = 0; i < s.size(); ++i){
			if(s[i] == '1')ret += k;
			k /= 2;
		}
		// printf("ret %lld \n", ret);
		return ret;
	}

	long long get(long long n, int k){
		ll tmpn = n;
		int ma = 0, cnt = 0;
		bool flag = true;
		while(tmpn > 0){
			if(tmpn % 2 == 1){
				cnt++;
				chmax(ma, cnt);
			}else{
				cnt = 0;
			}
			tmpn /= 2;
		}
		if(ma >= k) return n;
		string f = "";
		rep(i, k) f += '1';

		ll re = slv(f);
		ll ans =  n | re;
		// printf("ans %lld\n", ans);
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
		// printf("e %d\n", e);
		ll iran = 0;
		ll d = 1;
		rep(i, e - k){
			iran += d;
			d *= 2;
		}
		return ans - iran;
	}
};

int main(void){
	ConsecutiveOnes co;
	auto d = co.get(5, 2); cout << d << endl;
	return 0;
}