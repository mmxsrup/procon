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

int N;
int s[55];
int sum;
int inf[55];
set<int> setinf[55];
int M;

int main(void){
	cin >> N;
	rep(i, N)cin >> s[i];
	rep(i, N)sum += s[i];
	rep(i, N)inf[i] += s[i];
	rep(i, N) setinf[i].insert(i);
	cin >> M;
	rep(i, M){
		int a, b, c; cin >> a >> b >> c;
		b--; c--;
		if(a == 0){
			inf[b] += s[c];
			setinf[b].insert(c);
		}else{
			if(setinf[b].count(c)){
				printf("%d %d\n", s[c], s[c]);
			}else{
				int nokori_sum = sum - inf[b];
				int nokori_num = N - setinf[b].size() - 1;
				// printf("k %d %d\n", nokori_num, nokori_sum);
				int ma = nokori_num * 100;
				int mi = 0;
				printf("%d %d\n", max(0, nokori_sum - ma), min(100, nokori_sum - mi));
			}
		}
	}
	return 0;
}