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


class AlienAndGame{
public:
	int getNumber(vector <string> board){
		int ret = 1;
		int h = board.size(), w = board[0].size();
		rep(y, h)rep(x, w){//左上
			for (int i = 1; i <= min(h - y, w - x); ++i){//正方形の一辺の長さ
				bool flag = true;
				rep(j, i){//y+j行目を見ている	
					reps(k, 1, i){
						if(board[y + j][x] 	!= board[y + j][x + k]){
							flag = false; break;
						}
					}
					if(!flag) break;
				}
				if(flag){
					chmax(ret, i * i);
				}
			}
		}
		return ret;
	}
};

int main(void){
	AlienAndGame AlienAndG;
	vector<string> s;
	// s.pb("WBBB"), s.pb("WBBB"), s.pb("WWWW");
	s = {"BWBBWBB",
		 "WWBWWBW",
		 "BBBBBBW",
		 "WBBBBWB",
		 "BBWWWWB",
		 "WWWWWWW",
		 "BBWWBBB"};
	printf("%d\n", AlienAndG.getNumber(s));
	return 0;
}