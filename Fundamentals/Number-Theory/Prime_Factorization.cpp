// Time Complexity O(sqrt(n)*log(n))
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void primeFactors(int n, vector<int> &ans) {
    while (n % 2 == 0) {
        ans.push_back(2);
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            ans.push_back(i);
            n = n / i;
        }
    }
    if (n > 1) ans.push_back(n);  // Condition for Prime Numbers
}
void solve() {
    vector<int> ans;
    primeFactors(100, ans);  // This function will give PrimeFactorization of 100 in vector ans
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
