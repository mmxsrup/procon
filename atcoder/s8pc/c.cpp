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

ll n;
int m, q;
int a[100010];
int memo[10];
int used[10];
int dx[] = {1, -1};

int main(void){
	cin >> n >> m >> q;
	rep(i, q) cin >> a[i];

	rep(i, q) memo[a[i] % 7]++;
	bool flag = true;
	ll ans = 0;
	// printf("k\n");
	rep(i, 7){
		if(used[i]) continue;
		ans++;
		queue<int> q; q.push(i);
		while(!q.empty()){
			int t = q.front(); q.pop();
			rep(k, 2){
				if(memo[i + dx[k]] == 0 && used[i + dx[k]] == 0){
					q.push(i + dx[k]);
					used[i + dx[k]] = 1;
				}
			}
		}	
	}
	printf("%lld\n", ans);
	return 0;
}