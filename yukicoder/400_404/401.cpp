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
#define reps(i,f,n) for(int i=(f);i<(n);i++)
int d[31][31];
int main(void){
	int n; cin >> n;
	int n_tmp = n;
	rep(i, n){
		d[0][i] = i + 1; 
	}
	int v = 1;
	int cnt = n;
	int nowx = n - 1, nowy = 0;
	n--;
	while(n >= 1){
		for (int i = 0; i < 2; ++i){
			if(v % 4 == 0){
				rep(j, n){
					cnt++;
					nowx++;
					d[nowy][nowx] = cnt;
					continue;
				}
			}else if(v % 4 == 1){
				rep(j, n){
					cnt++; nowy++;
					d[nowy][nowx] = cnt;
					continue;
				}
			}else if(v % 4 == 2){
				 rep(j, n){
					cnt++; nowx--;
					d[nowy][nowx] = cnt;
					continue;
				}
			}else if(v % 4 == 3){
				rep(j, n){
					cnt++; nowy--;
					d[nowy][nowx] = cnt;
					continue;
				}
			}
			v++;
		}
		n--;
	}
	// printf("pro\n");
	rep(i, n_tmp){
		rep(j, n_tmp){
			printf("%03d ", d[i][j]);
		}
		printf("\n");
	}
	return 0;

}