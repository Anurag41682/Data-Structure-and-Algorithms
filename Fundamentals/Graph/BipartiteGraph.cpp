//Graph Which can be coloured using only two colors having no two adjacent vertex same colors are called Bipartite Graph.
#include <bits/stdc++.h>
#ifndef LOCAL
#define dbg(x...)
#endif
#define endl '\n'
#define int long long
using namespace std;
vector<vector<int>> adj;
vector<int> color;
bool checkBiapartite(int node, int clr) {
    if (color[node] == -1) {
        color[node] = clr;
        for (auto it : adj[node]) {
            if (color[it] == clr) return false;
            checkBiapartite(it, !clr);
        }
    }
    return true;
}
void solve() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    color.resize(n + 1, -1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << (checkBiapartite(1, 0) ? "Bipartite" : "Non-Bipartite")
         << endl;  // when having only one component otherwise we need to check
                   // each node using for loop for each node
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
