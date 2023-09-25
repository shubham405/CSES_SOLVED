#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
     ios_base::sync_with_stdio(0);
    cin.tie(0);
   ll n;
   cin>>n;
   vector<ll> arr(n);
   for(ll i = 0;i<n;i++)
      cin>>arr[i];
    
    sort(arr.begin(),arr.end());
    ll totalTime = 0;
    for(ll i = 0;i<n-1;i++)
    {
        totalTime+=arr[i];
    }
    if(totalTime>arr[n-1])
    {
        cout<<totalTime+arr[n-1];
    }
    else
    {
        cout<<2*arr[n-1];
    }
}