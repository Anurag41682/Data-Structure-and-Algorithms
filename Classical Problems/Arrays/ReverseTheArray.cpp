#include<bits/stdc++.h>//O(n)-reverse function
using namespace std;
int main()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    reverse(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
#include<bits/stdc++.h>//O(n)-using stack
using namespace std;
int main()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        st.push(arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}
#include<bits/stdc++.h>//O(n)-using recursion
using namespace std;
void reversearr(int arr[],int start,int end)
{
    if(start<=end)
    {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        reversearr(arr,start+1,end-1);
    }        
}
int main()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];        
    }
    reversearr(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}