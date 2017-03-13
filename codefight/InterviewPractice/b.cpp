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

int packageBoxing(std::vector<int> pkg, std::vector<std::vector<int>> boxes) {
	vector<tuple<int, int, int>> tup;
	rep(i, boxes.size()){
		vector<int> tmp;
		for(auto u : boxes[i]) tmp.pb(u);
		sort(all(tmp));
		tup.push_back(make_tuple(tmp[0], tmp[1], tmp[2]));
	}
	// sort(all(tup));
	sort(all(pkg));
	rep(i, pkg.size()) printf("%d\n",pkg[i] );
	int ans = -1;
	int now = INF;
	rep(i, tup.size()){
		int x, y, z; tie(x, y, z) = tup[i];
		printf("%d %d %d \n", x, y, z);
		if(pkg[0] <= x && pkg[1] <= y && pkg[2] <= z){
			if(now > x * y * z){
				printf("k\n");
			ans = i;
			now = x * y * z;
			}
		}
	}
	if(ans != -1) return ans;
	return -1;
}

int main(void){
	auto k = packageBoxing({4, 2, 5}, {{4, 3, 5}, {5, 2, 5}});
	printf("%d\n", k);
	return 0;

}
