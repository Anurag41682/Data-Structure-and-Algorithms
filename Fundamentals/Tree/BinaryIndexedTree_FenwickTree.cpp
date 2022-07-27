#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void update(int i, int add, vector<int> &BIT) {
    while (i < BIT.size()) {
        BIT[i] += add;
        i += i & (-i);
    }
}
int sum(int i, vector<int> &BIT) {
    int x = 0;
    while (i > 0) {
        x += BIT[i];
        i -= i & (-i);
    }
    return x;
}
void solve() {
    vector<int> v = {2, 4, 5, 7, 4, 6};
    vector<int> pref(v.size() + 1);
    for (int i = 0; i < v.size(); i++) {
        pref[i + 1] = v[i] + pref[i];
    }
    vector<int> BIT(v.size() + 1);  // binary indexed tree fenwick tree
    for (int i = 1; i <= v.size(); i++) {
        update(i, v[i - 1], BIT);  // update i by add;
        // sum(i)//find sum from 0 to i;
    }
    // update(4, 3, BIT);
    for (int i = 1; i <= v.size(); i++) {
        cout << sum(i, BIT) << " ";
    }
    // for (auto it : BIT) {
    //     cout << it << endl;
    // }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
