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

int n, m, k;
int a[1000010];
int s[1000010];//xorの累積和
ll memo[2000010];//memo[i] := k^(現在見ている区間のb)の値がiとなるbの数
int xor_num = 0;
int cnt = 0;

const int N = 300;//sqrt(クエリの最大数)
bool comp(tuple<int, int, int> a, tuple<int, int, int> b) {
    if (get<0>(a) / N != get<0>(b) / N) return get<0>(a) / N < get<0>(b) / N;
    return get<1>(a) < get<1>(b);
}
void add(int i) {//区間を伸ばす時
    memo[k ^ b[i]]++;
}
void remove(int i) {//区間を縮める時
	memo[k ^ b[i]]--;
}

int main(void){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n){
		if(i == 0) s[i] = a[i];
		else s[i] ^= s[i - 1] ^ a[i];
	}

	vector<tuple<int, int, int>> qs(m);
	rep(i, m){
		int l, r; scanf("%d %d", &l, &r);
		qs[i] = make_tuple(l - 1, r - 1, i);
	}
	sort(all(qs), comp);

	vector<int> ans(m);
	int i = 0, j = -1;
	for(auto t : qs){
		int l, r, index; tie(l, r, index) = t;
		// printf("%d %d\n", l, r);
		//現在見ているクエリのl,rまで伸縮
		while (i < l) remove(i++);
        while (i > l) add(--i);
        while (j < r) add(++j);
        while (j > r) remove(j--);
        printf("%d %d %d\n", xor_num, i, j);
        if(xor_num == k) ans[index] = cnt;
	}
	rep(i, m){
		printf("%d\n", ans[i]);
	}
	return 0;
}