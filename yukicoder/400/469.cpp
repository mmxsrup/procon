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

int n, q;
unsigned int xor128(){//乱数生成
 	static unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;
 	unsigned int t = (x ^(x << 11));
 	x = y; y = z; z = w;
 	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
unordered_map<unsigned long long, int> mapp;
unsigned long long hash_table[1000010];

int main(void){
	cin >> n >> q;
	hash_table[0] = 0;
	rep(i, n + 1){
		hash_table[i + 1] = hash_table[i] + xor128();
	}
	mapp[0] = 0;
	unsigned long long now_hash = 0;
	rep(i, q){
		string c;
		int l, r, k;
		cin >> c;
		if(c == "!"){
			cin >> l >> r >> k;
			now_hash += (hash_table[r] - hash_table[l]) * k;
			if(mapp.count(now_hash) == 0) mapp[now_hash] = i + 1;
		}else{
			printf("%d\n", mapp[now_hash]);
		}
	}
	return 0;
}