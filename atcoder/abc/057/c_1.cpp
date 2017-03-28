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


bool isprime[200010];
//エラトステネス
void eratos(int m){
    for (int i = 0; i <= m; ++i) isprime[i] = true;
    isprime[0] = isprime[1] = false;
    //iを残してiの倍数を消していく
    for (int i = 2; i <= m; ++i){
        if(isprime[i]){
            for (int j = 2 * i; j <= m; j += i){
                isprime[j] = false;
            }
        }
    }
}

int main(void){
	ll n; cin >> n;
	ll a = 1, b = 1;
	eratos(200010);
	vector<ll> v;
	for (int i = 2; i * i <= n; ++i){
		if(isprime[i]){
			// printf("i %d\n", i);
			// printf("%lld %lld\n", a,b );
			while(n % i == 0){
				v.pb(i);
				n /= i;
			}
		}
	}
	if(n != 1) v.pb(n);
	reverse(all(v));
	rep(i, v.size()){
		if(a >= b) b *= v[i];
		else a *= v[i];
	}
	string sa = to_string(a), sb = to_string(b);
	// cout << sa << " " << sb << endl;
	int size = max((int)sa.size(), (int)sb.size());
	printf("%d\n", size);
	return 0;
}