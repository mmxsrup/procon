#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

int main(void){
	string s;
	cin >> s;
	long long size = s.size();
	cout << s;
	for (int i = size - 1; i >= 0; --i){
		printf("%c", s[i]);
	}
	return 0;
}