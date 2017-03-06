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


void slove(string s, string s1){
	int array[5] = {0};//[0]:m [1]:c [2]:x [3]:i
	int size = s.size();
	int size1 = s1.size();

	rep(i, size){
		/*
		rep(j, 5) printf("%d", array[j]);
		printf("\n");
		*/
		if ('0' <= s[i] && s[i] <= '9'){
			if (s[i + 1] == 'm') array[0] += s[i] - '0';
			else if(s[i + 1] == 'c') array[1] += s[i] - '0';
			else if(s[i + 1] == 'x') array[2] += s[i] - '0';
			else if(s[i + 1] == 'i') array[3] += s[i] - '0';
			i++;
		}else{
			if (s[i] == 'm') array[0]++;
			else if(s[i] == 'c') array[1]++;
			else if(s[i] == 'x') array[2]++;
			else if(s[i] == 'i') array[3]++;
		}
	}
	/*
	rep(j, 5) printf("%d", array[j]);
	printf("\n");
	*/

	rep(i, size1){
		if ('0' <= s1[i] && s1[i] <= '9'){
			if (s1[i + 1] == 'm') array[0] += s1[i] - '0';
			else if(s1[i + 1] == 'c') array[1] += s1[i] - '0';
			else if(s1[i + 1] == 'x') array[2] += s1[i] - '0';
			else if(s1[i + 1] == 'i') array[3] += s1[i] - '0';
			i++;
		}else{
			if (s1[i] == 'm') array[0]++;
			else if(s1[i] == 'c') array[1]++;
			else if(s1[i] == 'x') array[2]++;
			else if(s1[i] == 'i') array[3]++;
		}
	}
	/*
	rep(j, 5) printf("%d", array[j]);
	printf("\n");

	printf("board\n");
	rep(i, 5) printf("%d\n", array[i]);
	*/

	for(int i = 3; i >= 0; --i){
		int kai = array[i] / 10;
		int amari = array[i] % 10;
		//printf("%d %d\n", kai, amari);
		array[i] = amari;
		array[i - 1] += kai;
		/*
		rep(i, 5) printf("%d", array[i]);
		printf("\n");
		*/
	}
	string ans;
	if (array[0] != 0 && array[0] != 1) ans += to_string(array[0]) + 'm';
	else if (array[0] == 1) ans += 'm';
	if (array[1] != 0 && array[1] != 1) ans += to_string(array[1]) + 'c';
	else if (array[1] == 1) ans += 'c';
	if (array[2] != 0 && array[2] != 1) ans += to_string(array[2]) + 'x';
	else if (array[2] == 1) ans += 'x';
	if (array[3] != 0 && array[3] != 1) ans += to_string(array[3]) + 'i';
	else if (array[3] == 1) ans += 'i';

	cout << ans << endl;
	return;
}

int main(void){
	int n; cin >> n;
	rep(i, n){
		string s1, s2;
		cin >> s1 >> s2;
		slove(s1, s2);
	}

	return 0;
}