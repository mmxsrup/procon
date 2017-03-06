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

struct node{
	int parent, left, right;
};


node t[10010];
int n, D[10010], H[10010];

void setdepth(int u, int d){
	if (u == NIL) return;

	D[u] = d;
	setdepth(t[u].left, d + 1);
	setdepth(t[u].right, d + 1);
}

int sethight(int u){
	int h1 = 0, h2 = 0;
	if (t[u].left != NIL) h1 = sethight(t[u].left) + 1;
	if (t[u].right != NIL) h2 = sethight(t[u].right) + 1;
	return H[u] = max(h1, h2);
}

int getsibling(int u){
	if (t[u].parent == NIL) return NIL;
	if (t)
}
void print_ans(int u){
	printf("node %d: ", u);
	printf("parent = %d, ", t[u].parent);
	printf("sibling = %d, ", getsibling(u));

	int deg = 0;
	if(t[u].left != NIL) deg++;
	if(t[u].right != NIL) deg++;
	printf("degree = %d, ", deg);

	printf("depth = %d, ", D[u]);
	printf("hight = %d, ", H[u]);

	if (t[u].parent == NIL) printf("root\n");
	else if(t[u].left ==  NIL && t[u].right == NIL) printf("leaf\n");
	else printf("internal node\n");
}

int main(void){
	int v, l, r;
	int root;
	cin >> n;
	rep(i, n) t[i].parent = NIL;//親を初期化する　子は後で初期化される

	rep(i, n){
		scanf("%d %d %d", &v, &l, &r);
		t[v].left = l;
		t[v].right = r;
		if (l != NIL) t[i].parent = v;
		if (r != NIL) t[i].parent = v;
	}

	//rootを見つける
	rep(i, n){
		if (t[i].parent == NIL)
			root = i;
	}

	setdepth(root, 0);
	sethight(root);

	rep(i, n) print_ans(i);

	return 0;
}




