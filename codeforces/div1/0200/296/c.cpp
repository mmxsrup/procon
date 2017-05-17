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

int n, m;
int a[200010], b[200010];
int ord[100010];
multiset<int> se[100010];
vector<int> path;
void dfs(int u){
	while(!se[u].empty()){
		int v = *se[u].begin();
		se[u].erase(se[u].begin()), se[v].erase(se[v].find(u));
		dfs(v);
	}
	path.emplace_back(u);
}

int main(void){
	cin >> n >> m;
	rep(i, m) scanf("%d %d", &a[i], &b[i]);
	rep(i, m){
		ord[a[i]]++, ord[b[i]]++;
		se[a[i]].insert(b[i]), se[b[i]].insert(a[i]);
	}

	vector<int> kisuu;
	reps(i, 1, n + 1){
		if(ord[i] % 2 == 1){
			kisuu.emplace_back(i);
		}
	}
	rep(i, kisuu.size()){
		int u = kisuu[i], v = kisuu[i + 1];
		se[u].insert(v), se[v].insert(u);
		i++;
	}

	// オイラー閉路を作った
	dfs(a[0]);
	reverse(all(path));
	if(path.size() % 2 == 0) path.emplace_back(path.back());

	int size = path.size();
	printf("%d\n", size - 1);
	rep(i, path.size() - 1){
		if(i % 2) printf("%d %d\n", path[i], path[i + 1]);
		else printf("%d %d\n", path[i + 1], path[i]);
	}
	return 0;
}