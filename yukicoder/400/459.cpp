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

int h, w, n;
string s[10010];
int block_num[10010];//block_num[i] := i列目の存在するブロックの数
int tc[300010]
vector<int> c[10010]; // c[i] := i列目に落とすブロックの番号
class pack{
public:
	int num = 0;
	int d[3] = {0};
};

pack pac[300010]; //pac[i]番目の落とすブロック
int main(void){
	cin >> h >> w >> n;
	rep(i, h) cin >> s[i];
	rep(i, w){
		int sum = 0;
		rep(j, h){
			if(s[j][i] == '#') sum++;
		}
		block_num[i] = sum;
	}
	rep(i, n){
		cin >> tc[i];
		c[tc[i]].pb(i);
	}
	rep(i, 10000){
		//残りの枚数　何列目　index
		priority_queue<tuple<int, int, int> > que;//大きい順
		reps(j, i, i + 3){
			for(u : c[i]){ // u =index
				pq.push(make_tuple(-pac[u].num, j, u));
			}
		}
		
		rep(j, block_num[i]){
			int sum, x, index; 
			tie(sum, x, index) = que.front();
			pac[index].num = sum * -1 + 1;
			pac[index].d[x]++;
			pq.push(make_tuple(sum - 1, x, index));
		}
	}
	rep(i, n){
		string ans[3] = {"...", "...", "..."};
		rep(x, 3){
			rep(y, pac[i].d[x]){
				ans[x][y] = '#';
			}
		}
		rep(j, 3){
			cout << ans[j] << endl;
		}
	}
	return 0;
}