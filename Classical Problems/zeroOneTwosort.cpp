#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int zeroes=0,ones=0,twos=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
                zeroes++;
            else if(a[i]==1)
                ones++;
            else
                twos++;
        }
        int i=0;
        while(zeroes--)
        {
            a[i]=0;i++;
        }
        while(ones--)
        {
            a[i]=1;i++;
        }
        while(twos--)
        {
            a[i]=2;i++;
        }
    }
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends