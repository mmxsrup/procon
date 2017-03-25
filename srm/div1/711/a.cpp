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
		string f = "";
		rep(i, k) f += '1';
		ll tmpn = n;
		int size = 0;
		while(tmpn > 0){
			tmpn /= 2;
			size++;
		}
		// printf("size %d\n", size);
		int max_size = 50;
		ll ans = INFF;
		for (int i = k; i <= max_size; ++i){ //1no kaz
			// printf("i %d\n", i);
			string d = "";
			rep(j, i) d += "1";
			// cout << "d "  << d << endl;
			for (int j = 0; j <= max_size; ++j){ // 0のかず
				if(j == 0){
					string tmpd = d;
					reps(size, (int)tmpd.size(), 51){
						while(tmpd.size() < size) tmpd += "0";
						if(tmpd.size() > max_size) break;
						// cout << tmpd << endl;
						ll ret = slv(tmpd);
						if(ret >= n) chmin(ans, ret);
					}
				}else{
					string tmpd = "1";
					rep(k, j) tmpd += "0";
					tmpd += d;
					while(tmpd.size() < size) tmpd += "0";
					if(tmpd.size() > max_size) break;
					// cout << tmpd << endl;
					ll ret = slv(tmpd);
					if(ret >= n) chmin(ans, ret);
				}
			}
		}
		return ans;
	}
};

int main(void){
	ConsecutiveOnes co;
	auto d = co.get(364269800189924, 33); cout << d << endl;
	return 0;
}