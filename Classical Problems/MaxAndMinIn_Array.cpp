#include<bits/stdc++.h>//O(n)-Iterative way
using namespace std;
struct pairr
{
    int min;
    int max;
};
pairr getMinMax(int arr[],int n)
{
    pairr ans;
    if(n==1)
    {
        ans.max=arr[0];
        ans.min=arr[0];
    }
    else
    {
        if(arr[0]>arr[1])
        {
            ans.max=arr[0];
            ans.min=arr[1];
        }
        else
        {
            ans.max=arr[1];
            ans.min=arr[0];
        }
    }    
    for(int i=2;i<n;i++)
    {
        if(arr[i]>ans.max)
            ans.max=arr[i];
        if(arr[i]<ans.min)
            ans.min=arr[i];
    }
    return ans;
}
int main()
{
    int arr[]={10,15,25,3,-8,12};
    int n=sizeof(arr)/sizeof(arr[0]);
    pairr ans=getMinMax(arr,n);
    cout<<ans.max<<"<-Max"<<endl;
    cout<<ans.min<<"<-Min"<<endl;    
}

#include<bits/stdc++.h>//O(n)-using recursion
using namespace std;
struct pairr
{
    int min;
    int max;
};
pairr getminmax(int arr[],int start,int end)
{
    pairr ans,l,r;
    int mid;
    if(start==end)
    {
        ans.min=arr[start];
        ans.max=arr[start];
        return ans;
    }
    else if(end==start+1)
    {
        if(arr[end]>arr[start])
        {
            ans.max=arr[end];
            ans.min=arr[start];
        }
        else
        {
            ans.max=arr[start];
            ans.min=arr[end];
        }
        return ans;
    }
    else
    {
        mid=start+(end-start)/2;
        l=getminmax(arr,start,mid);
        r=getminmax(arr,mid+1,end);
        if(l.min<r.min)
            ans.min=l.min;
        else
            ans.min=r.min;
        if(l.max>r.max)
            ans.max=l.max;
        else
            ans.max=r.max;
    }
    return ans;
}
int main()
{
    int arr[]={12,14,15,17,02,11};
    int n=sizeof(arr)/sizeof(arr[0]);
    pairr ans =getminmax(arr,0,n-1);
    cout<<ans.min<<"min"<<endl;
    cout<<ans.max<<"max"<<endl;
}