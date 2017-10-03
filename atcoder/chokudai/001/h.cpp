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

ll dp[100010];
ll a[100010];
 
int main()
{
    int N;
    cin >> N;
    rep(i, N) {
        cin >> a[i];
    }
    fill(dp, dp + N, INF);
    rep(i, N) {
        *lower_bound(dp, dp + N, a[i]) = a[i];
    }
 
    ll ans = (lower_bound(dp, dp + N, INF) -lower_bound(dp,dp+N,0));
    cout << ans << endl;
 
    return 0;
}