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
#define rall(v) (v).rbegin(), (v).rend()
#define eall(v) unique(all(v), v.end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define OUT(x) cout << #x << " = " << x << endl; 
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

int n;
int in[30], out[30];
bool dot[30];
string s[100010];
vector<int> G[30];

bool hantei(void){
	rep(i, 26)if(in[i] != out[i])return false;
	return true;
}

bool memo[30];
void dfs(int u, int p){
	memo[u] = true;
	for(auto v : G[u]){
		if(v == p) continue;
		if(memo[v]) continue;
		dfs(v, u);
	}
}

void init(void){
	rep(i, 30) in[i] = out[i] = dot[i] = memo[i] = 0;
	rep(i, 30) G[i].clear();
}

int main(void){
	while(1){
		cin >> n;
		if(n == 0) return 0;
		rep(i, n) cin >> s[i];
		init();
		rep(i, n){
			int u = s[i][0] - 'a', v = s[i].back() - 'a';
			out[v]++, in[u]++;
			dot[u] = dot[v] = true;
			G[u].pb(v);
		}
		bool flag = true;
		if(!hantei()) flag = false;

		int start = s[i][0] - 'a';
		dfs(start, -1);

		rep(i, 26)if(dot[i] != memo[i]) flag = false;
		if(flag) printf("OK\n");
		else printf("NG\n");
	}
	return 0;
}