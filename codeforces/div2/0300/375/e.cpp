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


int t, n, m;

vector<int> path;
multiset<int> se[210];
void dfs(int u){
	while(!se[u].empty()){
		int v = *se[u].begin();
		se[u].erase(se[u].begin()), se[v].erase(se[v].find(u));
		dfs(v);
	}
	path.emplace_back(u);
}

int main(void){
	cin >> t;
	while(t--){
		cin >> n >> m;
		set<pair<int, int>> input;
		vector<int> in(n);
		rep(i, 210)se[i].clear();
		rep(i, m){
			int a, b; cin >> a >> b;
			a--, b--;
			input.insert(make_pair(a, b)), input.insert(make_pair(b, a));
			se[a].insert(b), se[b].insert(a);
			in[a]++, in[b]++;
		}
		vector<int> odd;
		rep(i, n)if(in[i] % 2)odd.pb(i);
		// printf("odd %d\n", odd.size());
		rep(i, odd.size()){
			se[odd[i]].insert(odd[i + 1]), se[odd[i + 1]].insert(odd[i]);
			i++;
		}
		printf("%d\n", n - odd.size());
		rep(k, n){
			if(se[k].empty()) continue;
			path.clear();
			dfs(k);
			rep(i, path.size() - 1){
				if(input.count(make_pair(path[i], path[i + 1]))){
					printf("%d %d\n", path[i] + 1, path[i + 1] + 1);
					input.erase(make_pair(path[i], path[i + 1])), input.erase(make_pair(path[i + 1], path[i]));
				}
			}
		}
	}
}