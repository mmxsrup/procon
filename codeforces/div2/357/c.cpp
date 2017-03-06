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

priority_queue<int, vector<int>, greater<int> > pq;

//fi num insert:1 removeMin:2 getMin:3
//se print number
vpint db;

void print(void){
	int size = db.size();
	printf("%d\n", size);
	rep(i, db.size()){
		if(db[i].fi == 0){
			printf("insert %d\n", db[i].se);
		}else if(db[i].fi == 1){
			printf("removeMin\n");
		}else{
			printf("getMin %d\n", db[i].se);
		}
	}
	return;
}

void getmin(int aim){
	//pqでaimがくるまで回す
	while(!pq.empty() && pq.top() != aim){
		db.push_back(mp(1, 0));//いらないものremove
		//printf("removeMin\n");
		pq.pop();
	}
	if(pq.size() == 0){
		//getMinがqueueの中にないとき
		pq.push(aim);//これを加えた
		db.push_back(mp(0, aim));//aimをインサート
		//printf("insert %d\n", aim);
		db.push_back(mp(2, aim));//インサートしてgetMin
		//printf("getMin %d\n", aim);
	}else{
		db.push_back(mp(2, aim));//
		//printf("getMin %d\n", aim);
	}
	return;
}

int main(void){
	string s;
	int n;
	int kaisuu;
	cin >> kaisuu;

	rep(i, kaisuu){
		cin >> s;

		if(s == "insert"){
			cin >> n;
			pq.push(n);
			db.push_back(mp(0, n));
			//printf("insert %d\n", n);
		}
		if(s == "removeMin"){
			if(pq.empty()){
				//からの時
				//pq.push(1);
				db.push_back(mp(0, 1));//insertした
				db.push_back(mp(1, 0));//removeMin
				continue;
				//printf("insert 1\n");

			}else{
				db.push_back(mp(1, 0));//空でなければremoveMin
				//printf("removeMin\n");
				pq.pop();
			}
		}
		if(s == "getMin"){
			cin >> n;
			getmin(n);
		}
	}

	print();

	return 0;
}


/*

getMinは最小値確認

2
getMin 31
removeMin

Output
4
insert 31
getMin 31
insert 1
removeMin
Answer
3
insert 31
getMin 31
removeMin


Input
1
removeMin
Output
1
removeMin
Answer
2
insert 0
removeMin
*/