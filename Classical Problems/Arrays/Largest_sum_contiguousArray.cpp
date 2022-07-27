#include<bits/stdc++.h>
using namespace std;
class Solution//using kadan's algo-O(n)
{
    public:
    long long maxSubarraySum(int arr[], int n)
    {
        long long maxx=INT_MIN;
        long long current_sum=0;
        for(int i=0;i<n;i++)
        {
            current_sum+=arr[i];
            maxx=max(current_sum,maxx);
            if(current_sum<0)
            {
                current_sum=0;
            }
        }
        return maxx;        
    }
};
class Solution2//cumulative sum approach-O(n^2)
{
    public:
    long long maxSubarraySum(int arr[], int n)
    {
        int cumarr[n];
        cumarr[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            cumarr[i]=arr[i]+cumarr[i-1];
        }
        long long  maxx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            long long temp=cumarr[i];
            for(int j=0;j<=i;j++)
            {
                maxx=max(temp,maxx);
                temp-=arr[j];
            }
        }
        return maxx;
    }
};
class Solution3//using brute approach-O(n^3)
{
    public:
    long long maxSubarraySum(int arr[],int n)
    {
        long long maxx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                long long sum=0;
                for(int k=i;k<=j;k++)
                {
                    sum+=arr[k];
                    maxx=max(sum,maxx);
                }
            }
        }
        return maxx;
    }
};
int main()
{
    int t,n;    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {        
        cin>>n; //input size of array        
        int a[n];        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array            
        Solution3 ob;        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
