#include<bits/stdc++.h>//first way
using namespace std;
int partition(int arr[],int l,int r)
{
    int  pivot=r,i=l-1;
    for(int j=l;j<r;j++)
    {
        if(arr[j]<arr[pivot])
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
void quicksort(int arr[],int l, int r)
{
    if(l<r)
    {
        int pi=partition(arr,l,r);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,r);
    }
    
}
int main ()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
#include<bits/stdc++.h>//second way
using namespace std;
int main()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            swap(arr[i],arr[count]);
            count++;
        }
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}