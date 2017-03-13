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

int countVisibleTowerPairs(std::vector<int> position, std::vector<int> height) {
	int ret = 0;
	for (int i = 0; i < position.size(); ++i){
		for (int j = i + 1; j < position.size(); ++j){
			int dy = height[j] - height[i];
			int dx = position[i] - position[j];
			double d = dy / dx;
			bool flag = true;
			for (int k = 0; k < position.size(); ++k){
				// if(!(position[i] <= position[k] and position[k] <= position[j])) continue;
				if(((double)dy * position[k] + (double)dx * height[k] + d) * d < 0){
					flag = false;
					break;
				}
			}
			if(flag) ret++;
		}
	}
	return ret;
}


int main(void){
	auto d = countVisibleTowerPairs({3, 0, 6, 10}, {2, 1, 4, 6});
	printf("%d\n", d);
	return 0;
}