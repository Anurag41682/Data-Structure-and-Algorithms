#include <bits/stdc++.h>
#ifndef LOCAL
#define dbg(x...)
#endif
#define int long long
#define endl '\n'
using namespace std;

void update(int num, int idx, vector<int> &BIT) {
    int n = BIT.size();
    while (idx <= n) {
        BIT[idx] += num;
        idx += idx & (-idx);
    }
}
int query(int idx, vector<int> &BIT) {
    int ans = 0;
    while (idx > 0) {
        ans += BIT[idx];
        idx -= idx & (-idx);
    }
    return ans;
}

void solve() {
    vector<int> BIT(6);
    vector<int> input(5);
    for (int i = 0; i < 5; i++) {
        cin >> input[i];
    }

    for (int i = 0; i < 5; i++) {
        update(input[i], i + 1, BIT);
    }
    for (int i = 1; i <= 5; i++) {
        cout << query(i, BIT) << " ";
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}