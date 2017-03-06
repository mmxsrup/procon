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

string s[110];
int h, w;

int main(void){
	cin >> h >> w;
	rep(i, h) cin >> s[i];
	int ax, ay, bx, by;
	int cnt = 0;
	rep(i, h)rep(j, w){
		if(s[i][j] == '*'){
			if(cnt == 0){
				ax = j, ay = i;
			}else{
				bx = j, by = i;
			}
			cnt++;
		}
	}

	int dx1, dx2, dy1, dy2, dz1, dz2;
	dx1 = ax - bx; dy1 = ay - by;  dz1 = 0;
	rep(i, h)rep(j, w){
		if(s[i][j] == '*') continue;
		dx2 = j - bx; dy2 = i - by; dz2 = 0;
		//外積
		int ret = (dy1 * dz2 - dy2 * dz1) + (dx1 * dz2 - dx2 * dz1) + (dx1 * dy2 - dx2 * dy1);
		if(ret != 0){
			s[i][j] = '*';
			rep(k, h){
				cout << s[k] << endl;
			}
			return 0;
		}
	}
}