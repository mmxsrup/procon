/*
一番多い者に着目すればいける
*/
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

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int main(void){
	int n;
	char eto[51][51];
	char eto_template[15][15] = {"ne", "ushi", "tora", "u", "tatsu", "mi", "uma", "hitsuji", "saru", "tori", "inu", "i"};
	int eto_num[12] = {0};
	scanf("%d", &n);
	
	rep(i, n){
		scanf("%s", eto[i]);
		rep(j, 12){
			/*if (eto[i] == eto_template[j])
				eto_num[j]++;*/
			if (strcmp(eto[i], eto_template[j]) == 0) //同じなら0を返す
			{
				eto_num[j]++;
			}
		}
	}

	//かぶりが一番多いものを探す
	int max_num = 0;
	rep(i, 12)
		max_num = max(max_num, eto_num[i]);

	if (n - max_num >= max_num - 1) //かぶりがいちばん多い者を並べて、その間に他のものをいれられるだけ干支が残っていればいい
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}