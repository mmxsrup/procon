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

int ans = 0;
int DB, b[3];
int DC, c[3];
bool memo[10010][10010];
int main(void){
	int a[3];
	rep(i, 3) cin >> a[i];
	cin >> DB;
	rep(i, 3) cin >> b[i];
	cin >> DC;
	rep(i, 3) cin >> c[i];
	int ret = 0;
	priority_queue<tuple<int, int, int, int, int> > q;
	q.push(make_tuple(a[0] * 1000 + a[1] * 100 + a[2], a[2], a[1], a[0], 0));

	while(!q.empty()){
		int tsum, t[3], ans;
		tie(tsum, t[2], t[1], t[0], ans) = q.top(); q.pop();
		if(memo[tsum][t[2]]){
			continue;
		}else{
			memo[tsum][t[2]] = true;
		}
		chmax(ret, ans);
		// printf("%d\n", ret);

		int tmp[3];
		int nokori;
		//bさん
		rep(i, 3) tmp[i] = t[i];
		nokori = DB;
		if(nokori >= 1000 && tmp[0] > 0){
			int mi = min(nokori / 1000, tmp[0]);
			int tukau = mi;
			nokori -= 1000 * mi;
			tmp[0] -= tukau;
		}
		if(nokori >= 100 && tmp[1] > 0){
			int mi = min(nokori / 100, tmp[1]);
			int tukau = mi;
			nokori -= 100 * mi;
			tmp[1] -= tukau;
		}
		if(nokori <= tmp[2]){//砦
			tmp[2] -= nokori;
			rep(i, 3) tmp[i] += b[i];//もらう
			q.push(make_tuple(tmp[0] * 1000 + tmp[1] * 100 + tmp[2], tmp[2], tmp[1], tmp[0], ans + 1));
		}
		//cさん
		rep(i, 3) tmp[i] = t[i];
		nokori = DC;
		if(nokori >= 1000 && tmp[0] > 0){
			int mi = min(nokori / 1000, tmp[0]);
			int tukau = mi;
			nokori -= 1000 * mi;
			tmp[0] -= tukau;
		}
		if(nokori >= 100 && tmp[1] > 0){
			int mi = min(nokori / 100, tmp[1]);
			int tukau = mi;
			nokori -= 100 * mi;
			tmp[1] -= tukau;
		}
		if(nokori <= tmp[2]){//砦
			tmp[2] -= nokori;
			rep(i, 3) tmp[i] += c[i];//もらう
			q.push(make_tuple(tmp[0] * 1000 + tmp[1] * 100 + tmp[2], tmp[2], tmp[1], tmp[0], ans + 1));
		}
	}
	printf("%d\n", ret);
	return 0;
}