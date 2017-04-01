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

int n, w, d;
int p[110], s[110];
typedef tuple<int, int, int, int> tup;

int main(void){
	while(1){
		cin >> n >> w >> d;
		if(n == 0 && w == 0 && d == 0) break;
		rep(i, n){
			cin >> p[i] >> s[i];
		}
		priority_queue<tup, vector<tup>, greater<tup>> q[2]; //入れた順番 面積 辺の長さ
		q[0].push(make_tuple(-1, w * d, w, d));
		rep(i, n){
			rep(j, p[i] - 1){
				int num, men, x, y; 
				tie(num, men, x, y) = q[i % 2].top(); q[i % 2].pop();
				q[(i + 1) % 2].push(make_tuple(num, men, x, y));
			}

			//カット
			int num, men, x, y; 
			tie(num, men, x, y) = q[i % 2].top(); q[i % 2].pop();
			int len = s[i];
			len %= (x * 2 + y * 2);
			rep(j, 2){
				if(len - x < 0){
					int x1 = x - len, x2 = len;
					q[(i + 1) % 2].push(make_tuple(i, x1 * y, x1, y));
					q[(i + 1) % 2].push(make_tuple(i, x2 * y, x2, y));
					break;
				}
				len -= x;
				if(len - y < 0){
					int y1 = y - len, y2 = len;
					q[(i + 1) % 2].push(make_tuple(i, x * y1, x, y1));
					q[(i + 1) % 2].push(make_tuple(i, x * y2, x, y2));
					break;
				}
				len -= y;
			}

			while(!q[i % 2].empty()){
				int num, s, x, y; 
				tie(num, s, x, y) = q[i % 2].top(); q[i % 2].pop();
				q[(i + 1) % 2].push(make_tuple(num, s, x, y));
			}
		}
		vector<int> ans;
		rep(i, 2){
			while(!q[i].empty()){
				int num, men, x, y; 
				tie(num, men, x, y) = q[i].top(); q[i].pop();
				ans.pb(men);
			}
		}
		sort(all(ans));
		rep(i, ans.size()){
			if(i == ans.size() - 1) printf("%d\n", ans[i]);
			else printf("%d ", ans[i]);
		}
	}
	return 0;
}