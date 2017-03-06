#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

///Quick Find Weighted///
const int MAX_N = 200010;
int group[MAX_N];//group[i] := 頂点iが所属するグループ
vector<int> item[MAX_N];//item[g]:= グループgに所属する頂点番号
// アイテムiaの所属するグループとアイテムibの所属するグループを1つにする(異なるグループに属するものに)
void merge(int ia, int ib){
	if(is_same_group(ia, ib)) return;
	//iaの所属するグループがibの所属するグループより小さくならないようにする(一般的マージテク)
	if(item[group[ia]].size() < item[group[ib]].size()){
		swap(ia, ib);
	}
	int ga = group[ia], gb = group[ib];//グループgbの方が要素数が少ない
	for(auto u : item[gb]){//uには頂点の番号はいる
		group[u] = ga;//グループの番号を更新
	}
	item[ga].insert(item[ga].end(), item[gb].begin(), item[gb].end());//つなげる
	item[gb].clear();
}
// アイテムiaとアイテムibは同じグループに所属しているか？
bool is_same_group(int ia, int ib){
	return group[ia] == group[ib];
}

void init(int n){
	for (int i = 0; i < n; ++i){
		group[i] = i;
		item[i].push_back(i);
	}
}
/////////////////////////


int main(void){
	int n, m, q; cin >> n >> m >> q;
	vector<pair<int, int> > cd;
	set<pair<int, int> > s;//最後まで残っている橋を入れる

	for (int i = 0; i < m; ++i){
		int a, b; cin >> a >> b;
		a--; b--;
		s.insert(make_pair(a, b));
	}
	for (int i = 0; i < q; ++i){
		int c, d; cin >> c >> d;
		c--; d--;
		cd.push_back(make_pair(c, d));
		s.erase(make_pair(c, d));
	}

	init(n);//初期化
	for(auto u : s){//最後まで残っている橋をつなげる
		merge(u.first, u.second);
	}

    vector<int> ans(n, 0);//初めから到達できないのは0
    for (int i = 1; i < n; ++i){
    	if(is_same_group(0, i)){
    		ans[i] = -1;//橋がすべて壊れても到達できるのは-1
    	}
    }
    for (int i = q - 1; i >= 0 ; --i){
 		int a = cd[i].first, b = cd[i].second;
 		if(!is_same_group(a, b)){
 			if(!is_same_group(0, a) && !is_same_group(0, b)){//0につながることはない
 				merge(a, b);
 				continue;
 			}
 			
 			if(!is_same_group(0, a) && !is_same_group(0, b)){
                merge(a, b);
            }else{
                if(is_same_group(0, b)){
                	swap(a, b);
                }

                for (int el : item[group[b]])
                    ans[el] = i + 1;
                merge(a, b);
            }
 		}
    }

    for (int i = 1; i < n; ++i){
    	printf("%d\n", ans[i]);
    }
	return 0;
}