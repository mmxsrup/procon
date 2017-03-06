#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;

bool isprime[20010];
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

vector<int> prime;
//dp[i] := 合計がjとなるときの最大値
int dp[20010];

int main(void){
	int n; cin >> n;
	rep(i, n + 1) dp[i] = -1;
	eratos(20010);

	reps(i, 2, 20001){
		if(isprime[i]){
			prime.pb(i);
		}
	}
	dp[0] = 0;

	for(auto u : prime){
		for (int j = n; j >= 0; --j){
			if(u + j <= n && dp[j] != -1){
				chmax(dp[u + j], dp[j] + 1);
			}
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}