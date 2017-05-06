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

string s[30];
int ddcnt[30];
int R, C;
void solve(void){
	cin >> R >> C;
	rep(i, R) cin >> s[i];
	set<char> itiran;
	rep(i, R)rep(j, C) itiran.insert(s[i][j]);
	rep(i, 30) ddcnt[i] = 0;
	rep(i, R)rep(j, C) ddcnt[s[i][j] - 'A']++;

	for(auto cc : itiran){
		if(cc == '?') continue;
		int leny, lenx, ansy = -1, ansx = -1, size = 0;
		rep(y, R)rep(x, C){ //hidari ue
			reps(i, 1, R - y + 1)reps(j, 1, C - x + 1){ //tyouhoukei no nagasa
				bool flag = true;
				int cnt = 0;
				// printf("%c %d %d %d %d\n", cnt, y, x, i, j);

				rep(ki, i){
					rep(kj, j){
						int ny = y + ki, nx = x + kj;
						if(s[ny][nx] != '?' && s[ny][nx] != cc){
							flag = false;
							break;
						}
						if(s[ny][nx] == cc) cnt++;
					}
					if(!flag) break;
				}
				if(!flag) continue;
				// printf("%c %d %d %d %d\n", cc, y, x, i, j);
				if(size < i * j && cnt == ddcnt[cc - 'A']){
					ansy = y; ansx = x;
					leny = i, lenx = j;
					size = i * j;
				}
			}
		}
		// printf("%c %d %d %d %d\n", cc, ansy, ansx, leny, lenx);
		if(ansy != -1 && ansx != -1){
			rep(i, leny)rep(j, lenx){
				s[ansy + i][ansx + j] = cc;
			}
		}
	}
	rep(i, R)cout << s[i] << endl;
}

int main(void){
	int T; cin >> T;
	rep(i, T){
		printf("Case #%d:\n", i + 1);
		solve();
	}
	return 0;
}