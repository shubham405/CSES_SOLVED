#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    vector<ll> arr;
    for(ll i=0;i<n;i++)
    {
        ll x; 
        cin>>x;
        arr.push_back(x);
    }
    ll ans  = 0;
    for(ll i = 1;i<n;i++)
    {
        if(arr[i]<arr[i-1])
        {
            ans+=arr[i-1]-arr[i];
            arr[i]=arr[i-1];
        }
    }
    cout<<ans<<endl;
}