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

class MazeConstruct{
public:
	vector <string> construct(int k){
		if(k <= 98){
			int h, w;
			if(k % 2 == 0) h = k / 2, w = k / 2;
			else h = k / 2 + 1, w = k / 2;
			h++; w++;
			// printf("%d %d\n", h, w);
			vector<string> board(h);
			rep(i, h){
				string t = "";
				rep(j, w){
					t += '.';
				}
				board[i] = t;
			}
			return board;
		}else{
			// printf("k\n");
			int h = 50, w = 50;
			int cnt = k - 98;
			if(cnt % 2 == 1){
				w = 49;
				cnt += 1;
			}
			vector<string> board(h);
			rep(i, h){
				string t = "";
				rep(j, w){
					t += '.';
				}
				board[i] = t;
			}
			for (int i = 1; i < w - 1; i += 4){
				for (int j = 0; j < h - 1; ++j){
					board[j][i] = '#';
				}
			}
			bool flag = false;
			for (int i = 3; i < w - 1; i += 4){
				for (int j = h - 1; j >= 1; --j){
					if(cnt <= 0){
						flag = true;
						break;
					}
					board[j][i] = '#';
					cnt -= 2;
				}
				if(flag)break;
			}
			return board;
		}
	}
};

int main(void){
	MazeConstruct mc;
	int d; cin >> d;
	auto ret = mc.construct(d);
	for(auto u : ret){
		cout << u << endl;
	}
	return 0;
}