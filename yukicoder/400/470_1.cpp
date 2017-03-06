#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

class StronglyConnectedComponents {
private:
    const vector<vector<int>> &graph;
    vector<vector<int>> reversedGraph;
    vector<vector<int>> compressedGraph;
    vector<int> componentID;
    vector<int> postOrder;
    vector<bool> visited;
    stack<int> adjacent;

public:
    StronglyConnectedComponents(const vector<vector<int>> &graph) :
        graph(graph),
        reversedGraph(graph.size()),
        componentID(graph.size(), -1),
        visited(graph.size()) {

        rep(i, graph.size()){
            for(auto t : graph[i]){
                printf("%d->%d\n", i, t);
            }
        }
        for (int i = 0; i < graph.size(); i++) {
            for (int j : graph[i]) {
                reversedGraph[j].push_back(i);
            }
        }
        for (int i = 0; i < graph.size(); i++) {
            dfs(i);
        }
        reverse(postOrder.begin(), postOrder.end());
        for (int i : postOrder) {
            if (componentID[i] == -1) {
                dfs2(i);
                while (!adjacent.empty()) {
                    visited[adjacent.top()] = true;
                    adjacent.pop();
                }
                compressedGraph.emplace_back(vector<int>());
            }
        }
    }

    vector<vector<int>> &getCompressedGraph() {
        return compressedGraph;
    }

    int operator[](int u) {
        return componentID[u];
    }

private:
    void dfs(int u) {
        if (visited[u]) {
            return;
        }
        visited[u] = true;
        for (int v : graph[u]) {
            dfs(v);
        }
        postOrder.push_back(u);
    }

    void dfs2(int u) {
        componentID[u] = compressedGraph.size();
        for (int v : reversedGraph[u]) {
            if (componentID[v] == -1) {
                dfs2(v);
            } else if (componentID[v] != componentID[u] && visited[componentID[v]]) {
                compressedGraph[componentID[v]].push_back(componentID[u]);
                visited[componentID[v]] = false;
                adjacent.push(componentID[v]);
            }
        }
    }
};

class TwoSatisfiability  {
private:
    vector<vector<int>> g;
    vector<bool> var;
    bool satisfiable;

public:
    TwoSatisfiability(int n) : g(n * 2), var(n) {}

    // i or j
    void add(int i, int ii, int j, int jj) {
        printf("i %d j %d\n", i, j);
        g[i * 2 + 1 - ii].push_back(j * 2 + jj);
        g[j * 2 + 1 - jj].push_back(i * 2 + ii);
    }

    bool isSatisfiable() {
        return satisfiable;
    }

    void build() {
        StronglyConnectedComponents scc(g);

        satisfiable = true;
        for (int i = 0; i < var.size(); i++) {
            if (scc[i * 2] == scc[i * 2 + 1]) {
                satisfiable = false;
            }
            var[i] = scc[i * 2] < scc[i * 2 + 1];
        }
    }

    bool operator[](int k) {
        return var[k];
    }
};

int main() {
    int n;
    cin >> n;

    if (n >= 3000) {
        puts("Impossible");
        return 0;
    }

    vector<string> s(n);
    TwoSatisfiability sat(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            string a = s[i];
            string b = s[j];
            // printf("%d %d\n", i, j);
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

    sat.build();

    if (!sat.isSatisfiable()) {
        puts("Impossible");
    } else {
        for (int i = 0; i < n; i++) {
            if (sat[i]) {
                cout << s[i].substr(0, 2) << " " << s[i].substr(2, 1) << endl;
            } else {
                cout << s[i].substr(0, 1) << " " << s[i].substr(1, 2) << endl;
            }
        }
    }
}
