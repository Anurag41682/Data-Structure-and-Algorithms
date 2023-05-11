//Time complextity O(alpha) approximately constant.
#include <bits/stdc++.h>
#ifndef LOCAL
#define dbg(x...)
#endif
#define endl '\n'
#define int long long
using namespace std;
int findParent(int x, vector<int>& parent) {
    // base case
    if (parent[x] == -1) return x;
    return parent[x] = findParent(parent[x], parent);
}
void unionn(int x, int y, vector<int>& parent, vector<int>& rank) {
    int p1 = findParent(x, parent);
    int p2 = findParent(y, parent);

    if (p1 != p2) {
        if (rank[p1] < rank[p2]) {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        } else {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }
    }
}
void solve() {
    int n;
    cin >> n;
    vector<int> rank(n + 1, 1), parent(n + 1, -1);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        unionn(x, y, parent, rank);
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
