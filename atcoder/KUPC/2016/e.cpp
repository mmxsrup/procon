#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=n-1;i>=(0);i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define eall(v) unique(all(v), v.end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

int H, W;
string s[110];

const int MAX_V = 20100; //必要な頂点数
struct Flow{
    struct edge{
        int to, cap, rev;
    };
    vector<edge> G[MAX_V];//隣接リスト
    bool used[MAX_V];
 
    void add_edge(int from, int to, int cap){
        G[from].push_back((edge){to, cap, (int)G[to].size()});//from -> to
        G[to].push_back((edge){from, 0, (int)G[from].size() - 1});//to -> from
    }
    //増加パスを探す
    int dfs(int v, int t, int f){
        if(v == t) return f;
        used[v] = true;
        for (int i = 0; i < G[v].size(); ++i){
            edge &e = G[v][i];
            if(!used[e.to] && e.cap > 0){
                int d = dfs(e.to, t, min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    //sからtへの最大流
    int max_flow(int s, int t){
        int flow = 0;
        while(1){
            memset(used, 0, sizeof(used));
            int f = dfs(s, t, INF);
            if(f == 0) return flow;
            flow += f;
        }
    }
};

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int main(void) {
	scanf("%d %d", &H, &W);
	rep(i, H) cin >> s[i];
	int start = 2 * (H * W) + 1, goal = 2 * (H * W) + 2;
	int N = H * W;

	bool flag = false;
	rep(i, H)rep(j, W){
		if((i == 0 || i == H - 1 || j == 0 || j == W - 1) && s[i][j] == 'X')
			flag = true;
	}
	if(flag){
		printf("-1\n"); return 0;
	}

	Flow fw;
	rep(i, H)rep(j, W){
		int u = i * W + j;
		if(s[i][j] == 'X') {
			fw.add_edge(start, u, INF);
			fw.add_edge(u, u + N, INF);
		}else{
			fw.add_edge(u, u + N, 1);
		}
		if(i == 0 || i == H - 1 || j == 0 || j == W - 1){
			fw.add_edge(u + N, goal, INF);
		}
	}
	rep(i, H)rep(j, W)rep(k, 4){
		int y = i, x = j;
		int ny = y + dy[k], nx = x + dx[k];
		if(!(0 <= ny && ny < H && 0 <= nx && nx < W)) continue;
		int u = y * W + x, v = ny * W + nx;
		fw.add_edge(N + u, v, INF);
	}

	int ret = fw.max_flow(start, goal);
	printf("%d\n", ret);
	return 0;
}