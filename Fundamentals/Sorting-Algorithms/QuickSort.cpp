// Time complextiy O(n^2)
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
//this function move the pivot element at original position in sorted arrray and also move all the elements which are
//smaller than or equal to it in front of it and return its(pivot) postion.
int partition(int arr[], int start, int end) {    
    int pivot = arr[end];
    int i = start;
    for (int j = start; j < end; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[end]);
    return i;
}
void quicksort(int arr[], int start, int end) {
    if (start < end) {
        int idx = partition(arr, start, end);
        quicksort(arr, start, idx - 1);
        quicksort(arr, idx + 1, end);
    }
}
void solve() {
    int arr[] = {2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << n << endl;
    quicksort(arr, 0, n - 1);
    for (auto it : arr) {
        cout << it << " ";
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
