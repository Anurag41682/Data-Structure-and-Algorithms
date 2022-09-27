#include <bits/stdc++.h>
#ifndef LOCAL
#define dbg(x...)
#endif
#define endl '\n'
#define int long long
using namespace std;
void merge(int start, int mid, int end, vector<int>& v) {
    int i = start;
    int j = mid + 1;
    vector<int> temp;
    while (i <= mid && j <= end) {
        if (v[i] < v[j]) {
            temp.push_back(v[i++]);
        } else {
            temp.push_back(v[j++]);
        }
    }
    while (i <= mid) {
        temp.push_back(v[i++]);
    }
    while (j <= end) {
        temp.push_back(v[j++]);
    }
    int k = 0;
    for (int x = start; x <= end; x++) {
        v[x] = temp[k++];
    }
}
void mergeSort(int start, int end, vector<int>& v) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(start, mid, v);
        mergeSort(mid + 1, end, v);
        merge(start, mid, end, v);
    }
}
void solve() {
    vector<int> v = {8, 0, 1, 9, 2, 3, 7};
    mergeSort(0, v.size() - 1, v);
    for (auto it : v) cout << it << " ";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    while (T--) solve();
}
