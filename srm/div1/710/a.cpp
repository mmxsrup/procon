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

class ReverseMancala{
public:
	vector<vector<int>> mem;

	vector<int> fpa(vector<int> tmp, int i, int n){
		int nokori = tmp[i];
		tmp[i] = 0;
		int idx = i + 1;
		while(nokori > 0){
			tmp[idx % n]++;
			idx++;
		}
	}
	vector<int> fpaa(vector<int> tmp, int i){
		tmp.pb(i); return tmp;
	}

	vector<int> fpb(vector<int> tmp, int i, int n){
		int sum = 0;
		int idx = i;
		while(tmp[idx] != 0){
			tmp[idx]--;
			sum++;
			idx++;
		}
		tmp[idx] += sum;
	}
	vector<int> fpbb(vector<int> tmp, int i){
		tmp.pb(i); return tmp;
	}

	void dfs(vector<int> state, vector<int> goal, vector<int> ans){
		if(ans.size() == 2500) return;
		if(state == goal){
			mem.pb(ans);
			return;
		}
		int n = goal.size();

		rep(i, n){
			if(state[i] < goal[i])dfs(fpa(state, i, n), goal, fpaa(ans, i));
			else if(state[i] > goal[i] && state[i] != 0) dfs(fpb(state, i, n), goal, fpbb(ans, i));
		}
	}
	vector <int> findMoves(vector <int> start, vector <int> target){
		dfs(start, target, {});
		return mem[0];
	}
};

int main(void){
	ReverseMancala rm;
	auto t = rm.findMoves({6, 3, 4, 0}, {1, 5, 6, 1});
	for(auto u : t){
		printf("%d ", u);
	}
	printf("\n");
	return 0;
}