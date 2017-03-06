//Union-Find木
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<pint> vpint;
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

const int MX = 200005;

//辺(点)をつなぐ作業と、辺が連結されや部分の数を数得ることができればいいのだからunion find
/*
頂点の数の分だけ点を取る　点と点をつなぐ時は向きを決めておく
矢印の先（各連結成分の先頭)(root)には連結成分の数を記録しておく。
連結成分同士をつなげる時は、連結成分内ならどこにつなげても連結していること自体は変わらないので、矢印の先(root同士)をつなげるとrootが
2つでてくることが起きなくなる。

高速化する方法
	①２つの成分をつなげるとき、高さが小さい方から、大きい方へつなげる。
	②rootを求めるときに、ついでに辿ったところのノードの親をrootに張り替えておく
*/

//union find library
struct UF{
	int n;//頂点の数
	vector<int> d;//マイナスの時はrootでその連結成分の数、それ以外の時、親の頂点番号

	//コンストラクタ
	UF() {}
	//dという配列は、union-findの構造とサイズを同時に保存できる
	//変数nをnで初期化　変数d[]を-1で初期化　マイナスはルートを表す
	//dはその頂点がrootであるとき、グループのsizeの負の数が入り、そうでないときは親が入る
	UF(int n): n(n), d(n, -1) {}

	//root部分を求める関数
	int root(int v){
		if(d[v] < 0) return v;//負ならrootで、その数が連結成分のsize
		//d[v] = root(d[v])として、枝の深さを小さくすることで、高速化
		return d[v] = root(d[v]);//高速ルートを探しつつ、ついでに親のrootで書きかえ(高速化②適用パターン)
		//return root(d[v]);　親の根がrootであるので再帰で求める
	}

	/*uniteとsizeが重要*/
	//指定された二つの要素を合わせる
		//戻り値はbool型の理由は最小全域木(MST)で利用できる
	bool unite(int x, int y){
		x = root(x); y = root(y);//指定された要素のルートが同じなら合わせる必要はない
		if(x == y) return false;
		//小さい方を大きい方にくっつけるためにxの方が大きくなるように
		if(size(x) < size(y)) swap(x, y);
		d[x] += d[y];//マイナスの値が入り、それの絶対値が連結成分の中に含まれる数
		d[y] = x;//親の頂点番号を代入
		return true;
	}

	//連結成分の数を求める関数
	int size(int v){
		return -d[root(v)];//d[]の添え字の中にroot(v)を入れることで、引数がrootでなくてもsizeを求めることができる
	} 
};

//全ての道路の作られた年代とクエリで与えられる年代を合わせて、一緒に年代の新しい順にソートする
//時間順にクエリや道路の建設が来るようになり、それぞれの場合においてどのような操作をするか考えればいい
int main(void){
	int n, m;//n:頂点数 m:辺の数
	scanf("%d %d", &n, &m);
	vector<vector<pint> > e(MX);//ソートせずに添え字を利用

	rep(i, m){
		int a, b, y;
		//頂点番号は0indexで
		scanf("%d %d %d", &a, &b, &y);
		--a; --b;
		e[y].push_back(pint(a, b));
	}

	//クエリ入力
	int q;
	scanf("%d", &q);
	vector<vector<pint> > qs(MX);//qs[year]
	rep(qi, q){
		int v, w;
		scanf("%d %d", &v, &w);
		--v;//0index
		qs[w].push_back(pint(v, qi));//qiはクエリ番号
	}

	UF t(n);//頂点数を渡し、union find treeを初期化
	vector<int> ans(q);//答えを入れる配列
	for (int i = MX - 1; i >= 0; --i){
		for (pint p : qs[i]){
			int v = p.fi, qi = p.se; //fi v se　クエリ番号
			ans[qi] = t.size(v);//答えはvが含まれている連結成分のサイズ
		}
		for(pint p : e[i]){
			int a = p.fi, b = p.se;
			t.unite(a, b);
		} 
	}

	rep(i, q){
		printf("%d\n", ans[i]);
	}
	return 0;
}