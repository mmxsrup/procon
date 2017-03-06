/*

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
#include <list>
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
	ll a;
	ll b;
    scanf("%d %d", &a, &b);
    a--; 

	ll sum_a = 0, sum_b = 0;
	int keta_a = 0, keta_b = 0;
	
    while(a != 0){
    	a /= 10;
    	++keta_a;
    }
    while(b != 0){
    	b /= 10;
    	++keta_b;
    }

    for (int i = 10; i <= pow(10, keta_a); i *= 10)
    {
    	int kai = a / i;
    	int amari = a % i;

    	sum += kai * 2;

    	if (4 * (i / 10) <= amari && amari < 9 * (i / 10))
    	{
    		sum += amari - (4 * (i / 10)) + 1;
    	}else if(9 * (i / 10) <= kai){
    		sum += 2 * (i / 10);
    	}
    }















