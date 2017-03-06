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

class Euler_Tour{
public:
	vector<vector<int> > g;
	vector<int> euler_tour, begin, end;
	Euler_Tour(int n) : g(n), begin(2 * n), end(2 * n){};
	int k = 0, int root = 0;
	void dfs(int curr, int par){//現在　parent
		begin[curr] = k;
		euler_tour.push_back(curr);
		k++;
		for(auto next : g[curr]){
			dfs(next, par);
			k++;
		}
		end[curr] = k;
	}
};
int main(void){

	return 0;
}