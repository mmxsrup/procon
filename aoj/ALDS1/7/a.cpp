#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
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
#define REP(i,n) for (int i=(n)-1;i>=0;i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define REPS(i,f,n) for (int i=(f)-1;i>=(n);i--)
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

#define NIL -1
//親　最左子　左の子の右
struct node{
	int p, l, r;
};

node T[101010];
int n, D[101010];

void print_ans(int u){
	printf("node %d: ", u);
	printf("parent = %d, ", T[u].p);
	printf("depth = %d, ", D[u]);

	if (T[u].p == NIL) printf("root, ");
	else if(T[u].l == NIL) printf("leaf, ");
	else printf("internal node, ");

	printf("[");

	//子を表示させている部分
	for (int i = 0, c = T[u].l; c != NIL; i++, c = T[c].r){
		if (i != 0) printf(", ");
		printf("%d", c);
	}
	printf("]");
	printf("\n");
}

//再帰関数を利用して深さを求める 
int deep(int u, int p){//uがノードの番号で pがその深さ
	D[u] = p;
	//横方向と縦方向に向けて深さを１度で求めるための再帰関数
	if (T[u].r != NIL) deep(T[u].r, p);//右の兄弟が存在すればそれにも、自分と同じ深さを設定
	if (T[u].l != NIL) deep(T[u].l, p + 1);//最も左の子に自分の深さ+1を設定
	return 0;
}

int main(void){
	int root;
	int child_id; //左の子供のidを示すもの
	int tmp;
	cin >> n;
	rep(i, n) T[i].p = T[i].l = T[i].r = NIL; //初期化

	/* 木構造を登録する */
	rep(i, n){
		int id, k;//id節点の番号　k次数(子の数)
		scanf("%d %d", &id, &k);
		rep(j, k){
			scanf("%d", &tmp);//子の節点番号
			if (j == 0) T[id].l = tmp;//親に最左の子供を登録
			else T[child_id].r = tmp;//子供に右の兄弟を登録
			child_id = tmp;//次に登録するidを更新する
			T[tmp].p = id;//親を登録する		 
		}
	}

	//ルートを探す
	//ノードはn個
	rep(i, n){
		if (T[i].p == NIL) root = i;
	}

	deep(root, 0); //(ノードの番号がroot, 深さ)

	rep(i, n) print_ans(i);
	
	return 0;
 }