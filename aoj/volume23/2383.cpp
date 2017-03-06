//回答みた。ソートしてみていくのは考えたけど、それでいい理由が分からなかった。
/*
解法
ステージの難易度を昇順にソートしておく
昇順にソートしておくことで、後から入れる数字が必ず大きくなるので、挿入位置の後ろの数字との差だけを考えれば良くなる。
そのためどの数字の前に追加すればいいかだけを確認すれば良くなるため、追加前の数字の並びを気にする必要はくなる。
よって、昇順に数字を入れていき、入れる数字がいくつの場所に入るかを求め、それを掛け合わせれば答えとなる。
http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1878070#1
*/
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(ll i=0;i<(n);i++)

const ll mod = 1000000007;

int main(void){
	ll n; ll t;
	cin >> n >> t;
	vector<ll> d(n);
	rep(i, n) scanf("%lld", &d[i]);

	sort(all(d));
	ll ans = 1;
	//値を入れる場所を探す前から１つずつ確認していくと、時間がかかるので、２分探索とかlower_bound関数(指定した値"以上"の要素が最初に現れる位置を返す)
	//i + 1はすでに入っている数字の前と、最後尾に数字が入るため
	//lower_boundを使って、条件を満たさない数字を見つけ、条件を満たさない数字の総計を計算して、全体(i + 1)からその数を引いた数を掛け合わせている
	rep(i, n){
		ans = ans * (i + 1 - (ll)(lower_bound(d.begin(), d.begin() + i + 1, d[i] - t) - d.begin())) % mod;
	}

    printf("%lld\n", ans % mod);
    return 0;
}