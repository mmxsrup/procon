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

bool isprime[10010];
void eratos(int m){
    for (int i = 0; i <= m; ++i) isprime[i] = true;
    isprime[0] = isprime[1] = false;
    for (int i = 2; i <= m; ++i){
        if(isprime[i]){
            for (int j = 2 * i; j <= m; j += i){
                isprime[j] = false;
            }
        }
    }
    return;
}

int c[22];
int dp[100010];
int main(void){
	int m, n; cin >> m >> n;
	int mi = INF;
	rep(i, n){
		cin >> c[i];
		chmin(mi, c[i]);
	}

	eratos(10000);
	rep(i, 100010) dp[i] = -1;
	dp[m] = 0;
	for (int i = 100000; i >= 1; --i){
		rep(j, n){
			if(i - c[j] >= 0 && dp[i] != -1){
				dp[i - c[j]] = max(dp[i - c[j]], dp[i] + 1);
			}
		}
	}
	int ans = 0;
	rep(i, m){
		if(isprime[i] && dp[i] >= 0){
			ans += dp[i];
		}
	}
	printf("%d\n", ans + m / mi);
	return 0;
}

