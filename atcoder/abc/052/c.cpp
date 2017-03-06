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

bool isprime[1010];
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

int cnt[1010];
int main(void){
    int n; cin >> n;
    eratos(n + 1);
    rep(i, n + 1){
        int d = i;
        reps(j, 2, i + 1){
            while(d % j == 0){
                d /= j;
                // printf("j %d\n", j);
                cnt[j]++;
            }
        }
    }
    ll ans = 1;
    rep(i, n + 1){
        ans *= (cnt[i] + 1);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}