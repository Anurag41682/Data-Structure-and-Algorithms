#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void Divisors(int n, vector<int> &ans) {
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i) {
                ans.push_back(i);
            } else {
                ans.push_back(i);
                ans.push_back(n / i);
            }
        }
    }
}
void solve() {
    vector<int> ans;
    Divisors(6241, ans);
    cout << (int)ans.size() << endl;
    for (auto it : ans) {
        cout << it << " ";
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    while (T--) solve();
}
