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
// #define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

int N, x;
int main(void){
	cin >> N >> x;
	if(x == 1 || x == 2 * N - 1){
		printf("No\n");return 0;
	}
	printf("Yes\n");
	set<int> se;
	se.insert({x - 1, x, x + 1});
	int cnt = 0;
	for (int i = 1; i <= 2 * N - 1; ++i){
		if(!se.count(i)){
			se.insert(i);
			cnt++;
			printf("%d\n", i);
		}
		if(cnt == N - 2) break;
	}
	// printf("k\n");
	rep(i, 3){
		printf("%d\n", x + i - 1);
	}
	// printf("k1\n");
	for (int i = 1; i < 2 * N; ++i){
		if(!se.count(i)){
			se.insert(i);
			cnt++;
			printf("%d\n", i);
		}
	}
	return 0;
}