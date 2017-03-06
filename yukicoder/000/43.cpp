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

string s[10];
int n;
int kati[10], make[10];

int main(void){
	cin >> n;
	rep(i, n) cin >> s[i];
	// printf("yes\n");
	vector<pair<int, int> > nazo;
	rep(i, n)rep(j, n){
		if(s[i][j] == '-'){
			nazo.pb(mp(min(i, j), max(i, j)));
		}else if(s[i][j] == 'o'){
			kati[i]++;
		}
	}
	// printf("yes\n");
	sort(all(nazo));
	nazo.erase(unique(all(nazo)), nazo.end());
	int size = nazo.size();
	// printf("%d\n", size);
	int ans = INF;
	if(size != 0){
		for (int mask = 0; mask < (1 << (size)); ++mask){
			// printf("%d maks\n", mask);
			vector<int> win(10, 0);
			rep(i, n)win[i] = kati[i];
			for (int p = 0; p < size; ++p){
				if((mask & (1 << p)) != 0){//1が立ってたら、firstの勝ち
					win[nazo[p].fi]++;
				}else{
					win[nazo[p].se]++;
				}
			}
			int aim = win[0];
			sort(all(win));
			win.erase(unique(all(win)), win.end());
			reverse(all(win));
			int cnt = 0;
			while(win[cnt] != aim)cnt++;
			// printf("cnt %d\n",  cnt);
			chmin(ans, cnt + 1);
		}
	}else{
		vector<int> win;
		rep(i, n) win.pb(kati[i]);
		sort(all(win));
		win.erase(unique(all(win)), win.end());
		reverse(all(win));
		int cnt = 0;
		while(win[cnt] != kati[0])cnt++;
		chmin(ans, cnt + 1);
	}
	printf("%d\n", ans);
	return 0;
}