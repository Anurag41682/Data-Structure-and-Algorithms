#include <bits/stdc++.h>
#ifndef LOCAL
#define dbg(x...)
#endif
#define int long long
#define endl '\n'
using namespace std;
// this function help to add value num to index idx 
void update(int num, int idx, vector<int> &BIT) {  // log(n) time 
    int n = BIT.size();
    while (idx <= n) {
        BIT[idx] += num;
        idx += idx & (-idx);  //(-idx) = Two's complement of idx, eg. 14 = 1110 therefore -14 = 0010
                              // it can be find also by using (~idx + 1) as two's complement is one's complement + 1. 
    }
}
// this function help to get the sum upto(inclusive) index idx 
int query(int idx, vector<int> &BIT) { // log(n) time
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
