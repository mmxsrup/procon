#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define fr(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
const ll inf = 1e9;
const ll mod = 1e9 + 7;
 
template<int N>
class SCC {
    vector<int> G[N];
    vector<int> rG[N];
    vector<int> vs;
    bool used[N];
    int cmp[N];
    int V;
 
    void dfs(int v) {
        used[v] = true;
        for (int i = 0; i < G[v].size(); i++) {
            if (!used[G[v][i]]) dfs(G[v][i]);
        }
        vs.push_back(v);
    }
 
    void rdfs(int v, int k) {
        used[v] = true;
        scc[k].push_back(v);
        cmp[v] = k;
        for (int i = 0; i < rG[v].size(); i++) {
            if (!used[rG[v][i]]) rdfs(rG[v][i], k);
        }
    }
public:
    vector<vector<int> > scc;
    vector<vector<int> > SG;
 
    void add(int u, int v) {
        G[u].push_back(v);
        rG[v].push_back(u);
    }
 
    void init(int V) {
        this->V = V;
    }
 
    int build() {
        memset(used, 0, sizeof(used));
        vs.clear();
        for (int v = 0; v < V; v++) {
            if (!used[v]) dfs(v);
        }
        memset(used, 0, sizeof(used));
        int k = 0;
        for (int i = vs.size() - 1; i >= 0; i--) {
            if (!used[vs[i]]) {
                scc.push_back(vector<int>());
                rdfs(vs[i], k++);
            }
        }
        SG.resize(scc.size());
        for (int v = 0; v < V; v++) {
            for (int i = 0; i < G[v].size(); i++) {
                if (cmp[v] < cmp[G[v][i]]) {
                    SG[cmp[v]].push_back(cmp[G[v][i]]);
                }
            }
        }
        for (int i = 0; i < SG.size(); i++) {
            sort(SG[i].begin(), SG[i].end());
            SG[i].erase(unique(SG[i].begin(), SG[i].end()), SG[i].end());
        }
        return k;
    }
 
    int size() {
        return scc.size();
    }
 
    vector<int> &operator [](int k) {
        return scc[k];
    }
};
 
SCC<400> scc;
string strs[400][400];
int slen[400];
 
vector<int> G[300];
string dp[400][400];
int n, m, K;
char c[300];
 
void disp() {
    rep (i, scc.size()) {
        rep (j, K + 1) {
            if (dp[i][j] == "") cout << "emp ";
            else cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
 
string solve() {
    rep (i, scc.size()) {
        rep (j, K + 1) {
            dp[i][j] = "~";
        }
        dp[i][0] = "";
    }
 
    rep (i, scc.size()) {
        rep (j, slen[i] + 1) {
            dp[i][j] = min(dp[i][j], strs[i][j]);
        }
    }
 
    // O(MK)
    rep (i, scc.size()) {
        printf("i %d\n", i);
        rep (j, scc.SG[i].size()) {
            int to = scc.SG[i][j];
            printf("to %d\n", to);
            rep (k, K + 1) {
                rep (h, slen[to] + 1) {
                    if (k + h > K) break;
                    dp[to][k + h] = min(dp[to][k + h], dp[i][k] + strs[to][h]);
                }
            }
        }
    }
 
    string res = "~";
 
    rep (i, scc.size()) {
        res = min(res, dp[i][K]);        
    }
 
    return res;
}
 
int main() {
    cin >> n >> m >> K;
 
    scc.init(n);
    
    rep (i, n) {
        string t;
        cin >> t;
        c[i] = t[0];
    }
 
    rep (i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
 
        scc.add(u, v);
    }
 
    scc.build();
 
    rep (i, scc.size()) {
        string s;
 
        rep (j, scc[i].size()) {
            s += c[scc[i][j]];
        }
 
        sort(s.begin(), s.end());
        strs[i][s.length()] = s;
        slen[i] = s.length();
    }
 
    rep (i, scc.size()) {
        rep (j, slen[i]) {
            strs[i][j] = strs[i][slen[i]].substr(0, j);
        }
    }
 
    string ans = solve();
 
    if (ans == "~") {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}