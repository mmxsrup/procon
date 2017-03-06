#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;

class strongly_connected_components{
public:
	vector<vector<int> > G, rG;
	vector<int> used, vs;
	vector<int> cmp; //cmp[v] := 頂点vが含まれる連結成分がどれなのかを示す番号
	strongly_connected_components(const vector<vector<int> > &g, const vector<vector<int> > &rg, int n):
		G(g), rG(rg), cmp(2 * n), used(2 * n){
		exec();
	}
	int exec(){
		/*
		rep(i, G.size()){
			for(auto t : G[i]){
				printf("%d->%d\n", i, t);
			}
		}
		*/
		fill(used.begin(), used.end(), 0);
		for (int i = 0; i < G.size(); ++i){
			if(!used[i]) dfs(i);
		}
		fill(used.begin(), used.end(), 0);
		int k = 0;
		for (int i = vs.size() - 1; i >= 0; --i){
			if(!used[vs[i]]){
				rdfs(vs[i], k++);
			}
		}
		return k; //sccの数
	}
	int operator[](int i){//連結成分の番号を返す
        return cmp[i];
    }
private:
	void dfs(int curr){
		used[curr] = true;
		for(auto next : G[curr]){
			if(!used[next]) dfs(next);
		}
		vs.push_back(curr);
	}
	void rdfs(int curr, int k){
		used[curr] = true;
		cmp[curr] = k;//頂点vに対して、k番目と強連結成分であること入れる
		for(auto next : rG[curr]){
			if(!used[next]) rdfs(next, k);
		}
	}
};

class twosatisfiability{
public:
	int V;
    vector<int> res; // 1:= 0:=
    vector<vector<int> > g, rg;
    twosatisfiability(int n) : V(n), g(2 * n), rg(2 * n), res(n){}

    bool exec() {
        strongly_connected_components scc(g, rg, V);
        
        rep(i, 2 * V){
        	printf("cmp_%d %d\n", i, scc[i]);
        }
        
        for (int i = 0; i < V; i++) {

            if (scc[i * 2] == scc[i * 2 + 1]) {
                return false;
            }
            res[i] = scc[i * 2] < scc[i * 2 + 1];
        }
        return true;
    }
    void add_edge(int a, int b) {
        g[a].push_back(b);
        rg[b].push_back(a);
    }
    //0~V-1: x_i
    //V~2V-1: notx_i
    void add(int a, bool apos, int b, bool bpos) {
    	/*
        add_edge(a + (apos ? V : 0), b + (bpos ? 0 : V)); // not a implies b
        add_edge(b + (bpos ? V : 0), a + (apos ? 0 : V)); // not b implies a
        */
        int i = a, j = b;
        int ii = 0, jj = 0;
       	if(apos) ii = 1;
       	if(bpos) jj = 1;
        g[i * 2 + 1 - ii].push_back(j * 2 + jj);
        g[j * 2 + 1 - jj].push_back(i * 2 + ii);
    }
    bool operator[](int k) {
        return res[k];
    }
};

int n;
string u[100010];
int main(void){
	cin >> n;
	rep(i, n) cin >> u[i];
	if(n > 26 * 2){
		printf("Impossible\n");
		return 0;
	}
	twosatisfiability sat(n);
	rep(i, n){
		reps(j, i + 1, n){
			//u[i]を2,1文字に分けるとき、かつそのときに限りx_iに真を割りあてる
			//被りが生じるような組み合わせには偽となるような節を追加
			string a = u[i];
            string b = u[j];
           	if (a.substr(0, 1) == b.substr(0, 1) || a.substr(1, 2) == b.substr(1, 2)) {
                sat.add(i, true, j, true);
            }
            if (a.substr(0, 1) == b.substr(2, 1) || a.substr(1, 2) == b.substr(0, 2)) {
                sat.add(i, true, j, false);
            }
            if (a.substr(0, 2) == b.substr(1, 2) || a.substr(2, 1) == b.substr(0, 1)) {
                sat.add(i, false, j, true);
            }
            if (a.substr(0, 2) == b.substr(0, 2) || a.substr(2, 1) == b.substr(2, 1)) {
                sat.add(i, false, j, false);
            }
		}
	}
	bool flag = sat.exec();
	if(!flag){
		printf("Impossible\n");
		return 0;
	}else{
		rep(i, n){
			if(sat[i]){
				cout << u[i].substr(0, 2) << " " << u[i].substr(2, 1) << endl;
			}else{
				cout << u[i].substr(0, 1) << " " << u[i].substr(1, 2) << endl;
			}
		}
	}
	return 0;
}