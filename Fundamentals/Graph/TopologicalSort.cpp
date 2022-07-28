// If there is edge between u->v then u must come before v in topologicalSort order.
// It is only applied to Directed Acyclic Graph
#include <bits/stdc++.h>
#ifndef LOCAL
#define dbg(x...)
#endif
#define endl '\n'
#define int long long
using namespace std;
vector<vector<int>> adj;
vector<bool> vis;
stack<int> st;
void dfs(int node) {
    if (!vis[node]) {
        vis[node] = true;
        for (auto it : adj[node]) {
            dfs(it);
        }
        st.push(node);
    }
}
vector<int> topologicalSort(int n) {
    for (int i = 0; i < n; i++) {
        dfs(i);
    }
    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
void solve() {
    int n, m;
    cin >> n >> m;  // vertex and edge
    adj.resize(n + 1);
    vis.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    auto x = topologicalSort(n);
    dbg(x);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
