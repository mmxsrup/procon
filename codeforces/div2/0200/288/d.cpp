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
string s[200010];
map<int, string> ma;

int hashh(string x){
	int h = 100 * (x[0] - '0') + (x[1] - '0');
	ma[h] = x;
	return h;
}

multiset<int> se[10010];
vector<int> path;
void dfs(int u){
	// cout << "u " << ma[u] << endl;
	while(!se[u].empty()){
		int v = *se[u].begin();
		se[u].erase(se[u].begin());
		// cout << "v " << ma[v] << endl;
		dfs(v);
	}
	// cout << "Push " << ma[u] << endl;
	path.emplace_back(u);
}

int in[100010], out[10010];
int main(void){
	cin >> n;
	rep(i, n) cin >> s[i];
	rep(i, n){
		int l = hashh(s[i].substr(0, 2)), r = hashh(s[i].substr(1, 2));
		out[l]++, in[r]++;
		se[l].insert(r);
	}
	int start = hashh(s[0].substr(0, 2)), goal = hashh(s[0].substr(1, 2)), cnt = 0;
	rep(i, 10010){
		if(out[i] != in[i]) cnt++;
		if(out[i] > in[i]) start = i;
		if(out[i] < in[i]) goal = i;
		if(abs(out[i] - in[i]) > 1){ 
			printf("NO\n"); return 0;
		}
	}
	// cout << "sta " << ma[start] << endl;
	// cout << "goa " << ma[goal] << endl;
	if(cnt > 2){
		printf("NO\n"); return 0;
	}
	dfs(start);
	reverse(all(path));
	// printf("size %d\n", path.size());

	string ans;
	ans += ma[path[0]] + ma[path[1]].substr(1);
	reps(i, 2, path.size()){
		ans += ma[path[i]].substr(1);
	}
	//連結でない場合がある.
	if(ans.size() != n + 2){
		printf("NO\n"); return 0;
	}
	printf("YES\n");
	cout << ans << endl;
	return 0;
}