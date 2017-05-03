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

const int MAX_N = 110;
int dist[MAX_N][MAX_N];

//答えが1つ大きくなる問題.
int a[1010], b[1010], c[1010];
int main(void){
    int N, M; cin >> N >> M;
    rep(i, M){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
    }
    rep(i, MAX_N)rep(j, MAX_N) dist[i][j] = INF;
    rep(i, N)dist[i][i] = 0;
    rep(i, M)dist[a[i]][b[i]] = c[i], dist[b[i]][a[i]] = c[i];
    rep(k, N)rep(i, N)rep(j, N) dist[i][j] = chmin(dist[i][j], dist[i][k] + dist[k][j]);

    set<pair<int, int>> se;
    rep(k, M)rep(i, N)rep(j, N){ // i->a[i]->b[i]->j
        if(dist[i][a[k]] + c[k] + dist[b[k]][j] == dist[i][j]){ //a[k]-b[k]
            se.insert(mp(min(a[k], b[k]), max(a[k], b[k])));
        }
    }
    printf("%d\n", M - se.size());
    return 0;
}