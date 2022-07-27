//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) 
    {
        sort(arr,arr+n);
        int minn,maxx;
        int ans=arr[n-1]-arr[0];
        for(int i=1;i<n;i++)
        {
            int templ=arr[i-1]+k;
            int tempr=arr[i]-k;
            int minn=min(arr[0]+k,tempr);
            int maxx=max(arr[n-1]-k,templ);
            ans=min(ans,maxx-minn);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
