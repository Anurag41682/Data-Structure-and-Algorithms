#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int m;cin>>m;
    int arr2[m];
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    for(int i=0;i<m;i++)
    {
        mp[arr2[i]]++;
    }
    int ans{};
    for(int i=0;i<mp.size();i++)
    {
        if(mp[i]>=2)
            ans++;
    }
    cout<<ans;
}