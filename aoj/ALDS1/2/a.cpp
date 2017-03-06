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

int main(void){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n)
		cin >> a[i];

	//iはソート済配列の位置 jは現在動かしている位置
	int flag = 1;
	int cnt = 0;
	rep(i, n){
		REPS(j, n, i + 1){
			while(flag == 1){
				flag = 0;
				if(a[j] > a[j + 1]){
					swap(a[j], a[j + 1]);
					cnt++;
					flag = 1; //もう一度そーとを繰り返すように
					rep(i, n)
						printf("%d ", a[i]);
					printf("\n");

				}

			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}