#include<bits/stdc++.h>
using namespace std;
int main()
{
    //function to return 
5 minutes ago
MaxAndMinIn_Array.cpp
Add files via upload
5 minutes ago
MaxDifferenceHeight_I.cpp
Add files via upload
5 minutes ago
ReverseTheArray.cpp
Add files via upload
5 minutes ago
cyclically_rotate_an_array_by_one.cpp
Add files via upload
5 minutes ago
intersection.cpp
Add files via upload
5 minutes ago
maxDifferenceHeight_II.cpp
Add files via upload
5 minutes ago
moving_all_negativNoin_left.cpp
Add files via upload
5 minutes ago
union.cpp
Add files via upload
5 minutes ago
zeroOneTwosort.cpp
Add files via uploadthe no. of intersection in two arrays
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;cin>>m;
    int arr2[m];
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(int i=0;i<m;i++){
        mp[arr2[i]]++;
    }
    int ans{};
    for(int i=0;i<mp.size();i++){
        if(mp[i]>=2)
            ans++;
    }
    cout<<ans;
}
