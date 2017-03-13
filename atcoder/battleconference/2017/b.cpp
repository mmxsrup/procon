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

int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};

string s[12];
int main(void){
	rep(i, 9) cin >> s[i];
	bool flag = true;
	rep(i, 9){
		set<int> se;
		rep(j, 9){
			se.insert(s[i][j] - '0');
		}
		if(se.size() != 9){
			flag = false;
			break;
		}
	}
	if(!flag){
		printf("No\n");
		return 0;
	}
	rep(i, 9){
		set<int> se;
		rep(j, 9){
			se.insert(s[j][i] - '0');
		}
		if(se.size() != 9){
			flag = false;
			break;
		}
	}
	if(!flag){
		printf("No\n");
		return 0;
	}

	rep(i, 9)rep(j, 9){
		rep(k, 8){
			int ny = i + dy[k], nx = j + dx[k];
			if(!(0 <= ny && ny < 9 && 0 <= nx && nx < 9)) continue;
			if(s[ny][nx] == s[i][j]){
				flag = false;
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	return 0;
}