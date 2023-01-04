


/*




Start = s ,End = e and Mid = m

s = 0,e = 7, m=(s+e)/2 = 3; 


first step is to divide array into equal parts recursively untill s < e

         s     m       e
array = {8,7,6,5,4,3,2,1}

         s m   e                 s m   e
array = {8,7,6,5}         array={4,3,2,1}

         s m     e              s m     e               s m    e               s m     e 
array = {8   ,   7}    array = {6   ,   5}     array = {4   ,   3}    array = {2   ,   1}


second step is to merge each parts in sorted manner 

array = {7, 8}    array= {5, 6}    array = {3, 4}    array = {1, 2}     - n steps

array = {6,5,7,8}     array = {1,2,3,4}                                 - n steps

array = {1,2,3,4,5,6,7,8}                                               - n steps

                                                                Total   = n*log(n) since log(n) is the time needed to divide array of size(n);




*/

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
